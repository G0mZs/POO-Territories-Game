/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Territorio.cpp
 * Author: FNAC
 * 
 * Created on 10 de novembro de 2020, 14:49
 */

#include "Territorio.h"

Territorio::Territorio(string tipo, string nome, int resistencia, int nprodutos, int nouro, int pontos,int n,int turnoConquista) {
    this->n = n;
    this->nome = nome; 
    this->n++;
    this->tipo = tipo;
    this->resistencia = resistencia;
    this->nprodutos = nprodutos;
    this->nouro = nouro;
    this->pontos = pontos;
    this->nomeConca = this->nome + to_string(n);
    this->turnoConquista = turnoConquista;
}

int Territorio::getTurnoConquista()
{
    return turnoConquista;
}

int Territorio::setTurnoConquista(int turno)
{
    this->turnoConquista = turno;
}

string Territorio::getnomeConca()
{
    return nomeConca;
}

int Territorio::getN(){
    return n;
}

string Territorio::getNome() {
    return nome;
}

int Territorio::getOuro() {
    return nouro;
}

int Territorio::getPontos() {
    return pontos;
}

int Territorio::getProdutos() {
    return nprodutos;
}

int Territorio::getResistencia() {
    return resistencia;
}

string Territorio::getTipo() {
    return tipo;
}


void Territorio::mostraTerritorio() {
    cout  << "Tipo: " << getTipo()  << " Nome: " << getnomeConca() << " Resistencia: " << getResistencia() << " Producao de ouro por turno: " << getOuro() << " Producao de produtos por turno: " << getProdutos() << " Pontuacao: " << getPontos() << endl;
    
}

void Territorio::setProdutos(int produtos)
{
    this->nprodutos = produtos;
}

void Territorio::setOuro(int ouro)
{
    this->nouro = ouro;
}

void Territorio::setResistencia(int resistencia)
{
    this->resistencia = resistencia;
    for( c: territorios)
}

Territorio::~Territorio() {

}
