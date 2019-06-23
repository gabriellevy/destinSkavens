#include "clan.h"

Clan::Clan( TypeClan clan, QString nom/*, DPersoSkaven* chef, QString cheminBanniere*/)
    : m_Nom(nom)//, m_Chef(chef), m_CheminBanniere(cheminBanniere)
{
    m_TypeClan = clan;
}
