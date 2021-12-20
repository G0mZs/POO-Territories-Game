/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Continente.cpp
 * Author: FNAC
 * 
 * Created on 10 de novembro de 2020, 18:43
 */

#include "Continente.h"



Continente::Continente(string nome,string tipo, int resistencia, int nprodutos, int nouro, int pontos,int n,int turnoConquista) : Territorio("Continente",nome,resistencia,nprodutos,nouro,pontos,n,turnoConquista)
{
    this->n = n;
    this->nome = nome;
    this->tipo = "Continente";
    if(nome == "Planicie")
    {
        this->nomeConca = nome + to_string(n);
        this->resistencia = 5;
        this->nouro = 0;
        this->nprodutos = 0;
        
    }
    if(nome == "Montanha")
    {
        this->nomeConca = nome + to_string(n);
        this->resistencia = 6;
        this->nouro = 0;
        this->nprodutos = 0;
        
    }
    if(nome == "Fortaleza")
    {
        this->nomeConca = nome + to_string(n);
        this->resistencia = 8;
        this->nouro = 0;
        this->nprodutos = 0;
        
    }
    if(nome == "Mina")
    {
        this->nomeConca = nome + to_string(n);
        this->resistencia = 5;
        this->nouro = 0;
        this->nprodutos = 0;
        
    }
    if(nome == "Duna")
    {
        this->nomeConca = nome + to_string(n);
        this->resistencia = 4;
        this->nouro = 0;
        this->nprodutos = 0;
        
    }
    if(nome == "Castelo")
    {
        this->nomeConca = nome + to_string(n);
        this->resistencia = 7;
        this->nouro = 0;
        this->nprodutos = 0;
        
    }
    else;
       this->pontos = 1; 
       this->turnoConquista = turnoConquista;
}


