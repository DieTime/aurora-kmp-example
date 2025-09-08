package org.example.aurorakmp

import android.util.Log
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.safeContentPadding
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Text
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import org.jetbrains.compose.ui.tooling.preview.Preview
import java.text.SimpleDateFormat
import java.util.Date
import java.util.Locale

@Composable
@Preview
fun App(db: Database) {
    MaterialTheme {
        Column(
            modifier = Modifier.safeContentPadding().fillMaxSize(),
            horizontalAlignment = Alignment.CenterHorizontally,
            verticalArrangement = Arrangement.Center
        ) {
            val greeting = remember { Greeting().greet() }
            var revision by remember { mutableStateOf("...") }
            var visits by remember { mutableStateOf(listOf<String>()) }

            LaunchedEffect(Unit) {
                try {
                    revision = GithubRepository().revision().take(8)
                } catch (e: Exception) {
                    Log.e("GithubRepository", "Failed to query revision",e)
                    revision = "unknown"
                }
            }

            LaunchedEffect(db) {
                visits = db.getLastVisits()
            }

            Text(greeting)
            Text("Revision: $revision")

            Text("Last visits:")
            LazyColumn {
                items(visits) { visit ->
                    Text(visit)
                }
            }
        }
    }
}