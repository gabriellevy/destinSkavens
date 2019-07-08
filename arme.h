#ifndef ARME_H
#define ARME_H

#include "../destinLib/selectionneurdenoeud.h"
#include "genhistskaven.h"

enum class TypeArme : char {
    Attrapechoses,
    Globe_Vent_Toxique,
    Malelame,
    Pistolet_Malepierre,
    Nombre_Total
};

class Arme
{
    TypeArme m_TypeArme;
    QString m_Nom;
public:
    Arme(TypeArme typeArme);

    static QString GetNomArme(TypeArme typeArme);
};

namespace EVT {
    NoeudProbable* RecompenseArmeSkyre(GenHistSkaven* genHist);
}

#endif // ARME_H
