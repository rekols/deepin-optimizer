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
        widgets/tabbar.cpp \
        utils.cpp \
        thread.cpp \
        HomePage/cpu_monitor.cpp \
        HomePage/memory_monitor.cpp \
        HomePage/disk_monitor.cpp \
        HomePage/monitor_widget.cpp \
        widgets/progress_bar.cpp \
        widgets/icon_bar.cpp \
        ClearPage/scan_page.cpp \
        widgets/load_page.cpp \
    home_page.cpp \
    clear_page.cpp \
    ClearPage/finish_page.cpp \
    ClearPage/scanned_page.cpp

HEADERS += \
        main_window.h \
        widgets/tabbar.h \
        utils.h \
        thread.h \
        HomePage/cpu_monitor.h \
        HomePage/memory_monitor.h \
        HomePage/disk_monitor.h \
        HomePage/monitor_widget.h \
        widgets/progress_bar.h \
        widgets/icon_bar.h \
        ClearPage/scan_page.h \
        widgets/load_page.h \
    home_page.h \
    clear_page.h \
    ClearPage/finish_page.h \
    ClearPage/scanned_page.h

RESOURCES = optimizer.qrc
