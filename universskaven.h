#ifndef UNIVERSSKAVEN_H
#define UNIVERSSKAVEN_H

#include "../destinLib/univers.h"
#include "genhistskaven.h"
#include "clan.h"
#include "profession.h"
#include "lieu.h"

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
    void GenererLieu(TypeLieu typeLieu);
    void GenererClan(TypeClan typeClan, float puissance, QString description, QString chemin);
    void GenererTousLesClans();
    void GenererToutesLesProfessions();
    void GenererTousLesLieux();

    // identifiants de caracs importantes :
    static QString CARAC_CLAN;
    static QString CARAC_PROF;
    static QString CARAC_LIEU;
    static QString CARAC_FOURRURE;
    static QString CARAC_TAILLE;
    static QString CARAC_STATUT;
    static QString CARAC_MALEPIERRE; // grammes
    static QString CARAC_PEUR; // c'est la peur qui repose sur des actions temporaires du héros comme une intimidation. Il diminue avec le temps et affecte le statut social

    QVector<Clan*> m_TousLesClans;
    QVector<Lieu*> m_TousLesLieux;
    QVector<Profession*> m_TousLesProfessions;

    Profession* GetProfession(QString idProfession);
    Clan* GetClan(QString idClan);
    Clan* GetClanViaBanniere(QString banniere);
    Lieu* GetLieu(QString idLieu);

    static QString VIE_SKAVEN;
protected:
};

#endif // UNIVERSSKAVEN_H
