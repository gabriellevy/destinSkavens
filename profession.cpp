#include "profession.h"
#include <QTime>

Profession::Profession(TypeProfession typeProfession)
{
    m_TypeProfession = typeProfession;
    m_Nom = Profession::GetNomProfession(typeProfession);

    switch (m_TypeProfession) {
    case TypeProfession::Cultivateur_de_champignons : {
        m_StatutSocial = 0;
        m_Description = "";
        m_PoidsProba = new Condition(0.25, p_Relative);
    }break;
    case TypeProfession::Batisseur_de_taudis : {
        m_StatutSocial = 0;
        m_Description = "";
        m_PoidsProba = new Condition(0.15, p_Relative);
    }break;
    case TypeProfession::Mineur : {
        m_StatutSocial = 0;
        m_Description = "";
        m_PoidsProba = new Condition(0.25, p_Relative);
    }break;
    case TypeProfession::Gardien_de_nourissons : {
        m_StatutSocial = 5;
        m_Description = "";
        m_PoidsProba = new Condition(0.005, p_Relative);
    }break;
    case TypeProfession::Recolteur_de_nourriture_des_marais : {
        m_StatutSocial = 0;
        m_Description = "";
        m_PoidsProba = new Condition(0.1, p_Relative);
    }break;
    case TypeProfession::Docker : {
        m_StatutSocial = 0;
       m_Description = "";
       m_PoidsProba = new Condition(0.02, p_Relative);
    }break;
    case TypeProfession::Servant_de_machine_Skyre : {
        m_StatutSocial = 40;
       m_Description = "";
       m_PoidsProba = new Condition(0.02, p_Relative);
    }break;
    case TypeProfession::Garde_d_esclave : {
        m_StatutSocial = 60;
       m_Description = "";
       m_PoidsProba = new Condition(0.008, p_Relative);
    }break;
    case TypeProfession::Entreteneur_de_galerie : {
        m_StatutSocial = 0;
       m_Description = "";
       m_PoidsProba = new Condition(0.1, p_Relative);
    }break;
    case TypeProfession::Espion_chez_les_autres_clans_skavens : {
        m_StatutSocial = 100;
       m_Description = "";
       m_PoidsProba = new Condition(0.0005, p_Relative);
    }break;
    case TypeProfession::Espion_dans_le_monde_de_la_surface : {
        m_StatutSocial = 120;
       m_Description = "";
       m_PoidsProba = new Condition(0.0002, p_Relative);
    }break;
    case TypeProfession::Preparateur_de_drogues : {
        m_StatutSocial = 90;
       m_Description = "";
       m_PoidsProba = new Condition(0.0002, p_Relative);
    }break;
    case TypeProfession::Ingenieur : {
        m_StatutSocial = 180;
       m_Description = "";
       m_PoidsProba = new Condition(0.002, p_Relative);
    }break;
    case TypeProfession::Observateur_et_chasseur_de_malepierre : {
        m_StatutSocial = 90;
       m_Description = "";
       m_PoidsProba = new Condition(0.002, p_Relative);
    }break;
    case TypeProfession::Raffineur_de_malepierre : {
        m_StatutSocial = 200;
       m_Description = "";
       m_PoidsProba = new Condition(0.002, p_Relative);
    }break;
    case TypeProfession::Coureur_d_egouts : {
        m_StatutSocial = 90;
       m_Description = "";
       m_PoidsProba = new Condition(0.002, p_Relative);
    }break;
    case TypeProfession::Assassin : {
        m_StatutSocial = 200;
       m_Description = "";
       m_PoidsProba = new Condition(0.002, p_Relative);
    }break;
    case TypeProfession::Vermine_de_choc : {
        m_StatutSocial = 110;
       m_Description = "";
       m_PoidsProba = new Condition(0.01, p_Relative);
    }break;
    case TypeProfession::Guerrier_des_clans : {
        m_StatutSocial = 80;
       m_Description = "";
       m_PoidsProba = new Condition(0.09, p_Relative);
    }break;
    case TypeProfession::Moine_de_la_peste : {
        m_StatutSocial = 90;
       m_Description = "";
       m_PoidsProba = new Condition(0.01, p_Relative);
    }break;
    case TypeProfession::Pretre_de_la_peste : {
        m_StatutSocial = 180;
       m_Description = "";
       m_PoidsProba = new Condition(0.001, p_Relative);
    }break;
    case TypeProfession::Maitre_corrupteur : {
        m_StatutSocial = 250;
       m_Description = "";
       m_PoidsProba = new Condition(0.001, p_Relative);
    }break;
    case TypeProfession::Chef_de_meute : {
        m_StatutSocial = 140;
       m_Description = "";
       m_PoidsProba = new Condition(0.005, p_Relative);
    }break;
    case TypeProfession::Technomage : {
        m_StatutSocial = 240;
       m_Description = "";
       m_PoidsProba = new Condition(0.001, p_Relative);
    }break;
    case TypeProfession::Prophete_gris : {
        m_StatutSocial = 600;
       m_Description = "";
       m_PoidsProba = new Condition(0.00001, p_Relative);
    }break;
    case TypeProfession::NombreTotal : {

    }break;

    }

    if ( m_PoidsProba == nullptr)
        m_PoidsProba = new Condition(0.0002, p_Relative);

    if ( m_Description == "" )
        m_Description = m_Nom;


}


QString Profession::GetNomProfession(TypeProfession typeProfession)
{
    switch (typeProfession) {
    case TypeProfession::Cultivateur_de_champignons : return "Cultivateur de champignons";
    case TypeProfession::Batisseur_de_taudis : return "Bâtisseur de taudis";
    case TypeProfession::Mineur : return "Mineur";
    case TypeProfession::Gardien_de_nourissons : return "Gardien de nourissons";
    case TypeProfession::Recolteur_de_nourriture_des_marais : return "Récolteur de nourriture des marais";
    case TypeProfession::Docker : return "Docker";
    case TypeProfession::Servant_de_machine_Skyre : return "Servant de machine Skyre";
    case TypeProfession::Garde_d_esclave : return "Garde d'esclave";
    case TypeProfession::Entreteneur_de_galerie : return "Entreteneur de galerie";
    case TypeProfession::Espion_chez_les_autres_clans_skavens : return "Espion";
    case TypeProfession::Espion_dans_le_monde_de_la_surface : return "Espion en surface";
    case TypeProfession::Preparateur_de_drogues : return "Préparateur de drogues";
    case TypeProfession::Ingenieur : return "Ingénieur";
    case TypeProfession::Observateur_et_chasseur_de_malepierre : return "Observateur et récolteur de malepierre";
    case TypeProfession::Raffineur_de_malepierre : return "Raffineur de malepierre";
    case TypeProfession::Coureur_d_egouts : return "Coureur d'égoûts";
    case TypeProfession::Assassin : return "Assassin";
    case TypeProfession::Vermine_de_choc : return "Vermine de choc";
    case TypeProfession::Guerrier_des_clans : return "Guerrier des clans";
    case TypeProfession::Moine_de_la_peste : return "Moine de la peste";
    case TypeProfession::Pretre_de_la_peste : return "Prêtre de la peste";
    case TypeProfession::Maitre_corrupteur : return "Maître corrupteur";
    case TypeProfession::Chef_de_meute : return "Chef de meute";
    case TypeProfession::Technomage : return "Technomage";
    case TypeProfession::Prophete_gris : return "Prophète gris";
    case TypeProfession::NombreTotal : break;;
    }
    Q_ASSERT(true);
}
