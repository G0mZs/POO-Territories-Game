/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   imperio.h
 * Author: FNAC
 *
 * Created on 3 de dezembro de 2020, 11:20
 */
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
#include <time.h>


using namespace std;

#include "Tecnologia.h"
#include "Territorio.h"
#include "Inicial.h"
#include "Continente.h"
#include "Ilha.h"
#include "Eventos.h"

class imperio {
        int cofre = 0,armazem = 0,forcaMilitar = 0;
        vector<Territorio*> terrsImperio;
        vector<Tecnologia*> tecsImperio;
public:
     imperio();
     imperio(imperio& copia_imperio);
    int getforcaMilitar();
    int setArmazem(int armazem);
    int getCofre();
    int getArmazem();
    int setforcaMilitar(int forca);
    int setCofre(int cofre);
    void impInicial(Inicial* inicio);
    void preencheContinente(Territorio* territorio);
    void preencheIlha(Territorio* territorio);
    void preencheTecs(Tecnologia* tecnologia);
    void listarterrsImperio(vector<Territorio *> terr);
    void listaumTerritorioImp(string nome, vector<Territorio *> um);
    void deleteLast();
    vector<Territorio*> eliminaUltimo(vector<Territorio*> territorio);
    vector<Tecnologia *> getVectorTecsImperio();
    vector<Territorio *> getVectorTerrImperio();
    ~imperio();

};



