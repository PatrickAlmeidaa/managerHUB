#include "exibir2.h"
#include "ui_exibir2.h"
#include "gerent.h"

exibir2::exibir2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exibir2)
{
    ui->setupUi(this);
}

exibir2::~exibir2()
{
    delete ui;
}

void exibir2::on_pushButton_clicked()
{
    gerent g;
    this->close();
    g.exec();
}


void exibir2::on_pushButton_2_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->clearContents();
    QString data = ui->dateEdit->text();
    QSqlQuery query;
    query.prepare("select * from tb_agenda");
    if(query.exec()){
        int cont=0, cont2 = 0;
        ui->tableWidget->setColumnCount(4);

        while(query.next()){
            if(query.value(1).toString() == data){
                cont2++;
                ui->tableWidget->insertRow(cont);
                ui->tableWidget->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
                ui->tableWidget->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
                ui->tableWidget->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
                ui->tableWidget->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
                ui->tableWidget->setRowHeight(cont,20);
                cont++;
           }
        }

        ui->tableWidget->setColumnWidth(0,400);
        ui->tableWidget->setColumnWidth(1,100);
        ui->tableWidget->setColumnWidth(2,121);
        ui->tableWidget->setColumnWidth(3,121);
        QStringList cabecalhos={"Descrição","Data","Hora de Inicio","Hora de Termino"};
        ui->tableWidget->setHorizontalHeaderLabels(cabecalhos);
        ui->tableWidget->setStyleSheet("QTableView {selection-background-color:rgb(177,156,217)}");
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->verticalHeader()->setVisible(false);

        if(!(cont2 > 0)){
             QMessageBox::warning(this,"Busca","Nenhum compromisso nesse dia!");
        }



        //query.prepare("select Data, from tb_agenda order by Data");
        //query.exec();

    }
    else{
         QMessageBox::warning(this,"Acesso","Acesse a area de agendamento");
    }
}

