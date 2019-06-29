#include "lieu.h"
#include <QTime>

Lieu::Lieu(TypeLieu typeLieu):m_TypeLieu(typeLieu)
{
    switch (m_TypeLieu) {
    case TypeLieu::Skarogne: {
        m_Nom = "Skarogne";
        m_Description = "";
        m_PoidsProba = new Condition(0.1);
    } break;
    case TypeLieu::Malefosse: {
        m_Nom = "Malefosse";
        m_Description = "";
        m_PoidsProba = new Condition(0.2);
    } break;
    case TypeLieu::Gouffre_Noir: {
        m_Nom = "Moine de la peste";
        m_Description = "";
        m_PoidsProba = new Condition(0.002);
    } break;
    case TypeLieu::Le_Mont_Bossu: {
        m_Nom = "Le mont bossu";
        m_Description = "";
        m_PoidsProba = new Condition(0.002);
    } break;
    case TypeLieu::Sous_Mousillon: {
        m_Nom = "Sous moussillon";
        m_Description = "";
        m_PoidsProba = new Condition(0.002);
    } break;
    case TypeLieu::Sous_Altdorf: {
        m_Nom = "Sous Altdorf";
        m_Description = "";
        m_PoidsProba = new Condition(0.01);
    } break;
    case TypeLieu::Sous_Delbertz: {
        m_Nom = "Sous Delbertz";
        m_Description = "";
        m_PoidsProba = new Condition(0.001);
    } break;
    case TypeLieu::Sous_Middenheim: {
        m_Nom = "Sous Middenheim";
        m_Description = "";
        m_PoidsProba = new Condition(0.001);
    } break;
    case TypeLieu::Fosse_putride: {
        m_Nom = "Fosse putride";
        m_Description = "";
        m_PoidsProba = new Condition(0.001);
    } break;
    case TypeLieu::Mont_Purulent: {
        m_Nom = "Mont purulent";
        m_Description = "";
        m_PoidsProba = new Condition(0.001);
    } break;
    case TypeLieu::Pic_Fetide: {
        m_Nom = "Pic fétide";
        m_Description = "Le Pic Fétide est un des trois repaires Skavens qui occupent une position centrale dans les Voûtes. Cette tanière abrite un nombre assez important de Prophètes Gris, ainsi que des clans inféodés au Clan Skryre.";
        m_PoidsProba = new Condition(0.01);
    } break;
    case TypeLieu::Fosse_Bilieuse: {
        m_Nom = "Fosse bilieuse";
        m_Description = "Ce repaire du clan Scruten se trouve dans les Marais putrides près de Marienburg";
        m_PoidsProba = new Condition(0.05);
    } break;
    case TypeLieu::Puits_du_Queekz: {
        m_Nom = "Puit de Queekz";
        m_Description = "";
        m_PoidsProba = new Condition(0.01);
    } break;
    case TypeLieu::Sous_la_Lustrie: {
        m_Nom = "Sous la Lustrie";
        m_Description = "";
        m_PoidsProba = new Condition(0.3);
    } break;
    case TypeLieu::Sous_empire: {
        m_Nom = "Sous l'empire";
        m_Description = "";
        m_PoidsProba = new Condition(0.3);
    } break;
    case TypeLieu::Sous_Bretonnie: {
        m_Nom = "Sous la bretonnie";
        m_Description = "";
        m_PoidsProba = new Condition(0.1);
    } break;
    case TypeLieu::Sous_estalie: {
        m_Nom = "Sous l'Estalie";
        m_Description = "";
        m_PoidsProba = new Condition(0.08);
    } break;
    case TypeLieu::Sous_Tilee: {
        m_Nom = "Sous la Tilée";
        m_Description = "";
        m_PoidsProba = new Condition(0.08);
    } break;
    case TypeLieu::Sous_Arabie: {
        m_Nom = "Sous l'Arabie";
        m_Description = "";
        m_PoidsProba = new Condition(0.01);
    } break;
    case TypeLieu::Sous_Terres_sombres: {
        m_Nom = "Sous les terres sombres";
        m_Description = "";
        m_PoidsProba = new Condition(0.01);
    } break;
    case TypeLieu::Sous_les_terres_du_Sud: {
        m_Nom = "Sous les terres du Sud";
        m_Description = "";
        m_PoidsProba = new Condition(0.01);
    } break;
    case TypeLieu::Sous_Cathay: {
        m_Nom = "Sous Cathay";
        m_Description = "";
        m_PoidsProba = new Condition(0.005);
    } break;
    case TypeLieu::Sous_Naggaroth: {
        m_Nom = "Sous Naggaroth";
        m_Description = "";
        m_PoidsProba = new Condition(0.01);
    } break;
    case TypeLieu::Cite_des_Piliers: {
        m_Nom = "Cité des piliers";
        m_Description = "Anciennent la puissante forteresse naine Karak aux Huit Pics cette tannière est celle du clan Mors qui l'a conquise de haute lutte contre les nains et les peaux vertes.";
        m_PoidsProba = new Condition(0.01);
    } break;
    default:
        break;
    }

    if ( m_PoidsProba == nullptr)
        m_PoidsProba = new Condition(0.0002);

    if ( m_Description == "" )
        m_Description = m_Nom;

}
