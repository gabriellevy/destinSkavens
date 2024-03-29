#ifndef DPERSOSKAVEN_H
#define DPERSOSKAVEN_H

#include "../destinLib/perso.h"
#include "../destinLib/gestionnairecarac.h"

class Clan;
class Profession;
class Lieu;

class UniversSkaven;

struct Metier {
    QString nom;


};

class DPersoSkaven : public DPerso
{
protected :
    void RafraichirAffichage();

public:
    DPersoSkaven(QString id, QString nom, QString description, QString CheminImagePortrait);

    void InitialiserPerso();

    //Clan* m_Clan = nullptr;
    //Profession* m_Profession = nullptr;

    UniversSkaven* GetUniversSkaven();

    // pseudo accesseurs qui vont chercher les caracs des caracs dans le stableaux d'univers :
    Profession* GetProfession();
    Clan* GetClan();
    Lieu* GetLieu();

    static DPersoSkaven* GetSkaven();
    static DPersoSkaven* ME;
};

#endif // DPERSOSKAVEN_H
