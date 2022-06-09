#include "ordem.h"
#include "ui_ordem.h"
#include "gerent.h"
#include "exibir2.h"
#include "marcar_horario.h"

ordem::ordem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordem)
{
    ui->setupUi(this);
}

ordem::~ordem()
{
    delete ui;
}

void ordem::on_pushButton_2_clicked()
{
    gerent g;
    this->close();
    g.exec();
}

void ordem::on_pushButton_3_clicked()
{
    //buscar
     QString data = ui->dateEdit_2->text();

     QSqlQuery query;
     //QString aux1;
     int aux = 1;

     query.prepare("select * from tb_agenda");
     query.exec();
     while(query.next()){
         if(query.value(1).toString() == data){
            aux = 0;
            break;
         }
     }
     if(aux == 1){
         QMessageBox::warning(this,"Busca","Nenhum Compromisso nesse dia!");
     }
     else{
         exibir2 g;
         this->close();
         g.exec();
     }
}

