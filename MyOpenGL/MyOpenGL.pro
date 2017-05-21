#-------------------------------------------------
#
# Project created by QtCreator 2013-09-25T09:11:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyOpenGL
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    myglwidget.cpp \
    trebuchet.cpp \
    target.cpp

HEADERS  += window.h \
    myglwidget.h \
    trebuchet.h \
    target.h

FORMS    += window.ui


LIBS += -lOpengl32 -lglu32


