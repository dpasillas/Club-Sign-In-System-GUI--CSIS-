#-------------------------------------------------
#
# Project created by QtCreator 2012-02-06T14:35:54
#
#-------------------------------------------------

QT       += core gui

TARGET = AGS_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    optionsdialog.cpp \
    readerthread.cpp \
    id_validator.cpp

HEADERS  += mainwindow.h \
    optionsdialog.h \
    readerthread.h \
    id_validator.h

FORMS    += mainwindow.ui \
    optionsdialog.ui

RESOURCES += \
    resources.qrc
