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
        main_window.cpp

HEADERS += \
        main_window.h
