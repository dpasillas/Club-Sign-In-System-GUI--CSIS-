#-------------------------------------------------
#
# Project created by QtCreator 2012-02-06T14:35:54
#
#-------------------------------------------------

QT       += core gui sql

TARGET = AGS_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    optionsdialog.cpp \
    id_validator.cpp \
    passworddialog.cpp

HEADERS  += mainwindow.h \
    optionsdialog.h \
    id_validator.h \
    passworddialog.h \
    methodrunner.h

FORMS    += mainwindow.ui \
    optionsdialog.ui \
    passworddialog.ui

RESOURCES += \
    resources.qrc
