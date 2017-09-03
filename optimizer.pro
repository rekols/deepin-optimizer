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
    thread.cpp \
    cpu_monitor.cpp \
    memory_monitor.cpp \
    disk_monitor.cpp \
    monitor_widget.cpp \
    widget/progress_bar.cpp \
    widget/icon_bar.cpp \
    home_widget.cpp \
    scan_page.cpp \
    clear_widget.cpp \
    cleaner_page.cpp

HEADERS += \
        main_window.h \
    tabbar.h \
    utils.h \
    thread.h \
    cpu_monitor.h \
    memory_monitor.h \
    disk_monitor.h \
    monitor_widget.h \
    widget/progress_bar.h \
    widget/icon_bar.h \
    home_widget.h \
    scan_page.h \
    clear_widget.h \
    cleaner_page.h

RESOURCES = optimizer.qrc
