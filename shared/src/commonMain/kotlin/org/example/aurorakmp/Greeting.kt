package org.example.aurorakmp

import ru.auroraos.kmp.qtbindings.QtExport

@QtExport
class Greeting {
    private val platform = getPlatform()

    fun greet(): String {
        return "Hello, ${platform.name}!"
    }
}