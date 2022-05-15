#ifndef AGENDAMENTO_HORARIOS_H
#define AGENDAMENTO_HORARIOS_H

#include <iostream>
#include <vector>

using namespace std;

class Agendamentos{
    string descricaco;
    string data;
    string hora;
public:
    Agendamentos();

    void set_descricao(string descricao);
    string get_descricao();

    void set_data(string data);
    string get_data();

    void set_hora(string hora);
    string get_hora();

    void salva_agendamento(string desc, string dat, string h);

    bool verifica_agendamento(Agendamentos a, vector<Agendamentos> agenda);
};

#endif // AGENDAMENTO_HORARIOS_H
