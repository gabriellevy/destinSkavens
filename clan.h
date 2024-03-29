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
    Volkn,
    Treecherik,
    Skaar,
    Scruten,
    Skaul,
    Flem,
    Sleekit
};

class Clan
{

public:

    Clan(TypeClan clan, QString nom, float puissance, QString description, QString cheminBanniere = "");

    QString m_CheminBanniere = "";
    TypeClan m_TypeClan;
    QString m_Nom;
    QString m_Description;
    float m_Puissance;

    //DPersoSkaven* m_Chef = nullptr;

    static QString GetNomClan(TypeClan typeClan);
};

#endif // CLAN_H
