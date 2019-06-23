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

    Clan(TypeClan clan, QString nom/*, DPersoSkaven* chef = nullptr, QString cheminBanniere = ""*/);

    TypeClan m_TypeClan;
    QString m_Nom;

    //DPersoSkaven* m_Chef = nullptr;
    QString m_CheminBanniere;
};

#endif // CLAN_H
