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
#include "imperio.h"


class jogo {
    string nomeJogo;
    int turno=1, ano=1,fase = 1;
    vector<Territorio*> territorios;
    vector<Tecnologia *> tecnologias;
    vector<Eventos*> eventos;
    //imperio
    imperio *Imperio;


public:
    // Gets
    
    jogo();
    jogo(jogo& copia_jogo);
    int getFase();
    int getTurno();
    int getAno();
    string getnomeJogo();
    int getArmazem();
    int getCofre();
    int getForcaMilitar();
    //sets
    int setCofre(int cofre);
    int setArmazem(int armazem);
    int setForcaMilitar(int forca);
    int setFase(int fase);
    int setTurno(int turno);
    int setAno(int ano);
    string setnomeJogo(string nome);
    //
    int geraNRandom();
    int verificaN(string nome);
    int procuraTecnologia(string nome);
    int ouroTotal();
    int produtosTotal();
    int verificaforcaMaxima();
    int verificaOuroMaximo();
    int verificaProdutosMaximo();
    int obtemforcaInvasao(int ano);
    int pontuacaoTotal();
    int pontuacaoTerritorios();
    int pontuacaotodasTecnologias();
    int pontuacaoTecnologia();
    int pontuacaotodosTerritorios();
    int buscaIlha(string nome);
    int buscaTerritorio(string nome);
    int buscaTecnologia(string nome);
    void preencheEventos(Eventos *evento);
    void guardaOuro(int totalOuro);
    void guardaProdutos(int totalProdutos);
    void conquistaTerritorio(string tipo);
    void adicionaTerritorio(Territorio * c);
    void adicionaTecnologia(Tecnologia * c);
    void adicionaTecImperio(Tecnologia *c);
    void listarTecnologias();
    void listarTerritorios(vector<Territorio*> terr);
    void ListarTempo(int turno,int ano,int fase);
    void ListarforcaMilitar();
    void listarTecsImperio();
    void listarEventos();
    void imperioInicial(Inicial* inicio);
    void listaumTerritorio(string nome,vector<Territorio*> um);
    void geraRecursosTerritorios(int turno,int ano,vector<Territorio*> territorios,int aux);
    void compraTecnologia(string nome);
    void maisMilitar();
    void listaRecursos();
    void resetaOuro(vector<Territorio*> terrs);
    void resetaProdutos(vector<Territorio*> terrs);
    void maisOuro();
    void maisProdutos();
    void eventoRandom(int ano);
    void recursoAbandonado(int ano);
    void Invasao(int ano);
    void aliancaDiplomatica();
    void clear();
    void tomaTecnologia(string nome);
    void tomaTerritorio(string nome);
    void preencheCopia(jogo aux);
    vector<Territorio*>SetVetorTerrsImperio(vector<Territorio*> temp);
    vector<Territorio*> getVectorTerritorio();
    vector<Tecnologia*> getVectorTecnologia();
    vector<Territorio*> getVectorTerrImperio();
    vector<Tecnologia*> getVectorTecImperio();
    vector<Eventos*> getVectorEventos();
    ~jogo();
};

