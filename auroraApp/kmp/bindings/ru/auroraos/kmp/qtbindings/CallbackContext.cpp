/**
 * SPDX-FileCopyrightText: Copyright 2025 Open Mobile Platform LLC <community@omp.ru>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "CallbackContext.hpp"

using CallbackContext = Aurora::Kmp::QtBindings::CallbackContext;
using OnResultCallback = Aurora::Kmp::QtBindings::OnResultCallback;
using OnErrorCallback = Aurora::Kmp::QtBindings::OnErrorCallback;
using OnCancelledCallback = Aurora::Kmp::QtBindings::OnCancelledCallback;

extern "C" {
void onResult(void *context, void *result)
{
    auto callback = static_cast<CallbackContext *>(context)->onResultCallback;
    callback(result);
}

void onError(void *context, char *errorMessage)
{
    auto callback = static_cast<CallbackContext *>(context)->onErrorCallback;
    callback(errorMessage);
}

void onCancelled(void *context, char *errorMessage)
{
    auto callback = static_cast<CallbackContext *>(context)->onCancelledCallback;
    callback(errorMessage);
}
}
