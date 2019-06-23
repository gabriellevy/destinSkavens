#ifndef DPERSOSKAVEN_H
#define DPERSOSKAVEN_H

#include <QString>
#include "../destinLib/perso.h"
#include "universskaven.h"

struct Metier {
    QString nom;


};

class DPersoSkaven : public DPerso
{
public:
    DPersoSkaven();

    Clan m_Clan;

    UniversSkaven* GetUniversSkaven();
    void DeduireImage();
};

#endif // DPERSOSKAVEN_H
