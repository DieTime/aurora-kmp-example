/**
 * SPDX-FileCopyrightText: Copyright 2025 Open Mobile Platform LLC <community@omp.ru>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef RU_AURORA_KMP_QT_BINDINGS_EXCEPTION_HPP
#define RU_AURORA_KMP_QT_BINDINGS_EXCEPTION_HPP

#include <QException>

namespace Aurora {
namespace Kmp {
namespace QtBindings {

class CoroutineException: public QException
{
public:
    explicit CoroutineException(const QString &message);
    virtual ~CoroutineException() = default;

    CoroutineException(const CoroutineException &other);

    void raise() const override;
    CoroutineException *clone() const override;
    QString message() const;

private:
    QString m_message;
};

} /* namespace Aurora */
} /* namespace Kmp */
} /* namespace QtBindings */

#endif /* RU_AURORA_KMP_QT_BINDINGS_EXCEPTION_HPP */
