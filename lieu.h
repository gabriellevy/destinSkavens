#ifndef LIEU_H
#define LIEU_H

#include <QString>
#include "../destinLib/condition.h"

enum class TypeLieu : char {
    Skarogne,
    Malefosse,
    Gouffre_Noir,
    Le_Mont_Bossu,
    Sous_Mousillon,
    Sous_Altdorf,
    Sous_Delbertz,
    Sous_Middenheim,
    Fosse_putride,
    Mont_Purulent,
    Pic_Fetide,
    Fosse_Bilieuse,
    Puits_du_Queekz,
    Sous_la_Lustrie,
    Sous_empire,
    Sous_Bretonnie,
    Sous_estalie,
    Sous_Tilee,
    Sous_Arabie,
    Sous_Terres_sombres,
    Sous_les_terres_du_Sud,
    Sous_Cathay,
    Sous_Naggaroth,
    Cite_des_Piliers,
    NombreTotal // garder ça à la fin
};

class Lieu
{
public:
    Lieu(TypeLieu typeLieu);

    TypeLieu m_TypeLieu;
    QString m_Nom;
    QString m_Description;

    // condition à respecter pour pouvoir vivre dans ce lieu
    QList<Condition*> m_Conditions = {};

    /**
     * @brief condition calculant le pourcentage de chances d'être né dans ce lieu
     *  directement à la majorité
     */
    Condition* m_PoidsProba = nullptr;
};

#endif // LIEU_H
