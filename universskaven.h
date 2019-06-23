#ifndef UNIVERSSKAVEN_H
#define UNIVERSSKAVEN_H

#include <QWidget>
#include "../destinLib/univers.h"
#include "genhistskaven.h"

enum Clan {
    Rictus,
    Mors,
    Skab,
    Pestilens,
    Septik,
    Skrat,
    Gratzz,
    Morbidus,
    Scorbut,
    Krizzor,
    Liskit,
    Festus,
    Raklur,
    Eshin,
    Moulder,
    Skyre,
    Mordkin,
    Grutnik,
    Charogne,
    Volkn
};

class UniversSkaven : public Univers
{
    Q_OBJECT

public:
    UniversSkaven(ModeAffichage modeAffichage = ModeAffichage::ema_Jeu,
                QWidget *parent = nullptr);

    Hist* ExecuterGenerateurHistoire();

    QString GenererNomSkaven();
    Clan GenererClan();

protected:
    // génère toutes les caracs qui peuvent être visualisées par le joueur (d'autres caracs peuvent être générées et invisibles n'importe quand dans l'aventure)
    virtual void GenererCaracs();
};

#endif // UNIVERSSKAVEN_H
