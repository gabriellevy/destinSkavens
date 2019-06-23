#ifndef UNIVERSSKAVEN_H
#define UNIVERSSKAVEN_H

#include "../destinLib/univers.h"
#include "genhistskaven.h"

class Clan;

class UniversSkaven : public Univers
{
    Q_OBJECT

public:
    UniversSkaven(ModeAffichage modeAffichage = ModeAffichage::ema_Jeu,
                QWidget *parent = nullptr);

    Hist* ExecuterGenerateurHistoire();

    QString GenererNomSkaven();
    Clan* ChoisirClan();

    void GenererTousLesClans();

protected:
    // génère toutes les caracs qui peuvent être visualisées par le joueur (d'autres caracs peuvent être générées et invisibles n'importe quand dans l'aventure)
    virtual void GenererCaracs();
    QVector<Clan*> m_TousLesClans;
};

#endif // UNIVERSSKAVEN_H
