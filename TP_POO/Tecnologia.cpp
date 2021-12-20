/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tecnologia.cpp
 * Author: FNAC
 * 
 * Created on 10 de novembro de 2020, 14:49
 */

#include "Tecnologia.h"

Tecnologia::Tecnologia(string nome, int preco, string objetivo, string estado) {
    this->nome = nome;
    this->objetivo = objetivo;
    this->preco = preco;
    this->estado = estado;
}

string Tecnologia::getEstado() {
    return estado;
}

string Tecnologia::getNome() {
    return nome;
}

string Tecnologia::getObjetivo() {
    return objetivo;
}

int Tecnologia::getPreco() {
    return preco;
}

string Tecnologia::setEstado(string estado){
    this->estado = estado;
}

void Tecnologia::mostraTecnologias() {
    cout <<"Nome: " << getNome() << " Preco: " << getPreco() << " Objetivo: " << getObjetivo() << " Estado: " << getEstado() << endl;
}

Tecnologia::~Tecnologia() {

}





