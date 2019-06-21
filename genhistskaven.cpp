#include "genhistskaven.h"
#include "../destinLib/perso.h"

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

void GenHistSkaven::GenererPersos()
{
    DPerso* reveur = new DPerso("reveur", "Rêveur");
    IPerso::AjouterPersoJouable(reveur);
}

void GenHistSkaven::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Sélection du héros et de l'aventure");
    Effet* intro =this->m_GenerateurEvt->AjouterEffetNarration( "Choisissez votre personnage");

}
