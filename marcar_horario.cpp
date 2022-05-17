#include "marcar_horario.h"
#include "ui_marcar_horario.h"

QSqlDatabase banco = QSqlDatabase::addDatabase("QSQLITE");

Marcar_Horario::Marcar_Horario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Marcar_Horario)
{
    ui->setupUi(this);
    banco.setDatabaseName("C:/Users/erick/Documents/Bancodedados/banco.db");
    banco.open();

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

    QSqlQuery query;
    QSqlQuery q;
    QString aux;
    q.prepare("insert into tb_agenda (Descricao,Data,Hora) values"
                 "('"+desc+"','"+data+"','"+hora+"')");

    query.prepare("select * from tb_agenda");

    if(query.exec()){

        int cont=0;
        //int test =0;
        bool test = false;
        if(desc == ""){
            test = 1;
        }

        while(query.next()){

            if(query.value(1).toString()==data && query.value(2).toString() == hora){
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
        }
        else if(test == true){
             QMessageBox::warning(this,"Cadastro","Feito com Sucesso");
             q.exec();
             ui->lineEdit->clear();
             ui->lineEdit->setFocus();
        }
    }
}

