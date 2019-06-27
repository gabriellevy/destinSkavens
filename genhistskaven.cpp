#include "genhistskaven.h"
#include "universskaven.h"
#include "dpersoskaven.h"
#include "profession.h"

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

    GenererCaracs();

    GenererEvtsAccueil();

    return m_HistoireGeneree;
}

void GenHistSkaven::GenererCaracs()
{
    GetUniversSkaven()->GenererTousLesClans();
    GetUniversSkaven()->GenererToutesLesProfessions();
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

Effet* GenHistSkaven::GenererEffetSelectionMetier()
{
    QVector<NoeudProbable*> metiersPossibles = {};
    for (int i=0; i < GetUniversSkaven()->m_TousLesProfessions.length() ; ++i) {
        Profession* profession = GetUniversSkaven()->m_TousLesProfessions[i];

        Noeud* noeudMetier = this->m_GenerateurEvt->GenererNoeudModificateurCarac(
                    UniversSkaven::CARAC_PROF, profession->m_Nom);

        NoeudProbable* noeudMetierProbable = new NoeudProbable(noeudMetier, profession->m_PoidsProba);

        metiersPossibles.push_back(noeudMetierProbable);
    }

    return this->m_GenerateurEvt->AjouterEffetSelecteurDEvt(metiersPossibles);
}

Effet* GenHistSkaven::GenererEffetSelectionClan()
{
    QVector<NoeudProbable*> clansPossibles = {};
    for (int i=0; i < GetUniversSkaven()->m_TousLesClans.length() ; ++i) {
        Clan* clan = GetUniversSkaven()->m_TousLesClans[i];

        Noeud* noeudClan = this->m_GenerateurEvt->GenererNoeudModificateurCarac(
                    UniversSkaven::CARAC_CLAN, clan->m_Nom);

        NoeudProbable* noeudClanProbable = new NoeudProbable(noeudClan, new Condition(1.0f));

        clansPossibles.push_back(noeudClanProbable);
    }

    return this->m_GenerateurEvt->AjouterEffetSelecteurDEvt(clansPossibles);
}

void GenHistSkaven::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Sélection du héros et de l'aventure");
    // bon y'a un problème à sélectionner le métier comme ça : faut remettre à jour l'image mais bon on verra plus tard
    //this->m_GenerateurEvt->AjouterEffetNarration( "Le prochain effet va re-sélectionner votre métier");
    GenererEffetSelectionClan();
    GenererEffetSelectionMetier();
    this->m_GenerateurEvt->AjouterEffetNarration( "Initilisation du métier et du clan finis");
    // attention déterminer l'effet final pour pas se défiler tous les effets
}
