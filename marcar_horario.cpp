#include "marcar_horario.h"
#include "ui_marcar_horario.h"
#include "gerent.h"

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

