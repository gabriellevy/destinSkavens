#include "dpersoskaven.h"
#include "universskaven.h"
#include "clan.h"

DPersoSkaven::DPersoSkaven()
{
    // génération aléatoire du perso :
    this->m_Nom = GetUniversSkaven()->GenererNomSkaven();

    this->m_Clan = GetUniversSkaven()->ChoisirClan();

    this->DeduireImage();
    std::srand(time(nullptr));
}

UniversSkaven* DPersoSkaven::GetUniversSkaven()
{
    return static_cast<UniversSkaven*>(Univers::ME);
}

void DPersoSkaven::DeduireImage()
{
    this->m_CheminImagePortrait = "";
    // image spécial selon le métier

    // si aucune alors image spéciale selon le clan :
    if ( this->m_CheminImagePortrait == "" )
    {
        switch (this->m_Clan->m_TypeClan) {
        case TypeClan::Eshin : {
            QStringList chemins = {
                ":/images/portraits/eschin01.jpg",
                ":/images/portraits/eschin02.jpg",
                ":/images/portraits/eschin03.jpg",
                ":/images/portraits/eschin04.jpg",
                ":/images/portraits/eschin05.jpg"
            };
            this->m_CheminImagePortrait = chemins[rand() % chemins.length()];
        } break;
        case TypeClan::Moulder : {
            QStringList chemins = {
                ":/images/portraits/moulder01.jpg"
            };
            this->m_CheminImagePortrait = chemins[rand() % chemins.length()];
        } break;
        case TypeClan::Pestilens : {
            QStringList chemins = {
                ":/images/portraits/peste01.jpg",
                ":/images/portraits/peste02.jpg",
                ":/images/portraits/peste03.jpg"
            };
            this->m_CheminImagePortrait = chemins[rand() % chemins.length()];
        } break;

        }
    }

    // si toujours aucun alors image skaven de base
    if ( this->m_CheminImagePortrait == "" )
    {
        QStringList chemins = {
            ":/images/portraits/skaven01.png",
            ":/images/portraits/skaven02.png",
            ":/images/portraits/skaven03.jpg",
            ":/images/portraits/skaven04.jpg",
            ":/images/portraits/skaven05.jpg",
            ":/images/portraits/skaven06.jpg",
            ":/images/portraits/skaven07.jpg"
        };
        this->m_CheminImagePortrait = chemins[rand() % chemins.length()];
    }
}
//":/images/portraits/skaven01.png"
