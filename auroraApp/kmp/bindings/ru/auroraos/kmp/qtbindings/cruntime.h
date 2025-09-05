/**
 * SPDX-FileCopyrightText: Copyright 2025 Open Mobile Platform LLC <community@omp.ru>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef RU_AURORA_KMP_QT_BINDINGS_C_RUNTIME_H
#define RU_AURORA_KMP_QT_BINDINGS_C_RUNTIME_H

#ifdef __cplusplus
extern "C" {
#endif

struct CCancellableCoroutine;

typedef void (*COnResultCallback)(void *cContext, void *result);
typedef void (*COnStringCallback)(void *cContext, char *message);
typedef COnStringCallback COnErrorCallback;
typedef COnStringCallback COnCancelledCallback;
typedef void (*CCancelCoroutine)(struct CCancellableCoroutine *coroutine);

typedef struct CCancellableCoroutine
{
    void *coroutine;
    CCancelCoroutine cancel;
    void (*free)(struct CCancellableCoroutine *thiz);
} CCancellableCoroutine;

typedef struct KotlinCoroutineLauncher
{
    void *kotlinContext;
    CCancellableCoroutine *(*coroutineLauncherFunc)(void *cContext,
                                                    void *kotlinContext,
                                                    COnResultCallback onResult,
                                                    COnErrorCallback onError,
                                                    COnCancelledCallback onCancelled);
    void (*free)(struct KotlinCoroutineLauncher *thiz);
} KotlinCoroutineLauncher;

#ifdef __cplusplus
}
#endif

#endif /* RU_AURORA_KMP_QT_BINDINGS_C_RUNTIME_H */
