import org.jetbrains.kotlin.gradle.dsl.JvmTarget

plugins {
    alias(libs.plugins.kotlinMultiplatform)
    alias(libs.plugins.androidLibrary)

    // QtBindings for Aurora OS
    id("com.google.devtools.ksp")
    id("ru.auroraos.kmp.qtbindings")
    id("org.jetbrains.kotlin.plugin.serialization")
    id("app.cash.sqldelight")
}

kotlin {
    compilerOptions {
        freeCompilerArgs.add("-Xexpect-actual-classes")
    }

    androidTarget {
        compilerOptions {
            jvmTarget.set(JvmTarget.JVM_11)
        }
    }

    linuxX64("aurora") {
        binaries {
            staticLib {
                baseName = "shared"
            }
        }
    }

    sourceSets {
        commonMain.dependencies {
            implementation("io.ktor:ktor-client-core:3.1.2")
            implementation("io.ktor:ktor-client-content-negotiation:3.1.2")
            implementation("io.ktor:ktor-serialization-kotlinx-json:3.1.2")
        }
        androidMain.dependencies {
            implementation("io.ktor:ktor-client-okhttp:3.1.2")
            implementation("app.cash.sqldelight:android-driver:2.1.0")
        }
        val auroraMain by getting {
            dependencies {
                implementation("io.ktor:ktor-client-curl:3.1.2-aurora")
            }
        }
    }
}

android {
    namespace = "org.example.aurorakmp.shared"
    compileSdk = libs.versions.android.compileSdk.get().toInt()
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_11
        targetCompatibility = JavaVersion.VERSION_11
    }
    defaultConfig {
        minSdk = libs.versions.android.minSdk.get().toInt()
    }
}

sqldelight {
    databases {
        create("VisitDatabase") {
            packageName.set("com.example.aurorakmp.cache")
        }
    }
}

qtBindings {
    libName = "shared"
}

tasks.register<Copy>("copyStaticLibAurora") {
    dependsOn("linkReleaseStaticAurora")

    from(layout.buildDirectory.dir("bin/aurora/releaseStatic"))
    into(layout.projectDirectory.dir("../auroraApp/kmp/static"))
}

tasks.register<Copy>("copyQtBindingsAurora") {
    dependsOn("kspKotlinAurora")

    from(layout.buildDirectory.dir("generated/ksp/aurora/auroraMain/resources"))
    into(layout.projectDirectory.dir("../auroraApp/kmp/bindings"))
}

tasks.register<Delete>("cleanArtifactsAurora") {
    delete(layout.projectDirectory.dir("../auroraApp/kmp"))
}

tasks.register("compileArtifactsAurora") {
    dependsOn("cleanArtifactsAurora",  "copyStaticLibAurora", "copyQtBindingsAurora")
}