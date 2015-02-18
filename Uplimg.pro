TEMPLATE = app

QT += qml quick widgets core gui

SOURCES += main.cpp \
    core/systemtrayicon.cpp \
    uplimg.cpp \
    windows/mainwindow.cpp \
    core/screentaker.cpp \
    core/areauserdefiner.cpp \
    network/httpsender.cpp \
    file/filemanager.cpp \
    network/filesender.cpp \
    windows/uploadingwindow.cpp \
    core/settings.cpp \
    qml/cpp_wrapper/qmlsettings.cpp

RESOURCES += qml.qrc \
    images.qrc

QMAKE_CXXFLAGS += -std=c++11 # C++11 for sure !
QMAKE_CXXFLAGS += -lX11

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    qml/mainWindow.qml \
    qml/MyAccount.qml \
    qml/Overview.qml \
    qml/upload_window/UploadWindow.qml \
    qml/SettingsPage.qml

HEADERS += \
    core/systemtrayicon.h \
    uplimg.h \
    windows/mainwindow.h \
    core/screentaker.h \
    core/areauserdefiner.h \
    network/httpsender.h \
    file/filemanager.h \
    file/file.h \
    core/utils.h \
    network/filesender.h \
    windows/uploadingwindow.h \
    core/settings.h \
    core/keys_data.h \
    qml/cpp_wrapper/qmlsettings.h

# Global shortcuts from the Qxt Team !
HEADERS += \
    shortcuts/qxtglobalshortcut.h \
    shortcuts/qxtglobalshortcut_p.h

SOURCES += \
    shortcuts/qxtglobalshortcut.cpp \

win32 {
    SOURCES += shortcuts/win/qxtglobalshortcut_win.cpp
}

unix {
    SOURCES += shortcuts/x11/qxtglobalshortcut_x11.cpp
    LIBS += -lX11
}

mac {
    SOURCES += shortcuts/mac/qxtglobalshortcut_mac.cpp
}
