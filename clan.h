#ifndef CLAN_H
#define CLAN_H

#include <QString>

enum class TypeClan : char {
    Rictus,
    Mors,
    Skab,
    Pestilens,
    Septik,
    Skrat,
    Gratzz,
    Morbidus,
    Scorbut,
    Krizzor,
    Liskit,
    Festus,
    Raklur,
    Eshin,
    Moulder,
    Skyre,
    Mordkin,
    Grutnik,
    Charogne,
    Volkn
};

class Clan
{

public:

    Clan(TypeClan clan, QString nom, QString description/*, DPersoSkaven* chef = nullptr*/, QString cheminBanniere = "");

    TypeClan m_TypeClan;
    QString m_Nom;
    QString m_Description;

    //DPersoSkaven* m_Chef = nullptr;
    QString m_CheminBanniere;
};

#endif // CLAN_H
