/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Eventos.cpp
 * Author: FNAC
 * 
 * Created on 27 de novembro de 2020, 21:04
 */

#include "Eventos.h"

Eventos::Eventos(string nome,string descricao) {

    this->nome = nome;
    this->descricao = descricao;
}

string Eventos::getNomeEvento()
{
    return nome;
}

string Eventos::getDescricao()
{
    return descricao;
}

void Eventos::mostraEvento()
{
    cout << "Evento: " << getNomeEvento() << " Descricao: " << getDescricao() << endl;
}
