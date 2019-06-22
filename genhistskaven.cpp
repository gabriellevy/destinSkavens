#include "genhistskaven.h"
#include "../destinLib/perso.h"
#include "universskaven.h"

GenHistSkaven::GenHistSkaven(Hist* histoireGeneree):GenHistoire (histoireGeneree)
{

}

 void GenHistSkaven::GenererFonctionsCallback()
{
    //m_HistoireGeneree->m_CallbackFunctions["appliquerCmdts"] = &appliquerCmdts;
}

Hist* GenHistSkaven::GenererHistoire()
{
    GenererPersos();

    GenererFonctionsCallback();

    GenererEvtsAccueil();

    return m_HistoireGeneree;
}

UniversSkaven* GenHistSkaven::GetUniversSkaven()
{
    return static_cast<UniversSkaven*>(Univers::ME);
}

void GenHistSkaven::GenererPersos()
{
    QString nom = GetUniversSkaven()->GenererNomSkaven();
    DPerso* perso = new DPerso("heros", nom, nom, ":/images/skaven01.png");
    IPerso::AjouterPersoJouable(perso);
}

void GenHistSkaven::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Sélection du héros et de l'aventure");
    Effet* intro =this->m_GenerateurEvt->AjouterEffetNarration( "Choisissez votre personnage");

}
