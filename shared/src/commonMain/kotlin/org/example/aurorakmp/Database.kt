package org.example.aurorakmp

import app.cash.sqldelight.db.SqlDriver
import com.example.aurorakmp.cache.VisitDatabase
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.IO
import kotlinx.coroutines.withContext

expect class DatabaseDriverFactory {
    fun createDriver(): SqlDriver
}

class Database(driverFactory: DatabaseDriverFactory) {
    private val db = VisitDatabase(driverFactory.createDriver())
    private val queries = db.appDatabaseQueries

    suspend fun recordCurrentVisit() = withContext(Dispatchers.IO) {
        queries.transaction {
            queries.insertCurrentVisit()
        }
    }

    suspend fun getLastVisits(): List<String> = withContext(Dispatchers.IO) {
        queries.getLastVisits().executeAsList().map { it.datetime }
    }
}
