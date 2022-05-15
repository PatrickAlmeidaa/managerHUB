#include "gerent_funcoes.h"
#include "login_tela.h"
#include "marcar_horario.h"
#include "gerent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login_tela j;
    Marcar_Horario m;

    j.show();

    return a.exec();
}
