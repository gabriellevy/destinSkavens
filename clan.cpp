#include "clan.h"

Clan::Clan( TypeClan clan, QString nom, QString description/*, DPersoSkaven* chef*/, QString cheminBanniere)
    : m_Nom(nom), m_Description(description), m_CheminBanniere(cheminBanniere)
{
    m_TypeClan = clan;
}
