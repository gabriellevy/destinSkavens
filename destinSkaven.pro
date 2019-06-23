#-------------------------------------------------
#
# Project created by QtCreator 2019-06-21T20:32:32
#
#-------------------------------------------------

QT       += core gui sql widgets multimedia

TARGET = destinSkaven
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big

SOURCES += \
    ../destinLib/theme.cpp \
    ../destinLib/univers.cpp \
    ../destinLib/histoire.cpp \
    ../destinLib/carac.cpp \
    ../destinLib/condition.cpp \
    ../destinLib/noeud.cpp \
    ../destinLib/effet.cpp \
    ../destinLib/choix.cpp \
    ../destinLib/evt.cpp \
    ../destinLib/evt.h \
    ../destinLib/genevt.cpp \
    ../destinLib/execevt.cpp \
    ../destinLib/glisseur.cpp \
    ../destinLib/exechistoire.cpp \
    ../destinLib/execeffet.cpp \
    ../destinLib/execchoix.cpp \
    ../destinLib/execnoeud.cpp \
    ../destinLib/genhistoire.cpp \
    ../destinLib/perso.cpp \
    ../destinLib/setcarac.cpp \
    ../destinLib/evtaleatoire.cpp \
    ../destinLib/reglages.cpp \
    ../destinLib/dbmanager.cpp \
    ../destinLib/selectionneurdevenement.cpp \
    clan.cpp \
    aspectratiolabel.cpp \
    dpersoskaven.cpp \
    genhistskaven.cpp \
    profession.cpp \
    universskaven.cpp \
    main.cpp

HEADERS += \
    ../destinLib/theme.h \
    ../destinLib/univers.h \
    ../destinLib/histoire.h \
    ../destinLib/carac.h \
    ../destinLib/condition.h \
    ../destinLib/noeud.h \
    ../destinLib/effet.h \
    ../destinLib/choix.h \
    ../destinLib/evt.h \
    ../destinLib/genevt.h \
    ../destinLib/execevt.h \
    ../destinLib/glisseur.h \
    ../destinLib/exechistoire.h \
    ../destinLib/execeffet.h \
    ../destinLib/execchoix.h \
    ../destinLib/execnoeud.h \
    ../destinLib/genhistoire.h \
    ../destinLib/perso.h \
    ../destinLib/setcarac.h \
    ../destinLib/evtaleatoire.h \
    ../destinLib/reglages.h \
    ../destinLib/dbmanager.h \
    ../destinLib/selectionneurdevenement.h \
    aspectratiolabel.h \
    clan.h \
    dpersoskaven.h \
    genhistskaven.h \
    profession.h \
    universskaven.h

FORMS += \
    ../destinLib/univers.ui \
    ../destinLib/carac.ui \
    ../destinLib/choix.ui \
    ../destinLib/effet.ui \
    ../destinLib/evt.ui \
    ../destinLib/histoire.ui \
    ../destinLib/noeud.ui \
    ../destinLib/perso.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    persos.qrc
