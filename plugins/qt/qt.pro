######################################################################
# Automatically generated by qmake (2.01a) ?? ????. 14 17:12:28 2013
######################################################################

QT += core
CONFIG += console 
TEMPLATE =  app # lib
TARGET = 
DEPENDPATH += . \
              ../../include/
INCLUDEPATH += . \
               ../../include/

# Input
HEADERS += variantinterface.h \
           mapinterface.h \
           timerinterface.h \
           context.h \

SOURCES += main.cpp \
           

DESTDIR = ../../lib/

unix {
	DEFINES += "UNIX=1"
	DEFINES += "LINUX=1"
	DEFINES += "GCC=1"
}

win32 {
	DEFINES += "WIN32=1"
	DEFINES +=  "MINGW=1"
}

CONFIG(debug, debug|release) {
    TARGET = dukqt-debug
}

CONFIG(release, debug|release) {
    TARGET = dukqt-release
}

QMAKE_CXXFLAGS += -Wno-reorder -Wno-unused -Wno-sign-compare -w
