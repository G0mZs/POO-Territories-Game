/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ilha.cpp
 * Author: FNAC
 * 
 * Created on 10 de novembro de 2020, 19:07
 */

#include "Ilha.h"

using namespace std;

Ilha::Ilha(string nome, string tipo, int resistencia, int nprodutos, int nouro, int npontos,int n) : Territorio("Ilha", nome, resistencia, nprodutos, nouro, npontos,n,turnoConquista) {
    this->n = n;
    this->nome = nome;
    this->tipo = "Ilha";
    if(nome == "Refugio dos Piratas")
    {
        this->nomeConca = nome + to_string(n);
        this->resistencia = 9;
        this->nouro = 0;
        this->nprodutos = 0;
    }
    if(nome == "Pescaria")
    {
        this->nomeConca = nome + to_string(n);
        this->resistencia = 9;
        this->nouro = 0;
        this->nprodutos = 0;
    }
    else;
    this->pontos = 2;
}
