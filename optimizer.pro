#-------------------------------------------------
#
# Project created by QtCreator 2017-09-02T12:33:26
#
#-------------------------------------------------

QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = optimizer
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        main_window.cpp \
        Widget/tabbar.cpp \
        utils.cpp \
        thread.cpp \
        HomePage/cpu_monitor.cpp \
        HomePage/memory_monitor.cpp \
        HomePage/disk_monitor.cpp \
        HomePage/monitor_widget.cpp \
        Widget/progress_bar.cpp \
        Widget/icon_bar.cpp \
        home_widget.cpp \
        ClearPage/scan_page.cpp \
        clear_widget.cpp \
        ClearPage/cleaner_page.cpp \
        ClearPage/cfinish_page.cpp \
        Widget/load_page.cpp

HEADERS += \
        main_window.h \
        Widget/tabbar.h \
        utils.h \
        thread.h \
        HomePage/cpu_monitor.h \
        HomePage/memory_monitor.h \
        HomePage/disk_monitor.h \
        HomePage/monitor_widget.h \
        Widget/progress_bar.h \
        Widget/icon_bar.h \
        home_widget.h \
        ClearPage/scan_page.h \
        clear_widget.h \
        ClearPage/cleaner_page.h \
        ClearPage/cfinish_page.h \
        Widget/load_page.h

RESOURCES = optimizer.qrc
