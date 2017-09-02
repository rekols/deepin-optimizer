#-------------------------------------------------
#
# Project created by QtCreator 2017-09-02T12:33:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = optimizer
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        main_window.cpp \
    tabbar.cpp \
    utils.cpp \
    home_page.cpp \
    clear_page.cpp

HEADERS += \
        main_window.h \
    tabbar.h \
    utils.h \
    home_page.h \
    clear_page.h

RESOURCES = optimizer.qrc
