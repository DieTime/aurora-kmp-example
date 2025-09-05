/**
 * SPDX-FileCopyrightText: Copyright 2025 Open Mobile Platform LLC <community@omp.ru>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "CoroutineLauncher.hpp"

namespace Aurora {
namespace Kmp {
namespace QtBindings {

CoroutineLauncher::CoroutineLauncher(KotlinCoroutineLauncher *launcher)
    : d_ptr(launcher)
{}

CoroutineLauncher::CoroutineLauncher(CoroutineLauncher &&other)
{
    d_ptr = other.d_ptr;
    other.d_ptr = nullptr;
}

CoroutineLauncher::~CoroutineLauncher()
{
    if (d_ptr) {
        d_ptr->free(d_ptr);
    }
}

CoroutineLauncher &CoroutineLauncher::operator=(CoroutineLauncher &&other)
{
    if (this != &other) {
        this->d_ptr = other.d_ptr;
        other.d_ptr = nullptr;
        return *this;
    }

    return *this;
}

CoroutineLauncher::CancelableCoroutine CoroutineLauncher::launch(CallbackContext *context,
                                                                 COnResultCallback onResult,
                                                                 COnErrorCallback onError,
                                                                 COnCancelledCallback onCancelled)
{
    return CancelableCoroutine{d_ptr->coroutineLauncherFunc((void *) context,
                                                            d_ptr->kotlinContext,
                                                            onResult,
                                                            onError,
                                                            onCancelled)};
}

CoroutineLauncher::CancelableCoroutine::CancelableCoroutine(CCancellableCoroutine *coroutine)
    : d_ptr(coroutine)
{}

CoroutineLauncher::CancelableCoroutine::CancelableCoroutine(CancelableCoroutine &&other)
{
    d_ptr = other.d_ptr;
    other.d_ptr = nullptr;
}

CoroutineLauncher::CancelableCoroutine::~CancelableCoroutine()
{
    if (d_ptr) {
        d_ptr->free(d_ptr);
    }
}

CoroutineLauncher::CancelableCoroutine &CoroutineLauncher::CancelableCoroutine::operator=(
    CancelableCoroutine &&other)
{
    if (this != &other) {
        this->d_ptr = other.d_ptr;
        other.d_ptr = nullptr;
        return *this;
    }

    return *this;
}

void CoroutineLauncher::CancelableCoroutine::cancel()
{
    d_ptr->cancel(d_ptr);
}

} /* namespace Aurora */
} /* namespace Kmp */
} /* namespace QtBindings */
