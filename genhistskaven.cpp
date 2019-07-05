#include "genhistskaven.h"
#include "universskaven.h"
#include "dpersoskaven.h"
#include "profession.h"
#include "../destinLib/gestionnairecarac.h"

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
    GestionnaireCarac::GetGestionnaireCarac()->m_Caracs.push_back(carac);

    Carac* caracTaille = new Carac(UniversSkaven::CARAC_TAILLE,
                             UniversSkaven::CARAC_TAILLE,
                             "nom invalide",
                             "en cm",
                             "",
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->m_Caracs.push_back(caracTaille);
}

UniversSkaven* GenHistSkaven::GetUniversSkaven()
{
    return static_cast<UniversSkaven*>(Univers::ME);
}

void GenHistSkaven::GenererPersos()
{
    QString nom = this->GetUniversSkaven()->GenererNomSkaven();
    DPersoSkaven* perso = new DPersoSkaven(nom, nom, nom, "");
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

UniversSkaven* GetUniversSkaven()
{
    return static_cast<UniversSkaven*>(Univers::ME);
}

void GenererTexteNaissance()
{
    Lieu* lieu = GetUniversSkaven()->GetLieu(GestionnaireCarac::GetCaracValue(UniversSkaven::CARAC_LIEU));
    Clan* clan = GetUniversSkaven()->GetClanViaBanniere(GestionnaireCarac::GetCaracValue(UniversSkaven::CARAC_CLAN));
    QString lieu_description = lieu->m_Description;
    if ( lieu_description == lieu->m_Nom)
        lieu_description = "";

    QString clan_texte = clan->m_Description;
    if (clan_texte == "" || clan->m_Description == clan->m_Nom )
        clan_texte = "Vous faites partie du clan " + clan->m_Nom;

    QString texte = "Vous êtes nés dans le terrier de " +
            lieu->m_Nom + ". " +
            lieu_description +
            clan_texte + "\n\n";


    int taille = 90 + (qrand()%10)*10 + qrand()%10;

    QString fourrure = GestionnaireCarac::GetCaracValue(UniversSkaven::CARAC_FOURRURE);
    texte += "Votre fourrure est " + fourrure + ".";
    if ( fourrure == "Gris et cornu" )
        texte += " Vos cornes et votre fourrure grise sont le signe de la marque du rat cornu. Vous êtes promis à un brillant avenir loin au dessus de la piétaille qui vous entourait lors de votre naissance.";
    if ( fourrure == "Blanche" )
        texte += " C'est le signe des maîtres et des magiciens. Vos frères ont toujours senti confusément que vous leur étiez supérieur. Il est temps de l'assumer et de les écraser de votre talent exceptionnel.";
    if ( fourrure == "Noire" ) {
        texte += " C'est le signe des tueurs. Vous êtes promis à un avenir glorieux et sanglant.";
        taille += 30;
    }

    GestionnaireCarac::SetValeurACaracId(UniversSkaven::CARAC_TAILLE, QString::number(taille));
    texte += ("\nVous mesurez " + QString::number(taille) + "cm. ");
    if ( taille >= 170 ) {
        texte += "C'est une très grande taille qui vous aidera assurément à arriver à vos fins.";
    } else if ( taille < 130 ) {
        texte += "Il va être dur de vous faire respecter.";
    }

    texte += "\n\nVous approchez de votre 5ème année. Bientôt un adulte. Beaucoup de vos frères n'ont pas survécu jusque là. Qu'ils soient morts de maladie, de faim, ou juste dévorés par d'autres skavens, ils n'étaient sans doute pas dignes de survivre. Vous par contre avez été assez vigoureux pour téter jusqu'à atteindre une taille qui vous met presque à l'abri des gloutons. Une remarquable carrière vous attend ! Qui sait ? Peut-être que bientôt vous serez un des seigneurs de la ruine et mènerez votre peuple à l'assaut des peuples de la surface.";

    Univers::ME->GetExecHistoire()->EffetActuel()->m_Text = texte;
}

void GenHistSkaven::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Sélection du héros et de l'aventure");
    GenererEffetSelectionClan();
    GenererEffetSelectionLieu();
    GenererEffetSelectionFourrure();
    GenererEffetSelectionMetier();
    this->m_GenerateurEvt->AjouterEffetCallbackDisplay( &GenererTexteNaissance);

    this->m_GenerateurEvt->AjouterEffetNarration( "heu rien du tout");
}
