QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    battlewindow.cpp \
    cartyleria.cpp \
    cbomba.cpp \
    cbron.cpp \
    cczolg.cpp \
    cczynnik_losowy.cpp \
    cjednostka.cpp \
    cmiasto.cpp \
    cpiechota.cpp \
    cpocisk.cpp \
    cpotyczka.cpp \
    cprzeciwlotniczy.cpp \
    cprzeciwpancerny.cpp \
    cprzeszkoda.cpp \
    cpustynia.cpp \
    cteren.cpp \
    ctimer.cpp \
    czwykly.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    battlewindow.h \
    cartyleria.h \
    cbomba.h \
    cbron.h \
    cczolg.h \
    cczynnik_losowy.h \
    cjednostka.h \
    cmiasto.h \
    cpiechota.h \
    cpocisk.h \
    cpotyczka.h \
    cprzeciwlotniczy.h \
    cprzeciwpancerny.h \
    cprzeszkoda.h \
    cpustynia.h \
    cteren.h \
    ctimer.h \
    czwykly.h \
    mainwindow.h

FORMS += \
    battlewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
