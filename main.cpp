#include "universskaven.h"
#include "../destinLib/histoire.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // lancer le jeu :
    UniversSkaven av(ModeAffichage::ema_Jeu);
    av.LancerHistoire(UniversSkaven::VIE_SKAVEN, nullptr, "", "", true);
    av.show();

    return a.exec();
}
