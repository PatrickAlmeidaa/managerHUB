#include "marcar_horario.h"
#include "ui_marcar_horario.h"
#include "gerent.h"
#include "iostream"
#include <QMessageBox>

using namespace std;

Marcar_Horario::Marcar_Horario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Marcar_Horario)
{
    ui->setupUi(this);
}

Marcar_Horario::~Marcar_Horario()
{
    delete ui;
}

void Marcar_Horario::on_pushButton_2_clicked()
{
    gerent g;
    this->close();
    g.exec();
}


void Marcar_Horario::on_Agendar_clicked()
{
    QString desc = ui->lineEdit->text();
    QString data = ui->dateEdit->text();
    QString hora = ui->timeEdit->text();

    if(desc == ""){
         QMessageBox::warning(this,"Descrição","Descrição Invalida");
    }
}

