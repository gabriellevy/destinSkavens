#ifndef DPERSOSKAVEN_H
#define DPERSOSKAVEN_H

#include "../destinLib/perso.h"


class Clan;
class Profession;

class UniversSkaven;

struct Metier {
    QString nom;


};

class DPersoSkaven : public DPerso
{
protected :
    void RafraichirAffichage();

public:
    DPersoSkaven();

    void InitialiserPerso();

    Clan* m_Clan = nullptr;
    Profession* m_Profession = nullptr;

    UniversSkaven* GetUniversSkaven();
};

#endif // DPERSOSKAVEN_H
