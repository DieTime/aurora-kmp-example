/**
 * SPDX-FileCopyrightText: Copyright 2025 Open Mobile Platform LLC <community@omp.ru>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef RU_AURORA_KMP_QT_BINDINGS_CALLBACK_CONTEXT_HPP
#define RU_AURORA_KMP_QT_BINDINGS_CALLBACK_CONTEXT_HPP

#include <functional>

extern "C" {
void onResult(void *context, void *result);
void onError(void *context, char *errorMessage);
void onCancelled(void *context, char *errorMessage);
}

namespace Aurora {
namespace Kmp {
namespace QtBindings {

using OnResultCallback = std::function<void(void * /* Result */)>;
using OnErrorCallback = std::function<void(char * /* String */)>;
using OnCancelledCallback = std::function<void(char * /* String */)>;

struct CallbackContext
{
    OnResultCallback onResultCallback;
    OnErrorCallback onErrorCallback;
    OnCancelledCallback onCancelledCallback;
};

} /* namespace Aurora */
} /* namespace Kmp */
} /* namespace QtBindings */

#endif /* RU_AURORA_KMP_QT_BINDINGS_CALLBACK_CONTEXT_HPP */
