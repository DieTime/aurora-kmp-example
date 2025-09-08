package org.example.aurorakmp

import io.ktor.client.HttpClient
import io.ktor.client.HttpClientConfig
import io.ktor.client.call.body
import io.ktor.client.plugins.DefaultRequest
import io.ktor.client.plugins.contentnegotiation.ContentNegotiation
import io.ktor.client.request.get
import io.ktor.serialization.kotlinx.json.json
import kotlinx.serialization.json.Json
import ru.auroraos.kmp.qtbindings.QtExport
import kotlinx.serialization.Serializable

expect fun httpClient(config: HttpClientConfig<*>.() -> Unit = {}): HttpClient

@Serializable
private data class GithubRepositoryResponse(
    val sha: String,
)

@QtExport
class GithubRepository {
    private val httpClient = httpClient {
        install(DefaultRequest) {
            url("https://api.github.com")
        }
        install(ContentNegotiation) {
            json(Json {
                ignoreUnknownKeys = true
            })
        }
    }

    suspend fun revision(): String {
        return httpClient
            .get("/repos/dietime/aurora-kmp-example/commits/master")
            .body<GithubRepositoryResponse>()
            .sha
    }
}