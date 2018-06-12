#include "osciloscopio.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Osciloscopio w;
    w.show();

    return a.exec();
}


