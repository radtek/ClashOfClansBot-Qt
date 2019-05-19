# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = ClashOfClansBot-Qt
DESTDIR = ../x64/Debug
QT += core network gui svg multimedia uitools widgets qml websockets quickwidgets quick multimediawidgets charts
CONFIG += debug
DEFINES += _UNICODE WIN64 QT_DLL QT_CHARTS_LIB QT_MULTIMEDIA_LIB QT_MULTIMEDIAWIDGETS_LIB QT_NETWORK_LIB QT_QML_LIB QT_QUICK_LIB QT_QUICKWIDGETS_LIB QT_SVG_LIB QT_UITOOLS_LIB QT_WEBSOCKETS_LIB QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/$(ConfigurationName)
LIBS += -lavcodec \
    -lavutil \
    -lpostproc \
    -lswresample \
    -lswscale \
    -lavformat \
    -lavdevice \
    -lavfilter
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(ClashOfClansBot-Qt.pri)
