#include "login_tela.h"
#include "ui_login_tela.h"

login_tela::login_tela(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login_tela)
{
    ui->setupUi(this);
}

login_tela::~login_tela()
{
    delete ui;
}
