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
        widget/tabbar.cpp \
        utils.cpp \
        thread.cpp \
        home_page/cpu_monitor.cpp \
        home_page/memory_monitor.cpp \
        home_page/disk_monitor.cpp \
        home_page/monitor_widget.cpp \
        widget/progress_bar.cpp \
        widget/icon_bar.cpp \
        home_widget.cpp \
        clear_page/scan_page.cpp \
        clear_widget.cpp \
        clear_page/cleaner_page.cpp \
        clear_page/cfinish_page.cpp

HEADERS += \
        main_window.h \
        widget/tabbar.h \
        utils.h \
        thread.h \
        home_page/cpu_monitor.h \
        home_page/memory_monitor.h \
        home_page/disk_monitor.h \
        home_page/monitor_widget.h \
        widget/progress_bar.h \
        widget/icon_bar.h \
        home_widget.h \
        clear_page/scan_page.h \
        clear_widget.h \
        clear_page/cleaner_page.h \
        clear_page/cfinish_page.h

RESOURCES = optimizer.qrc
