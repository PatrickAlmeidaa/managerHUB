#include "agendamento_horarios.h"

Agendamentos::Agendamentos(){

}

void Agendamentos:: set_descricao(QString descricao){
    this->descricaco = descricao;
}
QString Agendamentos::get_descricao(){
    return descricaco;
}

void Agendamentos::set_data(QString data){
    this->data = data;
}
QString Agendamentos::get_data(){
    return data;
}

void Agendamentos::set_hora(QString hora){
    this->hora = hora;
}
QString Agendamentos::get_hora(){
    return hora;
}

void salva_agendamento(vector<Agendamentos> agenda, QString desc, QString dat, QString h){

    Agendamentos aux;

    aux.set_descricao(desc);
    aux.set_data(dat);
    aux.set_hora(h);

    agenda.push_back(aux);
}

bool verifica_agendamento(Agendamentos a, QVector<Agendamentos> agenda){
    //int tamanho = agenda.size();
    bool aux = true;
    //QMessageBox::warning(this,"entrou","entrou");
    // aux = false;
   // for(int i = 0; i < tamanho; i++){
     int i = 0;
   while(1){


        if(a.get_data() == agenda[i].get_data()){
            if(a.get_hora() == agenda[i].get_hora()){
                aux = false;
      //          QMessageBox::warning(this,"Horario","Horario Indisponivel");
                break;
            }
        }
        i++;
    }
    return aux;
}
