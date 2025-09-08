package org.example.aurorakmp

import app.cash.sqldelight.db.SqlDriver
import app.cash.sqldelight.driver.native.NativeSqliteDriver
import ru.auroraos.kmp.qtbindings.QtExport
import com.example.aurorakmp.cache.VisitDatabase

@QtExport
actual class DatabaseDriverFactory {
    actual fun createDriver(): SqlDriver {
        return NativeSqliteDriver(VisitDatabase.Schema, ":memory:")
    }
}