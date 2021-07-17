QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alfalfaField.cpp \
    dialogformakeaccount.cpp \
    farm.cpp \
    main.cpp \
    silo.cpp \
    storage.cpp\
    widget.cpp\
    scoreboard.cpp\
    mainwindow.cpp\
    person.cpp\
    Aviculture.cpp\
    Dairyfarm.cpp\
    Sheepcote.cpp\
    dialogstorage.cpp\
    dialogsilo.cpp\
    dialogalfalfafield.cpp\
    Sheepcote_back.cpp\
    Dairyfarm_back.cpp\
    Aviculture_back.cpp\
    store.cpp\
    wheatland2.cpp\
    wheatland_back.cpp\
    getamount.cpp\



HEADERS += \
    alfalfaField.h \
    dialogformakeaccount.h \
    farm.h \
    person.h \
    silo.h \
    storage.h\
    widget.h\
    scoreboard.h\
    mainwindow.h\
    Aviculture.h\
    Dairyfarm.h\
    Sheepcote.h\
    dialogstorage.h\
    dialogsilo.h\
    dialogalfalfafield.h\
    Sheepcote_back.h\
    Dairyfarm_back.h\
    Aviculture_back.h\
    store.h\
    wheatland2.h\
    wheatland_back.h\
    getamount.h\



FORMS += \
    dialogalfalfafield.ui\
    dialogformakeaccount.ui \
    dialogsilo.ui\
    dialogstorage.ui\
    widget.ui\
    mainwindow.ui\
    scoreboard.ui\
    wheatland2.ui\
    store.ui\
    getamount.ui\


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
