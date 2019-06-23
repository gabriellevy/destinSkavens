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
public:
    DPersoSkaven();

    Clan* m_Clan = nullptr;
    Profession* m_Profession = nullptr;

    UniversSkaven* GetUniversSkaven();
    void DeduireImage();
};

#endif // DPERSOSKAVEN_H
