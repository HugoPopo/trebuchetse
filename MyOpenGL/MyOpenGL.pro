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
    target.cpp \
    terrain.cpp \
    cube.cpp \
    boulet.cpp \
    bras.cpp \
    line.cpp \
    logo.cpp

HEADERS  += window.h \
    myglwidget.h \
    trebuchet.h \
    target.h \
    terrain.h \
    cube.h \
    boulet.h \
    bras.h \
    line.h \
    logo.h

FORMS    += window.ui


LIBS += -lOpengl32 -lglu32

RESOURCES += \
    ressource.qrc


