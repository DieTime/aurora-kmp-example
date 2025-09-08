TARGET = com.example.aurorakmp

CONFIG += \
    auroraapp \

SOURCES += \
    $$files(kmp/bindings/*.cpp, true) \
    src/main.cpp \

HEADERS += \
    $$files(kmp/bindings/*.hpp, true) \
    $$files(kmp/static/*.h, true) \
    src/greeting.hpp \
    src/github-repository.hpp \
    src/database.hpp \

INCLUDEPATH += \
    kmp/static \
    kmp/bindings \
    kmp/bindings/ru/auroraos/kmp/qtbindings \

LIBS += \
    -L$$PWD/kmp/static \
    -lshared \
    -lz \ # Required for Ktor
    -lsqlite3 \ # Required for SQLDelight

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

DISTFILES += \
    rpm/com.example.aurorakmp.spec
