package org.example.aurorakmp

import android.util.Log
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.safeContentPadding
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Text
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import org.jetbrains.compose.ui.tooling.preview.Preview

@Composable
@Preview
fun App() {
    MaterialTheme {
        Column(
            modifier = Modifier.safeContentPadding().fillMaxSize(),
            horizontalAlignment = Alignment.CenterHorizontally,
            verticalArrangement = Arrangement.Center
        ) {
            val greeting = remember { Greeting().greet() }
            var revision by remember { mutableStateOf("...") }

            LaunchedEffect(Unit) {
                try {
                    revision = GithubRepository().revision().take(8)
                } catch (e: Exception) {
                    Log.e("GithubRepository", "Failed to query revision",e)
                    revision = "unknown"
                }
            }

            Text(greeting)
            Text("Revision: $revision")
        }
    }
}