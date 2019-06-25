#include "profession.h"
#include <QTime>

Profession::Profession(TypeProfession typeProfession)
{
    // le vrai random devra être via les proba :
    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));

    m_TypeProfession = typeProfession;

    switch (m_TypeProfession) {
    case TypeProfession::Cultivateur_de_champignons : {
        m_StatutSocial = 0;
        m_Nom = "Cultivateur de champignons";
        m_Description = "";
    }break;
    case TypeProfession::Batisseur_de_taudis : {
        m_StatutSocial = 0;
        m_Nom = "Bâtisseur de taudis";
        m_Description = "";
    }break;
    case TypeProfession::Mineur : {
        m_StatutSocial = 0;
        m_Nom = "Mineur";
        m_Description = "";
    }break;
    case TypeProfession::Gardien_de_nourissons : {
        m_StatutSocial = 5;
        m_Nom = "Gardien de nourissons";
        m_Description = "";
    }break;
    case TypeProfession::Recolteur_de_nourriture_des_marais : {
        m_StatutSocial = 0;
        m_Nom = "Récolteur de nourriture des marais";
        m_Description = "";
    }break;
    case TypeProfession::Docker : {
        m_StatutSocial = 0;
       m_Nom = "Docker";
       m_Description = "";
    }break;
    case TypeProfession::Servant_de_machine_Skyre : {
        m_StatutSocial = 40;
       m_Nom = "Servant de machine Skyre";
       m_Description = "";
    }break;
    case TypeProfession::Garde_d_esclave : {
        m_StatutSocial = 60;
       m_Nom = "Garde d'esclave";
       m_Description = "";
    }break;
    case TypeProfession::Entreteneur_de_galerie : {
        m_StatutSocial = 0;
       m_Nom = "Entreteneur de galerie";
       m_Description = "";
    }break;
    case TypeProfession::Espion_chez_les_autres_clans_skavens : {
        m_StatutSocial = 100;
       m_Nom = "Espion chez les autres clans skavens";
       m_Description = "";
    }break;
    case TypeProfession::Espion_dans_le_monde_de_la_surface : {
        m_StatutSocial = 120;
       m_Nom = "Espion dans le monde de la surface";
       m_Description = "";
    }break;
    case TypeProfession::Preparateur_de_drogues : {
        m_StatutSocial = 90;
       m_Nom = "Préparateur de drogues";
       m_Description = "";
    }break;
    case TypeProfession::Ingenieur : {
        m_StatutSocial = 180;
       m_Nom = "Ingénieur";
       m_Description = "";
    }break;
    case TypeProfession::Observateur_et_chasseur_de_malepierre : {
        m_StatutSocial = 90;
       m_Nom = "Observateur et chasseur de malepierre";
       m_Description = "";
    }break;
    case TypeProfession::Raffineur_de_malepierre : {
        m_StatutSocial = 200;
       m_Nom = "Raffineur de malepierre";
       m_Description = "";
    }break;
    case TypeProfession::Coureur_d_egouts : {
        m_StatutSocial = 90;
       m_Nom = "Coureur d’égouts";
       m_Description = "";
    }break;
    case TypeProfession::Assassin : {
        m_StatutSocial = 200;
       m_Nom = "Assassin";
       m_Description = "";
    }break;
    case TypeProfession::Vermine_de_choc : {
        m_StatutSocial = 110;
       m_Nom = "Vermine de choc";
       m_Description = "";
    }break;
    case TypeProfession::Guerrier_des_clans : {
        m_StatutSocial = 80;
       m_Nom = "Guerrier des clans";
       m_Description = "";
    }break;
    case TypeProfession::Moine_de_la_peste : {
        m_StatutSocial = 90;
       m_Nom = "Moine de la peste";
       m_Description = "";
    }break;
    case TypeProfession::Pretre_de_la_peste : {
        m_StatutSocial = 180;
       m_Nom = "Prêtre de la peste";
       m_Description = "";
    }break;
    case TypeProfession::Maitre_corrupteur : {
        m_StatutSocial = 250;
       m_Nom = "Maître corrupteur";
       m_Description = "";
    }break;
    case TypeProfession::Chef_de_meute : {
        m_StatutSocial = 140;
       m_Nom = "Chef de meute";
       m_Description = "";
    }break;
    case TypeProfession::Technomage : {
        m_StatutSocial = 240;
       m_Nom = "Technomage";
       m_Description = "";
    }break;
    case TypeProfession::Prophete_gris : {
        m_StatutSocial = 600;
       m_Nom = "Prophète gris";
       m_Description = "";
    }break;
    case TypeProfession::NombreTotal : {

    }break;

    }


}
