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
#include <cstring>
#include "Tecnologia.h"
#include "Territorio.h"
#include "jogo.h"
#include "Ilha.h"
#include "Continente.h"
#include "Inicial.h"

using namespace std;

struct guarda_jogo{
    jogo *gamez;
    string nome;
};

class Configs{
    int tamanho = 0,tentativa = 0,tentativaRecursos = 0;
	jogo *game;
    vector<guarda_jogo> gestorjogo;
    static int num_id;
    
public:
    Configs();
    int setTamanho(int tamanho);
    void comecar();
    bool carregaTecnologia(string ficheiro);
    bool carregaTerritorio(string ficheiro);
    int leComando(vector<string> subcomando);
    int leComando2(vector<string> subcomando);
    int leComando3(vector<string> subcomando,int temp3);
    int leComando4(vector<string> subcomando,int temp,int temp2);
    int leComandoAvanca(vector<string> subcomando);
    int iniciaJogo();
    int acabaJogo();
    vector<string> divideString(string comando);
    void gravajogo(string nome,jogo* aux);
    void apagajogo(string nome);
    void ativajogo(string nome,jogo* aux);
    string modificaIgual(string nome);
    int procuraJogo(string nome);
    ~Configs();
};


