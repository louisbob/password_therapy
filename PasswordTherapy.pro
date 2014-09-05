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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/release/ -lcrypto++
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/debug/ -lcrypto++
else:unix: LIBS += -L$$PWD/../../../../usr/lib/ -lcrypto++

INCLUDEPATH += $$PWD/../../../../usr/include
DEPENDPATH += $$PWD/../../../../usr/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/release/libcrypto++.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/debug/libcrypto++.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/release/crypto++.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/debug/crypto++.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../usr/lib/libcrypto++.a
