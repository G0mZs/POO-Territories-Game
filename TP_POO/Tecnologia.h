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

class Tecnologia {
    string nome;
    int preco;
    string objetivo;
    string estado; // Se esta adquirida ou nao adquirida
public:
    Tecnologia(string nome,int preco,string objetivo,string estado);
    int getPreco();
    string getNome();
    string getObjetivo();
    string getEstado();
    string setEstado(string estado);
    void mostraTecnologias();
    ~Tecnologia();

};





