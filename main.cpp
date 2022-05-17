#include "login_tela.h"
#include "gerent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login_tela j;

    j.show();

    return a.exec();
}
