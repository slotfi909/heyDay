QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alfalfafield.cpp \
    dialogformakeaccount.cpp \
    farm.cpp \
    main.cpp \
    silo.cpp \
    widget.cpp\
    scoreboard.cpp\
    mainwindow.cpp\
    person.cpp\
    Aviculture.cpp\
    Dairyfarm.cpp\
    Sheepcote.cpp\



HEADERS += \
    alfalfafield.h \
    dialogformakeaccount.h \
    farm.h \
    person.h \
    silo.h \
    widget.h\
    scoreboard.h\
    mainwindow.h\
    Aviculture.h\
    Dairyfarm.h\
    Sheepcote.h\



FORMS += \
    alfalfafield.ui \
    dialogformakeaccount.ui \
    silo.ui \
    widget.ui\
    mainwindow.ui\
    scoreboard.ui\
    wheatland.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
