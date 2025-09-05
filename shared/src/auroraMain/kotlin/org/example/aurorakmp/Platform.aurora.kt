package org.example.aurorakmp

class AuroraPlatform: Platform {
    override val name: String = "Aurora"
}

actual fun getPlatform(): Platform = AuroraPlatform()
