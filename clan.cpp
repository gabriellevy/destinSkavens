#include "clan.h"

Clan::Clan( TypeClan clan, QString nom, float puissance, QString description/*, DPersoSkaven* chef*/, QString cheminBanniere)
    : m_Nom(nom), m_Description(description), m_CheminBanniere(cheminBanniere), m_Puissance(puissance)
{
    m_TypeClan = clan;
}
