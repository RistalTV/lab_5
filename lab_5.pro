TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    addeleminlist.c \
    func.c \
        main.c \
    select.c \
    output.c \
    check.c

HEADERS += \
    addeleminlist.h \
    func.h \
    select.h \
    output.h \
    check.h

DISTFILES += \
    mak.txt
