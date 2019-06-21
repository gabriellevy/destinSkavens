#include "universskaven.h"
#include "../destinLib/perso.h"
#include "ui_univers.h"
#include "genhistskaven.h"

UniversSkaven::UniversSkaven(ModeAffichage modeAffichage,
                         QWidget *parent)
    : Univers(parent, modeAffichage)
{
    this->AppliquerTheme(QColor(180, 180, 210));
}

void UniversSkaven::GenererCaracs()
{
}

Hist* UniversSkaven::ExecuterGenerateurHistoire()
{
    m_Histoire = new Hist("Sélection du rêve");
    m_GenHistoire = new GenHistSkaven(m_Histoire);
    m_GenHistoire->GenererHistoire();
    this->setWindowTitle("Sélection du rêve");

    return m_Histoire;
}
