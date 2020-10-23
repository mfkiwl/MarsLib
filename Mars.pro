QT       += core gui serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(./RTKLib.pri)

SOURCES += \
    main.cpp \
    obsdialog.cpp \
    ui/mainwindow.cpp \
    utils/serialportThread.cpp

HEADERS += \
    mars.h \
    obsdialog.h \
    src/rtklib.h \
    ui/mainwindow.h \
    utils/serialportThread.h


FORMS += \
    mainwindow.ui \
    obsdialog.ui

TRANSLATIONS += \
    Mars_zh_CN.ts

INCLUDEPATH +=\
    ./src/


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += src \

win32: LIBS += -lWinMM

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Debug/release/ -lRTKLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Debug/debug/ -lRTKLib
else:macx: LIBS += -L$$PWD/Debug/ -lRTKLib

INCLUDEPATH += $$PWD/Debug/debug
DEPENDPATH += $$PWD/Debug/debug
