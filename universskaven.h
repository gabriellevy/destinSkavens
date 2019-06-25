#ifndef UNIVERSSKAVEN_H
#define UNIVERSSKAVEN_H

#include "../destinLib/univers.h"
#include "genhistskaven.h"
#include "clan.h"
#include "profession.h"

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
    Profession* ChoisirProfession();

    void GenererProfession(TypeProfession typeProfession);
    void GenererClan(TypeClan typeClan, QString nom, float puissance, QString description, QString chemin);
    void GenererTousLesClans();
    void GenererToutesLesProfessions();

    // identifiants de caracs importantes :
    static QString CARAC_CLAN;
    static QString CARAC_PROF;

protected:
    // génère toutes les caracs qui peuvent être visualisées par le joueur (d'autres caracs peuvent être générées et invisibles n'importe quand dans l'aventure)
    virtual void GenererCaracs();
    QVector<Clan*> m_TousLesClans;
    QVector<Profession*> m_TousLesProfessions;
};

#endif // UNIVERSSKAVEN_H
