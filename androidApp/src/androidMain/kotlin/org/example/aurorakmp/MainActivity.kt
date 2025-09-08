package org.example.aurorakmp

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import kotlinx.coroutines.runBlocking

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        enableEdgeToEdge()
        super.onCreate(savedInstanceState)

        val db = Database(DatabaseDriverFactory(applicationContext))
        runBlocking { db.recordCurrentVisit() }

        setContent {
            App(db)
        }
    }
}
