#include "universskaven.h"
#include "../destinLib/histoire.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // lancer le jeu :
    UniversSkaven av(ModeAffichage::ema_Jeu);
    Hist* hist = av.ExecuterGenerateurHistoire();
    ExecHistoire* exec_hist = new ExecHistoire(hist);
    av.LancerHistoire(exec_hist);
    av.show();

    return a.exec();
}
