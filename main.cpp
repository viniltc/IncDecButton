#include "buttoninc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ButtonInc w;
    w.show();
    return a.exec();
}
