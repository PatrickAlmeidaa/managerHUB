#include "marcar_horario.h"
#include "ui_marcar_horario.h"
#include <QDebug>

//QSqlDatabase banco = QSqlDatabase::addDatabase("QSQLITE");

Marcar_Horario::Marcar_Horario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Marcar_Horario)
{
    ui->setupUi(this);
    //banco.setDatabaseName("C:/Users/erick/Documents/Bancodedados/banco.db");
    //banco.open();

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
    QTime hora = ui->timeEdit->time();
    QTime hora2 = ui->timeEdit_2->time();
    //if(hora < hora2)
      //  QMessageBox::warning(this,"Comparação Horario","Horario comparou certo");

        //qDebug() << "Hora impresso" <<;

    QSqlQuery query;
    QSqlQuery q;
    QString aux1;

    q.prepare("insert into tb_agenda (Descricao,Data,Hora,Fim) values"
                 "('"+desc+"','"+data+"','"+hora.toString()+"','"+hora2.toString()+"')");

    query.prepare("select * from tb_agenda");

    if(desc == ""){
       QMessageBox::warning(this,"Erro","Descrição Invalida");
    }
    else if(hora >= hora2){
       QMessageBox::warning(this,"Erro","Horario Inválido");
       ui->timeEdit->setMinimumTime( QTime( 0, 0, 0 ) );
       ui->timeEdit_2->setMinimumTime( QTime( 0, 0, 0 ) );
    }
    else if(query.exec()){

        int aux = 0;

        while(query.next()){
            if(query.value(1).toString() == data){
               if(query.value(2).toTime() <= hora && query.value(3).toTime() >= hora){
                   aux = 1;
                   aux1 = query.value(0).toString();
                   break;
               }
               else if(query.value(2).toTime() <= hora2 && query.value(3).toTime() >= hora2){
                   aux = 1;
                   aux1 = query.value(0).toString();
                   break;
               }
               else if(query.value(2).toTime() <= hora && query.value(3).toTime() >= hora && query.value(2).toTime() <= hora2 && query.value(3).toTime() >= hora2){
                   aux = 1;
                   aux1 = query.value(0).toString();
                   break;
               }
               else if(!(query.value(2).toTime() <= hora && query.value(3).toTime() >= hora && query.value(2).toTime() <= hora2 && query.value(3).toTime() >= hora2)){

                   if(hora < query.value(2).toTime()){
                       if(hora2 < query.value(2).toTime()){
                           aux = 0;
                           break;
                       }
                       else{
                           aux = 1;
                           break;
                       }
                   }
               }
              }
            }
        if(aux == 1){
            QMessageBox::warning(this,"Conflito de Horarios",aux1+" ja esta marcado nesse mesmo dia e horario");
            ui->timeEdit->clear();
            ui->timeEdit->setFocus();
        }
        else{
            QMessageBox::warning(this,"Cadastro","Deu certo");
            ui->lineEdit->clear();
            ui->lineEdit->setFocus();
            ui->timeEdit->clearMinimumTime();
            ui->timeEdit_2->clearMinimumTime();
            q.exec();
        }
    }



       /*
        int cont=0;
        //int test =0;
        bool test = false;

        while(query.next()){

            if(query.value(1).toString()== ""){
                test = true;
            }
            else if(query.value(1).toString()==data && query.value(2).toTime() >= hora  && query.value(3).toTime() <= hora2){
                test = false;
                aux = query.value(0).toString();
                break;
            }
            else{
                test = true;
            }
            cont++;

        }
        if(test == false && desc == ""){
             QMessageBox::warning(this,"Descrição Invalida","Favor Inserir uma Descrição Validade");
             ui->lineEdit->clear();
             ui->lineEdit->setFocus();
        }
        else if(test == true && desc == ""){
             QMessageBox::warning(this,"Descrição Invalida","Favor Inserir uma Descrição Validade");
             ui->lineEdit->clear();
             ui->lineEdit->setFocus();
        }
        else if(test == false){
             QMessageBox::warning(this,"Conflito de Horarios",aux+" ja esta marcado nesse mesmo dia e horario");
             ui->lineEdit->clear();
             ui->lineEdit->setFocus();
        }
        else if(test == true){
             QMessageBox::warning(this,"Cadastro","Feito com Sucesso");
             q.exec();
             ui->lineEdit->clear();
             ui->lineEdit->setFocus();
        }*/
}

