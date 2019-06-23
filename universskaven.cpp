#include "universskaven.h"
#include "ui_univers.h"
#include "clan.h"
#include <QTime>

UniversSkaven::UniversSkaven(ModeAffichage modeAffichage,
                         QWidget *parent)
    : Univers(parent, modeAffichage)
{
    this->AppliquerTheme(QColor(180, 180, 210));

    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));

    this->GenererTousLesClans();
}

void UniversSkaven::GenererCaracs()
{
}

Hist* UniversSkaven::ExecuterGenerateurHistoire()
{
    m_Histoire = new Hist("Vie de Skaven");
    m_GenHistoire = new GenHistSkaven(m_Histoire);
    m_GenHistoire->GenererHistoire();
    this->setWindowTitle(m_Histoire->m_Titre);

    return m_Histoire;
}

void UniversSkaven::GenererTousLesClans()
{
    m_TousLesClans.push_back(new Clan(TypeClan::Rictus, "Rictus"));
    m_TousLesClans.push_back(new Clan(TypeClan::Mors, "Mors"));
    m_TousLesClans.push_back(new Clan(TypeClan::Skab, "Skab"));
    m_TousLesClans.push_back(new Clan(TypeClan::Pestilens, "Pestilens"));
    m_TousLesClans.push_back(new Clan(TypeClan::Septik, "Septik"));
    m_TousLesClans.push_back(new Clan(TypeClan::Skrat, "Skrat"));
    m_TousLesClans.push_back(new Clan(TypeClan::Gratzz, "Gratzz"));
    m_TousLesClans.push_back(new Clan(TypeClan::Morbidus, "Morbidus"));
    m_TousLesClans.push_back(new Clan(TypeClan::Scorbut, "Scorbut"));
    m_TousLesClans.push_back(new Clan(TypeClan::Krizzor, "Krizzor"));
    m_TousLesClans.push_back(new Clan(TypeClan::Liskit, "Liskit"));
    m_TousLesClans.push_back(new Clan(TypeClan::Festus, "Festus"));
    m_TousLesClans.push_back(new Clan(TypeClan::Raklur, "Raklur"));
    m_TousLesClans.push_back(new Clan(TypeClan::Eshin, "Eshin"));
    m_TousLesClans.push_back(new Clan(TypeClan::Moulder, "Moulder"));
    m_TousLesClans.push_back(new Clan(TypeClan::Skyre, "Skyre"));
    m_TousLesClans.push_back(new Clan(TypeClan::Mordkin, "Mordkin"));
    m_TousLesClans.push_back(new Clan(TypeClan::Grutnik, "Grutnik"));
    m_TousLesClans.push_back(new Clan(TypeClan::Charogne, "Charogne"));
    m_TousLesClans.push_back(new Clan(TypeClan::Volkn, "Volkn"));
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
