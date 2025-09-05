/**
 * SPDX-FileCopyrightText: Copyright 2025 Open Mobile Platform LLC <community@omp.ru>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef RU_AURORA_KMP_QT_BINDINGS_COROUTINE_LAUNCHER_HPP
#define RU_AURORA_KMP_QT_BINDINGS_COROUTINE_LAUNCHER_HPP

#include "CallbackContext.hpp"
#include "cruntime.h"

namespace Aurora {
namespace Kmp {
namespace QtBindings {

struct CoroutineLauncher
{
    CoroutineLauncher(KotlinCoroutineLauncher *launcher);
    CoroutineLauncher(const CoroutineLauncher &other) = delete;
    CoroutineLauncher(CoroutineLauncher &&other);
    virtual ~CoroutineLauncher();

    CoroutineLauncher &operator=(const CoroutineLauncher &other) = delete;
    CoroutineLauncher &operator=(CoroutineLauncher &&other);

    struct CancelableCoroutine
    {
    public:
        CancelableCoroutine(CCancellableCoroutine *coroutine);
        CancelableCoroutine(const CancelableCoroutine &other) = delete;
        CancelableCoroutine(CancelableCoroutine &&other);
        virtual ~CancelableCoroutine();

        CancelableCoroutine &operator=(const CancelableCoroutine &other) = delete;
        CancelableCoroutine &operator=(CancelableCoroutine &&other);
        void cancel();

    private:
        CCancellableCoroutine *d_ptr;
    };

    CancelableCoroutine launch(CallbackContext *context,
                               COnResultCallback onResult,
                               COnErrorCallback onError,
                               COnCancelledCallback onCancelled);

private:
    KotlinCoroutineLauncher *d_ptr;
};

} /* namespace Aurora */
} /* namespace Kmp */
} /* namespace QtBindings */

#endif /* RU_AURORA_KMP_QT_BINDINGS_COROUTINE_LAUNCHER_HPP */
