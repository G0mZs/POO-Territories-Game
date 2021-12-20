
#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

 

class Territorio{
protected:
    int n = 1;
    string nome,nomeConca; // Nome equivale ao tipo , se é planicie etc.. || nomeConca equivale ao tipo mais a ordem de criação (concatenação)
    string tipo;
    int resistencia, nprodutos, nouro, pontos;
    int turnoConquista;
    
public:
    Territorio(string tipo,string nome,int resistencia,int nprodutos,int nouro,int pontos,int n,int turnoConquista);
    string getNome();
    string getTipo();
    string getnomeConca();
    int getTurnoConquista();
    int setTurnoConquista(int turno);
    int getResistencia();
    int getProdutos();
    int getOuro();
    int getPontos();
    int getN();
    void mostraTerritorio();
    void setProdutos(int produtos);
    void setOuro(int ouro);
    void setResistencia(int resistencia);
    virtual ~Territorio();
};



