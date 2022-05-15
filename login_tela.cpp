#include "login_tela.h"
#include "ui_login_tela.h"
#include <QMessageBox>
#include "marcar_horario.h"
#include "mainwindow.h"
#include "gerent.h"

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
void login_tela::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString senha = ui->lineEdit_2->text();

    if(username == "gerent" && senha == "123"){
        //MainWindow form;
        QMessageBox::information(this,"Login","Feito com sucesso");
        Marcar_Horario j;
        gerent g;

        this->close();

        g.exec();

    }
    else{
        QMessageBox::warning(this,"Login","Username ou senha incorretas");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit->setFocus();
    }

}

