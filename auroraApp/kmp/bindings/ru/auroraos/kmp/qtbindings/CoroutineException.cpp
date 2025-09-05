/**
 * SPDX-FileCopyrightText: Copyright 2025 Open Mobile Platform LLC <community@omp.ru>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "CoroutineException.hpp"

namespace Aurora {
namespace Kmp {
namespace QtBindings {

CoroutineException::CoroutineException(const QString &message)
    : m_message(message)
{}

CoroutineException::CoroutineException(const CoroutineException &other)
    : QException(other)
    , m_message(other.m_message)
{}

void CoroutineException::raise() const
{
    throw *this;
}

CoroutineException *CoroutineException::clone() const
{
    return new CoroutineException(*this);
}

QString CoroutineException::message() const
{
    return m_message;
}

} /* namespace Aurora */
} /* namespace Kmp */
} /* namespace QtBindings */
