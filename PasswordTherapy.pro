INCLUDEPATH += $$PWD/src

QT += widgets

SOURCES += \
    src/main.cpp \
    src/mainWindow.cpp \
    src/QRGenerator.cpp \
    src/sha512.cpp

HEADERS += \
    include/mainWindow.h \
    include/QRGenerator.h \
    include/sha512.h
