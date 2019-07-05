#include "universskaven.h"
#include "ui_univers.h"
#include <QTime>

UniversSkaven::UniversSkaven(ModeAffichage modeAffichage,
                         QWidget *parent)
    : Univers(parent, modeAffichage)
{
    this->AppliquerTheme(QColor(54, 46, 43));

    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));
}

QString UniversSkaven::CARAC_CLAN = "Clan";
QString UniversSkaven::CARAC_PROF = "Profession";
QString UniversSkaven::CARAC_LIEU = "Lieu";
QString UniversSkaven::CARAC_FOURRURE = "Fourrure";
QString UniversSkaven::CARAC_TAILLE = "Taille";

Hist* UniversSkaven::ExecuterGenerateurHistoire()
{
    m_Histoire = new Hist("Vie de Skaven");
    m_GenHistoire = new GenHistSkaven(m_Histoire);
    m_GenHistoire->GenererHistoire();
    this->setWindowTitle(m_Histoire->m_Titre);

    return m_Histoire;
}

void UniversSkaven::GenererProfession(TypeProfession typeProfession)
{
    Profession* profession = new Profession(typeProfession);
    m_TousLesProfessions.push_back(profession);
}

void UniversSkaven::GenererLieu(TypeLieu typeLieu)
{
    Lieu* lieu = new Lieu(typeLieu);
    m_TousLesLieux.push_back(lieu);
}

void UniversSkaven::GenererClan(TypeClan typeClan, QString nom, float puissance, QString description, QString chemin)
{
    if ( description == "")
        description = nom;
    Clan* clan = new Clan(typeClan, nom, puissance, description, chemin);
    m_TousLesClans.push_back(clan);
}

void UniversSkaven::GenererTousLesLieux()
{
    int nb = static_cast<int>(TypeLieu::NombreTotal);
    for (int i = 0; i < nb ; ++i) {
        this->GenererLieu(static_cast<TypeLieu>(i));
    }
}

Profession* UniversSkaven::GetProfession(QString idProfession)
{
    for ( int i = 0 ; i < m_TousLesProfessions.length() ; ++i) {
        if ( m_TousLesProfessions[i]->m_Nom == idProfession)
            return m_TousLesProfessions[i];
    }
    QString msg = "Profession introuvable : " + idProfession ;
    Q_ASSERT_X(true, msg.toStdString().c_str(), "UniversSkaven::GetProfession");
    return nullptr;
}

Lieu* UniversSkaven::GetLieu(QString idLieu)
{
    for ( int i = 0 ; i < m_TousLesLieux.length() ; ++i) {
        if ( m_TousLesLieux[i]->m_Nom == idLieu)
            return m_TousLesLieux[i];
    }
    QString msg = "Lieu introuvable : " + idLieu ;
    Q_ASSERT_X(true, msg.toStdString().c_str(), "UniversSkaven::GetLieu");
    return nullptr;
}

Clan* UniversSkaven::GetClanViaBanniere(QString banniere)
{
    for ( int i = 0 ; i < m_TousLesClans.length() ; ++i) {
        if ( m_TousLesClans[i]->m_CheminBanniere == banniere)
            return m_TousLesClans[i];
    }
    QString msg = "Clan introuvable de cette bannière : " + banniere ;
    Q_ASSERT_X(true, msg.toStdString().c_str(), "UniversSkaven::GetClanViaBanniere");
    return nullptr;
}

Clan* UniversSkaven::GetClan(QString idClan)
{
    for ( int i = 0 ; i < m_TousLesClans.length() ; ++i) {
        if ( m_TousLesClans[i]->m_Nom == idClan)
            return m_TousLesClans[i];
    }
    QString msg = "Clan introuvable : " + idClan ;
    Q_ASSERT_X(true, msg.toStdString().c_str(), "UniversSkaven::GetClan");
    return nullptr;
}

void UniversSkaven::GenererToutesLesProfessions()
{
    this->GenererProfession(TypeProfession::Cultivateur_de_champignons);
    this->GenererProfession(TypeProfession::Batisseur_de_taudis);
    this->GenererProfession(TypeProfession::Mineur);
    this->GenererProfession(TypeProfession::Gardien_de_nourissons);
    this->GenererProfession(TypeProfession::Recolteur_de_nourriture_des_marais);
    this->GenererProfession(TypeProfession::Docker);
    this->GenererProfession(TypeProfession::Servant_de_machine_Skyre);
    this->GenererProfession(TypeProfession::Garde_d_esclave);
    this->GenererProfession(TypeProfession::Entreteneur_de_galerie);
    this->GenererProfession(TypeProfession::Espion_chez_les_autres_clans_skavens);
    this->GenererProfession(TypeProfession::Espion_dans_le_monde_de_la_surface);
    this->GenererProfession(TypeProfession::Preparateur_de_drogues);
    this->GenererProfession(TypeProfession::Ingenieur);
    this->GenererProfession(TypeProfession::Observateur_et_chasseur_de_malepierre);
    this->GenererProfession(TypeProfession::Raffineur_de_malepierre);
    this->GenererProfession(TypeProfession::Coureur_d_egouts);
    this->GenererProfession(TypeProfession::Assassin);
    this->GenererProfession(TypeProfession::Vermine_de_choc);
    this->GenererProfession(TypeProfession::Guerrier_des_clans);
    this->GenererProfession(TypeProfession::Moine_de_la_peste);
    this->GenererProfession(TypeProfession::Pretre_de_la_peste);
    this->GenererProfession(TypeProfession::Maitre_corrupteur);
    this->GenererProfession(TypeProfession::Chef_de_meute);
    this->GenererProfession(TypeProfession::Technomage);
    this->GenererProfession(TypeProfession::Prophete_gris);
}

void UniversSkaven::GenererTousLesClans()
{
    this->GenererClan(TypeClan::Rictus,
                      "Rictus",
                      400.0f,
                      "Le Mont Bossu est actuellement sous la coupe du Seigneur Kratch, chef de l’un des Clans Guerriers les plus importants.",
                      ":/images/clans/Rictus.jpg");
    this->GenererClan(TypeClan::Mors,
                      "Mors",
                      800.0f,
                      "",
                      ":/images/clans/Mors.jpg");
    this->GenererClan(TypeClan::Skab,
                      "Skab",
                      450.0f,
                      "",
                      ":/images/clans/Skab.png");
    this->GenererClan(TypeClan::Pestilens,
                      "Pestilens",
                      900.0f,
                      "",
                      ":/images/clans/Pestilens.png");
    this->GenererClan(TypeClan::Septik,
                      "Septik",
                      200.0f,
                      "",
                      ":/images/clans/Septik.jpg");
    this->GenererClan(TypeClan::Skrat,
                      "Skrat",
                      200.0f,
                      "",
                      ":/images/clans/Skrat.jpg");
    this->GenererClan(TypeClan::Gratzz,
                      "Gratzz",
                      200.0f,
                      "",
                      ":/images/clans/Gratzz.jpg");
    this->GenererClan(TypeClan::Morbidus,
                      "Morbidus",
                      200.0f,
                      "",
                      ":/images/clans/Morbidus.png");
    this->GenererClan(TypeClan::Scorbut,
                      "Scorbut",
                      200.0f,
                      "",
                      ":/images/clans/Scorbut.jpg");
    this->GenererClan(TypeClan::Krizzor,
                      "Krizzor",
                      200.0f,
                      "",
                      ":/images/clans/Krizzor.jpg");
    this->GenererClan(TypeClan::Liskit,
                      "Liskit",
                      200.0f,
                      "",
                      ":/images/clans/Liskit.jpg");
    this->GenererClan(TypeClan::Festus,
                      "Festus",
                      200.0f,
                      "",
                      ":/images/clans/Festus.jpg");
    this->GenererClan(TypeClan::Raklur,
                      "Raklur",
                      200.0f,
                      "",
                      ":/images/clans/Raklur.jpg");
    this->GenererClan(TypeClan::Eshin,
                      "Eshin",
                      900.0f,
                      "",
                      ":/images/clans/Eshin.png");
    this->GenererClan(TypeClan::Moulder,
                      "Moulder",
                      900.0f,
                      "",
                      ":/images/clans/Moulder.jpg");
    this->GenererClan(TypeClan::Skyre,
                      "Skyre",
                      1000.0f,
                      "",
                      ":/images/clans/Skyre.png");
    this->GenererClan(TypeClan::Mordkin,
                      "Mordkin",
                      150.0f,
                      "",
                      ":/images/clans/Mordkin.png");
    this->GenererClan(TypeClan::Grutnik,
                      "Grutnik",
                      150.0f,
                      "",
                      ":/images/clans/Grutnik.png");
    this->GenererClan(TypeClan::Volkn,
                      "Volkn",
                      200.0f,
                      "",
                      ":/images/clans/Volkn.jpg");
}

Clan* UniversSkaven::ChoisirClan()
{
    return m_TousLesClans[rand() % m_TousLesClans.length()];
}

Profession* UniversSkaven::ChoisirProfession()
{
    return m_TousLesProfessions[rand() % m_TousLesProfessions.length()];
}

QString UniversSkaven::GenererNomSkaven()
{
    QStringList noms = {
        "Thramute", "Ekritch", "Queek", "Throt", "Morlocke", "Churft", "Skitice", "Kritislik", "Morskittar",
        "Yuatek", "Sneek", "Skrittar", "Kritislik", "Paskrit", "Throt", "Izak", "Griskit" , "Ghoritch", "Scarskrex",
        "Skrit", "Ikit", "Snikkit", "Skabbicus", "Snarlock", "tran bristlespire", "strut stonebone", "qhronq nightcrusher",
        "stulk bristlechest", "crilk darkweaver", "ven cravenborn", "viknut featherwalker", "steqzik blackfinger", "toshuekch clawmaul"
        "uonqroch"
    };
    return noms[rand() % noms.length()];
}
