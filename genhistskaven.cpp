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

    GenererEvtsAccueil();

    GenererCaracs();

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

Effet* GenHistSkaven::GenererEffetSelectionMetier(Evt* evt)
{
    QVector<Noeud*> metiersPossibles = {};
    for (int i=0; i < GetUniversSkaven()->m_TousLesProfessions.length() ; ++i) {
        Profession* profession = GetUniversSkaven()->m_TousLesProfessions[i];

        Noeud* noeudMetier = this->m_GenerateurEvt->GenererNoeudModificateurCarac(
                    UniversSkaven::CARAC_PROF, profession->m_Nom, profession->m_Conditions);

        metiersPossibles.push_back(noeudMetier);
    }

    return this->m_GenerateurEvt->AjouterEffetSelecteurDEvt(evt, metiersPossibles,
                                                            "selectionneur d'événement", "on vient de sélectionneur l'événement je crois!");
}

void GenHistSkaven::GenererEvtsAccueil()
{
    Evt* Debut = this->AjouterEvt("Debut", "Sélection du héros et de l'aventure");
    // bon y'a un problème à sélectionner le métier comme ça : faut remettre à jour l'image mais bon on verra plus tard
    this->m_GenerateurEvt->AjouterEffetNarration( "Le prochain effet va re-sélectionner votre métier");
    //Effet* setMetier = GenererEffetSelectionMetier(Debut);
    this->m_GenerateurEvt->AjouterEffetNarration( "Là ça devrait vraiment être fini");
    // attention déterminer l'effet final pour pas se défiler tous les effets
}
