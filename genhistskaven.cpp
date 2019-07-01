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
    GetUniversSkaven()->GenererTousLesLieux();

    Carac* carac = new Carac(UniversSkaven::CARAC_FOURRURE,
                             UniversSkaven::CARAC_FOURRURE,
                             "nom invalide",
                             "Couleur de fourrure et signes particuliers",
                             "",
                             MODE_AFFICHAGE::ma_Texte);
    Univers::ME->GetHistoire()->m_Caracs.push_back(carac);
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
                    UniversSkaven::CARAC_CLAN, clan->m_CheminBanniere);

        NoeudProbable* noeudClanProbable = new NoeudProbable(noeudClan, new Condition(1.0));

        clansPossibles.push_back(noeudClanProbable);
    }

    return this->m_GenerateurEvt->AjouterEffetSelecteurDEvt(clansPossibles);
}

Effet* GenHistSkaven::GenererEffetSelectionFourrure()
{
    QVector<NoeudProbable*> fourruresPossibles = {};

    auto creerSelectionFourrure = [&fourruresPossibles, this](QString couleurFourrure, double proba) {
            Noeud* noeudClan = this->m_GenerateurEvt->GenererNoeudModificateurCarac(
                        UniversSkaven::CARAC_FOURRURE, couleurFourrure);
            NoeudProbable* noeudLieuProbable = new NoeudProbable(noeudClan, new Condition(proba));
            fourruresPossibles.push_back(noeudLieuProbable);
    };
    creerSelectionFourrure("Gris et cornu", 0.001);
    creerSelectionFourrure("Blanche", 0.0001);
    creerSelectionFourrure("Noire", 0.01);
    creerSelectionFourrure("Brune", 0.5);
    creerSelectionFourrure("Tachetée", 0.5);

    return this->m_GenerateurEvt->AjouterEffetSelecteurDEvt(fourruresPossibles);
}

Effet* GenHistSkaven::GenererEffetSelectionLieu()
{
    QVector<NoeudProbable*> lieuxPossibles = {};
    for (int i=0; i < GetUniversSkaven()->m_TousLesLieux.length() ; ++i) {
        Lieu* lieu = GetUniversSkaven()->m_TousLesLieux[i];

        Noeud* noeudClan = this->m_GenerateurEvt->GenererNoeudModificateurCarac(
                    UniversSkaven::CARAC_LIEU, lieu->m_Nom);

        NoeudProbable* noeudLieuProbable = new NoeudProbable(noeudClan, lieu->m_PoidsProba);

        lieuxPossibles.push_back(noeudLieuProbable);
    }

    return this->m_GenerateurEvt->AjouterEffetSelecteurDEvt(lieuxPossibles);
}

void GenHistSkaven::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Sélection du héros et de l'aventure");
    // bon y'a un problème à sélectionner le métier comme ça : faut remettre à jour l'image mais bon on verra plus tard
    //this->m_GenerateurEvt->AjouterEffetNarration( "Le prochain effet va re-sélectionner votre métier");
    GenererEffetSelectionClan();
    GenererEffetSelectionLieu();
    GenererEffetSelectionFourrure();
    GenererEffetSelectionMetier();
    this->m_GenerateurEvt->AjouterEffetNarration( "Initilisation du métier et du clan finis");
    // attention déterminer l'effet final pour pas se défiler tous les effets
}
