#include "clan.h"

Clan::Clan( TypeClan clan, QString nom, float puissance, QString description, QString cheminBanniere)
    : m_Nom(nom), m_CheminBanniere(cheminBanniere), m_Description(description), m_Puissance(puissance)
{
    m_TypeClan = clan;
}

QString Clan::GetNomClan(TypeClan typeClan)
{
    switch (typeClan) {
    case TypeClan::Rictus : return "Rictus";
    case TypeClan::Mors : return "Mors";
    case TypeClan::Skab : return "Skab";
    case TypeClan::Pestilens : return "Pestilens";
    case TypeClan::Septik : return "Septik";
    case TypeClan::Skrat : return "Skrat";
    case TypeClan::Gratzz : return "Gratzz";
    case TypeClan::Morbidus : return "Morbidus";
    case TypeClan::Scorbut : return "Scorbut";
    case TypeClan::Krizzor : return "Krizzor";
    case TypeClan::Liskit : return "Liskit";
    case TypeClan::Festus : return "Festus";
    case TypeClan::Raklur : return "Raklur";
    case TypeClan::Eshin : return "Eshin";
    case TypeClan::Moulder : return "Moulder";
    case TypeClan::Skyre : return "Skyre";
    case TypeClan::Mordkin : return "Mordkin";
    case TypeClan::Grutnik : return "Grutnik";
    case TypeClan::Charogne : return "Charogne";
    case TypeClan::Volkn : return "Volkn";
    }

    return "";
}
