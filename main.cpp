#include "mainwindow.h"
#include "login_tela.h"
#include "marcar_horario.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Marcar_Horario m;
    login_tela j;
    j.show();
    m.show();
    //w.show();
    return a.exec();
}
