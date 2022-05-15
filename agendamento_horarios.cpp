#include "agendamento_horarios.h"

Agendamentos::Agendamentos(){

}

void Agendamentos:: set_descricao(string descricao){
    this->descricaco = descricao;
}
string Agendamentos::get_descricao(){
    return descricaco;
}

void Agendamentos::set_data(string data){
    this->data = data;
}
string Agendamentos::get_data(){
    return data;
}

void Agendamentos::set_hora(string hora){
    this->hora = hora;
}
string Agendamentos::get_hora(){
    return hora;
}

void Agendamentos::salva_agendamento(string desc, string dat, string h){
    vector<Agendamentos> agenda;
    Agendamentos aux;

    aux.set_descricao(desc);
    aux.set_data(dat);
    aux.set_hora(h);

    agenda.push_back(aux);
}

bool Agendamentos::verifica_agendamento(Agendamentos a, vector<Agendamentos> agenda){
    int tamanho = agenda.size();
    for(int i = 0; i < tamanho; i++){
        if(a.data == agenda[i].get_data()){
            if(a.hora == agenda[i].hora){
                break;
                return false;
            }
        }
    }
    return true;
}
