#include "exibir.h"
#include "ui_exibir.h"
#include "marcar_horario.h"
#include "gerent.h"

#include <QtSql>
#include <QMessageBox>
#include <QAbstractItemView>

exibir::exibir(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exibir)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from tb_agenda");
    if(query.exec()){
        int cont=0;
        ui->tableWidget->setColumnCount(3);
        while(query.next()){
            ui->tableWidget->insertRow(cont);
            ui->tableWidget->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setRowHeight(cont,20);
            cont++;
        }
        ui->tableWidget->setColumnWidth(0,300);
        ui->tableWidget->setColumnWidth(1,200);
        ui->tableWidget->setColumnWidth(2,121);
        QStringList cabecalhos={"Descrição","Data","Hora"};
        ui->tableWidget->setHorizontalHeaderLabels(cabecalhos);
        ui->tableWidget->setStyleSheet("QTableView {selection-background-color:rgb(177,156,217)}");
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableWidget->verticalHeader()->setVisible(false);

    }
    else{
         QMessageBox::warning(this,"Erro","ao lista");
    }
}
exibir::~exibir()
{
    delete ui;
}
void exibir::on_pushButton_clicked()
{
    gerent g;
    this->close();
    g.exec();
}
