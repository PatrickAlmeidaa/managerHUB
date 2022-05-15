#include "gerent.h"
#include "ui_gerent.h"
//#include "main.cpp"
#include "marcar_horario.h"

gerent::gerent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerent)
{
    ui->setupUi(this);
}

gerent::~gerent()
{
    delete ui;
}

void gerent::on_pushButton_clicked()
{
    this->close();
}


void gerent::on_pushButton_3_clicked()
{
    Marcar_Horario m;
    this->close();
    m.exec();
    //j.close();
}

