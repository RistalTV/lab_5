TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    addeleminlist.c \
    deleleminlist.c \
    func.c \
        main.c \
    search.c \
    select.c \
    output.c \
    check.c

HEADERS += \
    addeleminlist.h \
    deleleminlist.h \
    func.h \
    search.h \
    select.h \
    output.h \
    check.h

DISTFILES += \
    mak.txt
