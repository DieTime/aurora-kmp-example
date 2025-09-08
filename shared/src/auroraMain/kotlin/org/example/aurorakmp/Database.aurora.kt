package org.example.aurorakmp

import app.cash.sqldelight.db.SqlDriver
import app.cash.sqldelight.driver.native.NativeSqliteDriver
import app.cash.sqldelight.driver.native.wrapConnection
import co.touchlab.sqliter.DatabaseConfiguration
import ru.auroraos.kmp.qtbindings.QtExport
import com.example.aurorakmp.cache.VisitDatabase
import ru.auroraos.kmp.pathInfo.PathInfo

@QtExport
actual class DatabaseDriverFactory {
    actual fun createDriver(): SqlDriver {
        return NativeSqliteDriver(
            DatabaseConfiguration(
                name = "visit.db",
                version = 1,
                create = { connection ->
                    wrapConnection(connection) { VisitDatabase.Schema.create(it) }
                },
                upgrade = { connection, prev, next ->
                    wrapConnection(connection) { VisitDatabase.Schema.migrate(it, prev.toLong(), next.toLong()) }
                },
                extendedConfig = DatabaseConfiguration.Extended(
                    foreignKeyConstraints = true,
                    basePath = PathInfo.getAppCache()
                ),
            )
        )
    }
}