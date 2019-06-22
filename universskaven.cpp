#include "universskaven.h"
#include "../destinLib/perso.h"
#include "ui_univers.h"
#include "genhistskaven.h"
#include <QVector>

UniversSkaven::UniversSkaven(ModeAffichage modeAffichage,
                         QWidget *parent)
    : Univers(parent, modeAffichage)
{
    this->AppliquerTheme(QColor(180, 180, 210));

    std::srand(time(nullptr));
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
