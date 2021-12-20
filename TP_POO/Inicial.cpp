/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inicial.cpp
 * Author: FNAC
 * 
 * Created on 10 de novembro de 2020, 18:29
 */

#include "Inicial.h"

Inicial::Inicial(string nome,string tipo, int resistencia, int nprodutos, int nouro, int pontos) : Territorio("Territorio Inicial",nome,resistencia,nprodutos,nouro,pontos,n,turnoConquista)
{
    this->nome = nome;
    this->tipo = "Territorio Inicial";
    this->resistencia = 9;
    this->nouro = nouro;
    this->nprodutos = nprodutos;
    this->pontos = pontos;
    this->nomeConca = this->nome;
    this->turnoConquista = turnoConquista;
}


