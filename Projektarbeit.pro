TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    koordinatenlib.cpp \
    datenlib.cpp \
    dtdlib.cpp \
    datenattlib.cpp \
    suchelib.cpp

DISTFILES += \
    Koordinaten.txt \
    Daten.dtd \
    daten.dat \
    KoordinatenNeu.txt \
    Daten.xml

        data.path = $$OUT_PWD/

        data.files += $$PWD/*.dat

        data.files += $$PWD/*.xml

        data.files += $$PWD/*.dtd

        data.files += $$PWD/*.txt

        INSTALLS += data

HEADERS += \
    daten.h \
    koordinaten.h \
    datendtd.h \
    datenatt.h

