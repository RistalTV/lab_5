TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    seller.c \
    select.c \
    output.c \
    check.c

HEADERS += \
    seller.h \
    select.h \
    output.h \
    check.h

DISTFILES += \
    mak.txt
