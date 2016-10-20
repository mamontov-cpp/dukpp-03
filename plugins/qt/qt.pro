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
           test.h \
           test2.h \
    pushvariant.h \
    qobjectfinalizer.h \
    valueownership.h \
    isqobject.h \
    getadressofcommontypeorqobject.h \
    getaddressoftype.h \
    constructor.h \
    wrapvalue.h \
    registermetatype.h \
    toqobject.h \
    objectwithownership.h \
    basicmetatypes.h \
    basiccontext.h \
    getvalue.h \
    pushvalue.h \
    dukqt.h \
    classbinding.h \
    metaconstructor.h \
    metamethod.h \
    trygetpointertoqobjectdescendant.h \
    metapropertyaccessor.h \
    convert.h

SOURCES += main.cpp \
    context.cpp \
    pushvariant.cpp \
    qobjectfinalizer.cpp \
    wrapvalue.cpp \
    registermetatype.cpp \
    toqobject.cpp \
    classbinding.cpp \
    metaconstructor.cpp \
    metamethod.cpp \
    metapropertyaccessor.cpp \
    convert.cpp
           

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

DISTFILES +=
