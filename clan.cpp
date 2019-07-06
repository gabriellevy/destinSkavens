#include "clan.h"

Clan::Clan( TypeClan clan, QString nom, float puissance, QString description, QString cheminBanniere)
    : m_Nom(nom), m_CheminBanniere(cheminBanniere), m_Description(description), m_Puissance(puissance)
{
    m_TypeClan = clan;
}
