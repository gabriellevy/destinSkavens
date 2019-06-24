#include "universskaven.h"
#include "ui_univers.h"
#include <QTime>

UniversSkaven::UniversSkaven(ModeAffichage modeAffichage,
                         QWidget *parent)
    : Univers(parent, modeAffichage)
{
    this->AppliquerTheme(QColor(180, 180, 210));

    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));
}

QString UniversSkaven::CARAC_CLAN = "Clan";

void UniversSkaven::GenererCaracs()
{
    GenererTousLesClans();
}

Hist* UniversSkaven::ExecuterGenerateurHistoire()
{
    m_Histoire = new Hist("Vie de Skaven");
    m_GenHistoire = new GenHistSkaven(m_Histoire);
    m_GenHistoire->GenererHistoire();
    this->setWindowTitle(m_Histoire->m_Titre);

    this->GenererCaracs();

    return m_Histoire;
}

void UniversSkaven::GenererClan(TypeClan typeClan, QString nom, QString description, QString chemin)
{
    if ( description == "")
        description = "Clan " + nom;
    Clan* clan = new Clan(typeClan, nom, description, chemin);
    m_TousLesClans.push_back(clan);
}

void UniversSkaven::GenererTousLesClans()
{
    this->GenererClan(TypeClan::Rictus,
                      "Rictus",
                      "Le Mont Bossu est actuellement sous la coupe du Seigneur Kratch, chef de l’un des Clans Guerriers les plus importants.",
                      ":/images/clans/Rictus.jpg");
    this->GenererClan(TypeClan::Mors,
                      "Mors",
                      "",
                      ":/images/clans/Mors.jpg");
    this->GenererClan(TypeClan::Skab,
                      "Skab",
                      "",
                      ":/images/clans/Skab.png");
    this->GenererClan(TypeClan::Pestilens,
                      "Pestilens",
                      "",
                      ":/images/clans/Pestilens.png");
    this->GenererClan(TypeClan::Septik,
                      "Septik",
                      "",
                      ":/images/clans/Septik.jpg");
    this->GenererClan(TypeClan::Skrat,
                      "Skrat",
                      "",
                      ":/images/clans/Skrat.jpg");
    this->GenererClan(TypeClan::Gratzz,
                      "Gratzz",
                      "",
                      ":/images/clans/Gratzz.jpg");
    this->GenererClan(TypeClan::Morbidus,
                      "Morbidus",
                      "",
                      ":/images/clans/Morbidus.png");
    this->GenererClan(TypeClan::Scorbut,
                      "Scorbut",
                      "",
                      ":/images/clans/Scorbut.jpg");
    this->GenererClan(TypeClan::Krizzor,
                      "Krizzor",
                      "",
                      ":/images/clans/Krizzor.jpg");
    this->GenererClan(TypeClan::Liskit,
                      "Liskit",
                      "",
                      ":/images/clans/Liskit.jpg");
    this->GenererClan(TypeClan::Festus,
                      "Festus",
                      "",
                      ":/images/clans/Festus.jpg");
    this->GenererClan(TypeClan::Raklur,
                      "Raklur",
                      "",
                      ":/images/clans/Raklur.jpg");
    this->GenererClan(TypeClan::Eshin,
                      "Eshin",
                      "",
                      ":/images/clans/Eshin.png");
    this->GenererClan(TypeClan::Moulder,
                      "Moulder",
                      "",
                      ":/images/clans/Moulder.jpg");
    this->GenererClan(TypeClan::Skyre,
                      "Skyre",
                      "",
                      ":/images/clans/Skyre.png");
    this->GenererClan(TypeClan::Mordkin,
                      "Mordkin",
                      "",
                      ":/images/clans/Mordkin.png");
    this->GenererClan(TypeClan::Grutnik,
                      "Grutnik",
                      "",
                      ":/images/clans/Grutnik.png");
    this->GenererClan(TypeClan::Volkn,
                      "Volkn",
                      "",
                      ":/images/clans/Volkn.jpg");
}

Clan* UniversSkaven::ChoisirClan()
{
    return m_TousLesClans[rand() % m_TousLesClans.length()];
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
