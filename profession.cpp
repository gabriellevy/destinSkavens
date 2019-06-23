#include "profession.h"
#include <QTime>

Profession::Profession()
{
    // le vrai random devra être via les proba :
    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));

    int val = rand() % static_cast<int>(TypeProfession::NombreTotal);

    m_TypeProfession = static_cast<TypeProfession>(val);

    switch (m_TypeProfession) {
    case TypeProfession::Cultivateur_de_champignons : {
        m_StatutSocial = 0;
    }break;
    case TypeProfession::Batisseur_de_taudis : {
        m_StatutSocial = 0;
    }break;
    case TypeProfession::Mineur : {
        m_StatutSocial = 0;
    }break;
    case TypeProfession::Gardien_de_nourissons : {
        m_StatutSocial = 5;
    }break;
    case TypeProfession::Recolteur_de_nourriture_des_marais : {
        m_StatutSocial = 0;
    }break;
    case TypeProfession::Docker : {
        m_StatutSocial = 0;
    }break;
    case TypeProfession::Servant_de_machine_Skyre : {
        m_StatutSocial = 40;
    }break;
    case TypeProfession::Garde_d_esclave : {
        m_StatutSocial = 60;
    }break;
    case TypeProfession::Entreteneur_de_galerie : {
        m_StatutSocial = 0;
    }break;
    case TypeProfession::Espion_chez_les_autres_clans_skavens : {
        m_StatutSocial = 100;
    }break;
    case TypeProfession::Espion_dans_le_monde_de_la_surface : {
        m_StatutSocial = 120;
    }break;
    case TypeProfession::Preparateur_de_drogues : {
        m_StatutSocial = 90;
    }break;
    case TypeProfession::Ingenieur : {
        m_StatutSocial = 180;
    }break;
    case TypeProfession::Observateur_et_chasseur_de_malepierre : {
        m_StatutSocial = 90;
    }break;
    case TypeProfession::Raffineur_de_malepierre : {
        m_StatutSocial = 200;
    }break;
    case TypeProfession::Coureur_d_egouts : {
        m_StatutSocial = 90;
    }break;
    case TypeProfession::Assassin : {
        m_StatutSocial = 200;
    }break;
    case TypeProfession::Vermine_de_choc : {
        m_StatutSocial = 110;
    }break;
    case TypeProfession::Guerrier_des_clans : {
        m_StatutSocial = 80;
    }break;
    case TypeProfession::Moine_de_la_peste : {
        m_StatutSocial = 90;
    }break;
    case TypeProfession::Pretre_de_la_peste : {
        m_StatutSocial = 180;
    }break;
    case TypeProfession::Maitre_corrupteur : {
        m_StatutSocial = 250;
    }break;
    case TypeProfession::Chef_de_meute : {
        m_StatutSocial = 140;
    }break;
    case TypeProfession::Technomage : {
        m_StatutSocial = 240;
    }break;
    case TypeProfession::Prophete_gris : {
        m_StatutSocial = 600;
    }break;
    case TypeProfession::NombreTotal : {

    }break;

    }


}
