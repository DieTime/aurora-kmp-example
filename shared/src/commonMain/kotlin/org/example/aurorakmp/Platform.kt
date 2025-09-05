package org.example.aurorakmp

interface Platform {
    val name: String
}

expect fun getPlatform(): Platform