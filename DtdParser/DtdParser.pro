TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dtdlib.cpp

HEADERS += \
    dtd.h
        data.path = $$OUT_PWD/

        data.files += $$PWD/*.dat

        data.files += $$PWD/*.xml

        data.files += $$PWD/*.dtd

        data.files += $$PWD/*.txt

        INSTALLS += data
