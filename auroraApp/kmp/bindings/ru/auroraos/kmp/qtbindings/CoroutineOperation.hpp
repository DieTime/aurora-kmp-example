/**
 * SPDX-FileCopyrightText: Copyright 2025 Open Mobile Platform LLC <community@omp.ru>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef RU_AURORA_KMP_QT_BINDINGS_COROUTINE_OPERATION_HPP
#define RU_AURORA_KMP_QT_BINDINGS_COROUTINE_OPERATION_HPP

#include <functional>
#include <optional>

#include <QFuture>
#include <QFutureWatcher>

#include "CallbackContext.hpp"
#include "CoroutineException.hpp"
#include "CoroutineLauncher.hpp"

namespace Aurora {
namespace Kmp {
namespace QtBindings {

template<typename T>
using ResultTransformer = std::function<T(void *)>;

template<typename T>
std::enable_if_t<!std::is_void_v<T>, QFuture<T>> coroutine(CoroutineLauncher launcher,
                                                           const ResultTransformer<T> &transformer);

template<typename T>
std::enable_if_t<std::is_void_v<T>, QFuture<T>> coroutine(CoroutineLauncher launcher);

template<typename T>
class CoroutineOperation
{
public:
    virtual ~CoroutineOperation() = default;

private:
    friend QFuture<T> coroutine<T>(CoroutineLauncher, const ResultTransformer<T> &);

    CoroutineOperation(CoroutineLauncher launcher)
        : m_launcher(std::move(launcher))
        , m_callbackContext{nullptr,
                            [this](char *message) { finishedWithError(QString::fromUtf8(message)); },
                            // TODO: Do we need to call m_futureInterface.reportCancelled()?
                            [](char *) {}}
    {
        auto watcher = new QFutureWatcher<T>();
        watcher->setFuture(future());

        QObject::connect(watcher, &QFutureWatcher<T>::canceled, [=, this]() {
            if (m_cancellableCoroutine) {
                m_cancellableCoroutine->cancel();
                m_cancellableCoroutine.reset();
            }
        });
        QObject::connect(watcher, &QFutureWatcher<T>::finished, [watcher]() {
            watcher->deleteLater();
        });
    }

    QFuture<T> launch(const ResultTransformer<T> &transformer)
    {
        m_callbackContext.onResultCallback = [this, transformer](void *result) {
            auto transformedResult = transformer(result);
            finishedWithResult(&transformedResult);
        };

        m_futureInterface.reportStarted();
        m_cancellableCoroutine = m_launcher.launch(&m_callbackContext,
                                                   &onResult,
                                                   &onError,
                                                   &onCancelled);
        return future();
    }

    void finishedWithResult(const T *result)
    {
        // If Qfuture has been cancelled, reportFinished will do nothing
        m_futureInterface.reportFinished(result);
    }

    void finishedWithError(const QString &error)
    {
        // If Qfuture has been cancelled, reportException, reportFinished will do nothing
        m_futureInterface.reportException(CoroutineException(error));
        m_futureInterface.reportFinished();
    }

    QFuture<T> future()
    {
        return m_futureInterface.future();
    }

    CoroutineLauncher m_launcher;
    std::optional<CoroutineLauncher::CancelableCoroutine> m_cancellableCoroutine;
    CallbackContext m_callbackContext;
    // We use the undocumented (but not explicitly marked as private) QFutureInterface class
    // because that's the only way to manipulate a QFuture's status
    QFutureInterface<T> m_futureInterface;
};

template<>
class CoroutineOperation<void>
{
public:
    virtual ~CoroutineOperation() = default;

private:
    friend QFuture<void> coroutine<void>(CoroutineLauncher launcher);

    CoroutineOperation(CoroutineLauncher launcher)
        : m_launcher(std::move(launcher))
        , m_callbackContext{nullptr,
                            [this](char *message) { finishedWithError(QString::fromUtf8(message)); },
                            // TODO: Do we need to call m_futureInterface.reportCancelled()?
                            [](char *) {}}
    {
        auto watcher = new QFutureWatcher<void>();
        watcher->setFuture(future());

        QObject::connect(watcher, &QFutureWatcher<void>::canceled, [=]() {
            if (m_cancellableCoroutine) {
                m_cancellableCoroutine->cancel();
                m_cancellableCoroutine.reset();
            }
        });
        QObject::connect(watcher, &QFutureWatcher<void>::finished, [=]() {
            watcher->deleteLater();
        });
    }

    QFuture<void> launch()
    {
        m_callbackContext.onResultCallback = [this](void *) { finishedWithResult(); };
        m_futureInterface.reportStarted();
        m_cancellableCoroutine = m_launcher.launch(&m_callbackContext,
                                                   &onResult,
                                                   &onError,
                                                   &onCancelled);
        return future();
    }

    void finishedWithResult()
    {
        // If Qfuture has been cancelled, reportFinished will do nothing
        m_futureInterface.reportFinished();
    }

    void finishedWithError(const QString &error)
    {
        // If Qfuture has been cancelled, reportException, reportFinished will do nothing
        m_futureInterface.reportException(CoroutineException(error));
        m_futureInterface.reportFinished();
    }

    QFuture<void> future()
    {
        return m_futureInterface.future();
    }

    CoroutineLauncher m_launcher;
    std::optional<CoroutineLauncher::CancelableCoroutine> m_cancellableCoroutine;
    CallbackContext m_callbackContext;
    // We use the undocumented (but not explicitly marked as private) QFutureInterface class
    // because that's the only way to manipulate a QFuture's status
    QFutureInterface<void> m_futureInterface;
};

template<typename T>
std::enable_if_t<!std::is_void_v<T>, QFuture<T>> coroutine(CoroutineLauncher launcher,
                                                           const ResultTransformer<T> &transformer)
{
    auto op = new CoroutineOperation<T>(std::move(launcher));

    auto watcher = new QFutureWatcher<T>();
    watcher->setFuture(op->future());
    QObject::connect(watcher, &QFutureWatcher<T>::finished, [=]() {
        watcher->deleteLater();
        delete op;
    });

    return op->launch(transformer);
}

template<typename T>
std::enable_if_t<std::is_void_v<T>, QFuture<T>> coroutine(CoroutineLauncher launcher)
{
    auto op = new CoroutineOperation<T>(std::move(launcher));
    auto watcher = new QFutureWatcher<T>();
    watcher->setFuture(op->future());
    QObject::connect(watcher, &QFutureWatcher<T>::finished, [=]() {
        watcher->deleteLater();
        delete op;
    });

    return op->launch();
}

} /* namespace Aurora */
} /* namespace Kmp */
} /* namespace QtBindings */

#endif /* RU_AURORA_KMP_QT_BINDINGS_COROUTINE_OPERATION_HPP */
