TARGET = imagepub
HEADERS += imagepub.h uploaddialog.h imagepubsettings.h
SOURCES += imagepub.cpp uploaddialog.cpp imagepubsettings.cpp
INCLUDEPATH += ../../include /usr/include
CONFIG += qt plugin
QT += core gui network
TEMPLATE = lib
RESOURCES += imagepub.qrc
FORMS += uploaddialog.ui imagepubsettings.ui
TRANSLATIONS += imagepub_ru.ts