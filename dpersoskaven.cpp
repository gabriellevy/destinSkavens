#include "dpersoskaven.h"
#include "universskaven.h"
#include "clan.h"
#include "profession.h"
#include "lieu.h"
#include "../destinLib/carac.h"
#include "../destinLib/gestionnairecarac.h"
#include <QTime>

DPersoSkaven* DPersoSkaven::ME = nullptr;

DPersoSkaven::DPersoSkaven(QString id, QString nom, QString description, QString CheminImagePortrait)
    :DPerso(id, nom, description, CheminImagePortrait)
{
    DPersoSkaven::ME = this;

    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));
}

DPersoSkaven* DPersoSkaven::GetSkaven()
{
    if ( DPersoSkaven::ME == nullptr )
        DPersoSkaven::ME = new DPersoSkaven("inconnu ??", "inconnu ??", "", "");
    return ME;
}

void DPersoSkaven::InitialiserPerso()
{
    // génération aléatoire du perso :
    //this->m_Nom = GetUniversSkaven()->GenererNomSkaven();

    Carac* carac = new Carac(UniversSkaven::CARAC_CLAN,
                             UniversSkaven::CARAC_CLAN,
                             "nom invalide",
                             "",
                             "",
                             MODE_AFFICHAGE::ma_ImgValeur);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(carac);

    Carac* caracProf = new Carac(UniversSkaven::CARAC_PROF,
                             UniversSkaven::CARAC_PROF,
                                 "nom invalide",
                                 "",
                                 "",
                             MODE_AFFICHAGE::ma_Texte);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracProf);

    Carac* caracLieu = new Carac(UniversSkaven::CARAC_LIEU,
                             UniversSkaven::CARAC_LIEU,
                                 "nom invalide",
                                 "",
                                 "",
                             MODE_AFFICHAGE::ma_Texte);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracLieu);

    Carac* caracMalepierre = new Carac(UniversSkaven::CARAC_MALEPIERRE,
                             UniversSkaven::CARAC_MALEPIERRE,
                                 "0",
                                 "",
                                 "grammes de malepierre",
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracMalepierre);

    Carac* caracStatut = new Carac(UniversSkaven::CARAC_STATUT,
                             UniversSkaven::CARAC_STATUT,
                                 "0",
                                 "",
                                 "Statut social parmi les autres skavens",
                             MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracStatut);

    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(
                new Carac(UniversSkaven::CARAC_FOURRURE, UniversSkaven::CARAC_FOURRURE,"",
                   "", UniversSkaven::CARAC_FOURRURE, MODE_AFFICHAGE::ma_Texte, nullptr));
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(
                new Carac(UniversSkaven::CARAC_TAILLE, UniversSkaven::CARAC_TAILLE,"",
                   "", UniversSkaven::CARAC_TAILLE, MODE_AFFICHAGE::ma_Texte, nullptr));

    this->RafraichirAffichage();
}

UniversSkaven* DPersoSkaven::GetUniversSkaven()
{
    return static_cast<UniversSkaven*>(Univers::ME);
}

Profession* DPersoSkaven::GetProfession()
{
    QString idProfession = DPerso::GetValeurCarac(UniversSkaven::CARAC_PROF);
    if ( idProfession == "" )
        return nullptr;
    return GetUniversSkaven()->GetProfession(idProfession);
}

Lieu* DPersoSkaven::GetLieu()
{
    QString idLieu =  DPerso::GetValeurCarac(UniversSkaven::CARAC_LIEU);
    return GetUniversSkaven()->GetLieu(idLieu);
}

Clan* DPersoSkaven::GetClan()
{
    QString cheminBanniere = DPerso::GetValeurCarac(UniversSkaven::CARAC_CLAN);
    if ( cheminBanniere == "")
        return nullptr;
    return GetUniversSkaven()->GetClanViaBanniere(cheminBanniere);
}

void DPersoSkaven::RafraichirAffichage()
{
    QString CheminImagePortrait = "";
    if ( this->GetProfession() == nullptr )
        return;
    // image spécial selon le métier
    switch (this->GetProfession()->m_TypeProfession) {
    case TypeProfession::Guerrier_des_clans :
    {
        QStringList chemins = {
            ":/images/portraits/guerrier01.jpg",
            ":/images/portraits/guerrier02.jpg",
            ":/images/portraits/guerrier03.jpg",
            ":/images/portraits/guerrier04.jpg",
            ":/images/portraits/guerrier05.jpg",
            ":/images/portraits/guerrier06.jpg",
            ":/images/portraits/guerrier07.jpg",
            ":/images/portraits/guerrier08.jpg",
            ":/images/portraits/guerrier09.jpg",
            ":/images/portraits/guerrier10.jpg"
        };
        CheminImagePortrait = chemins[rand() % chemins.length()];
    }break;
    case TypeProfession::Ingenieur :
    case TypeProfession::Technomage :{
        QStringList chemins = {
            ":/images/portraits/ingénieur01.jpg",
            ":/images/portraits/ingénieur02.jpg",
            ":/images/portraits/ingénieur03.jpg"
        };
        CheminImagePortrait = chemins[rand() % chemins.length()];
    }break;
    case TypeProfession::Moine_de_la_peste :
    case TypeProfession::Pretre_de_la_peste :{
        QStringList chemins = {
            ":/images/portraits/peste01.jpg",
            ":/images/portraits/peste02.jpg",
            ":/images/portraits/peste03.jpg"
        };
        CheminImagePortrait = chemins[rand() % chemins.length()];
    }break;
    case TypeProfession::Vermine_de_choc : {
        QStringList chemins = {
            ":/images/portraits/vermine01.jpg",
            ":/images/portraits/vermine02.jpg",
            ":/images/portraits/vermine03.jpg",
            ":/images/portraits/vermine04.jpg"
        };
        CheminImagePortrait = chemins[rand() % chemins.length()];
    }break;
    case TypeProfession::Prophete_gris : {
        QStringList chemins = {
            ":/images/portraits/prophète01.jpg",
            ":/images/portraits/prophète02.jpg",
            ":/images/portraits/prophète03.jpg"
        };
        CheminImagePortrait = chemins[rand() % chemins.length()];
    }break;
    case TypeProfession::Maitre_corrupteur :
    case TypeProfession::Chef_de_meute : {
        QStringList chemins = {
            ":/images/portraits/moulder01.jpg"
        };
        CheminImagePortrait = chemins[rand() % chemins.length()];
    }break;
    case TypeProfession::Espion_dans_le_monde_de_la_surface :
    case TypeProfession::Espion_chez_les_autres_clans_skavens :
    case TypeProfession::Coureur_d_egouts :
    case TypeProfession::Assassin : {
        QStringList chemins = {
            ":/images/portraits/eschin01.jpg",
            ":/images/portraits/eschin02.jpg",
            ":/images/portraits/eschin03.jpg",
            ":/images/portraits/eschin04.jpg",
            ":/images/portraits/eschin05.jpg"
        };
        CheminImagePortrait = chemins[rand() % chemins.length()];
    }break;
    default : break;
    }

    // si aucune alors image spéciale selon le clan :
    if ( CheminImagePortrait == "" )
    {
        switch (this->GetClan()->m_TypeClan) {
        case TypeClan::Eshin : {
            QStringList chemins = {
                ":/images/portraits/eschin01.jpg",
                ":/images/portraits/eschin02.jpg",
                ":/images/portraits/eschin03.jpg",
                ":/images/portraits/eschin04.jpg",
                ":/images/portraits/eschin05.jpg"
            };
            CheminImagePortrait = chemins[rand() % chemins.length()];
        } break;
        case TypeClan::Moulder : {
            QStringList chemins = {
                ":/images/portraits/moulder01.jpg"
            };
            CheminImagePortrait = chemins[rand() % chemins.length()];
        } break;
        case TypeClan::Pestilens : {
            QStringList chemins = {
                ":/images/portraits/peste01.jpg",
                ":/images/portraits/peste02.jpg",
                ":/images/portraits/peste03.jpg"
            };
            CheminImagePortrait = chemins[rand() % chemins.length()];
        } break;

        default :  {

        }break;

        }
    }

    // si toujours aucun alors image skaven de base
    if ( CheminImagePortrait == "" )
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
        CheminImagePortrait = chemins[rand() % chemins.length()];
    }

    MajCheminImage(CheminImagePortrait);

    // mettre à jour la bannière de clan en fonction du clan choisi
    Clan* clan = GetClan();
    if ( clan != nullptr ) {
        Carac* caracClan = GestionnaireCarac::GetGestionnaireCarac()->GetCarac(UniversSkaven::CARAC_CLAN);
        if ( caracClan != nullptr ) {
            caracClan->m_DataCarac.m_Description = clan->m_Description;
            caracClan->SetImg(clan->m_CheminBanniere);
        }
    }

    DPerso::RafraichirAffichage();
}
