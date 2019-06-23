#ifndef DPERSOSKAVEN_H
#define DPERSOSKAVEN_H

#include "../destinLib/perso.h"


class Clan;

class UniversSkaven;

struct Metier {
    QString nom;


};

class DPersoSkaven : public DPerso
{
public:
    DPersoSkaven();

    Clan* m_Clan = nullptr;

    UniversSkaven* GetUniversSkaven();
    void DeduireImage();
};

#endif // DPERSOSKAVEN_H
