package org.example.aurorakmp

import io.ktor.client.HttpClient
import io.ktor.client.HttpClientConfig
import io.ktor.client.engine.curl.Curl

actual fun httpClient(config: HttpClientConfig<*>.() -> Unit) = HttpClient(Curl) {
    config(this)
}
