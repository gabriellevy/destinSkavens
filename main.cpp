#include "universskaven.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UniversSkaven w;
    w.show();

    return a.exec();
}
