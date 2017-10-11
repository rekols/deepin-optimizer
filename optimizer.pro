#-------------------------------------------------
#
# Project created by QtCreator 2017-09-02T12:33:26
#
#-------------------------------------------------

QT       += core gui concurrent svg

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
        widgets/progress_bar.cpp \
        widgets/icon_bar.cpp \
        ClearPage/scan_page.cpp \
        widgets/load_page.cpp \
    home_page.cpp \
    ClearPage/finish_page.cpp \
    ClearPage/scanned_page.cpp \
    cleaner_page.cpp \
    widgets/hseparator.cpp \
    widgets/monitor_widget.cpp

HEADERS += \
        main_window.h \
        widgets/tabbar.h \
        utils.h \
        thread.h \
        widgets/progress_bar.h \
        widgets/icon_bar.h \
        ClearPage/scan_page.h \
        widgets/load_page.h \
    home_page.h \
    ClearPage/finish_page.h \
    ClearPage/scanned_page.h \
    cleaner_page.h \
    widgets/hseparator.h \
    widgets/monitor_widget.h

RESOURCES = optimizer.qrc
