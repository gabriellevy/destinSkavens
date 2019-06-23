#include "dpersoskaven.h"
#include "universskaven.h"

DPersoSkaven::DPersoSkaven()
{
    // génération aléatoire du perso :
    this->m_Nom = GetUniversSkaven()->GenererNomSkaven();

    this->m_Clan = GetUniversSkaven()->GenererClan();

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
        //switch
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
