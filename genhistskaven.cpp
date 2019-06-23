#include "genhistskaven.h"
#include "universskaven.h"
#include "dpersoskaven.h"

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
    DPersoSkaven* perso = new DPersoSkaven();
    IPerso::AjouterPersoJouable(perso);
}

void GenHistSkaven::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Sélection du héros et de l'aventure");
    /*Effet* intro =*/this->m_GenerateurEvt->AjouterEffetNarration( "Choisissez votre personnage");

}
