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
void login_tela::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString senha = ui->lineEdit_2->text();
    /*
    if(username == "gerent" && senha == "123"){
        QMessageBox::information(this,"Login","Feito com sucesso");
        gerent g;

        this->close();

        g.exec();
    }
    else{
        QMessageBox::warning(this,"Login","Usuario ou Senha incorretas");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit->setFocus();
    }*/
    gerent g;
        this->close();

        g.exec();
}

void login_tela::on_pushButton_2_clicked()
{
   this->close();
}

