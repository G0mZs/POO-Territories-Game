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

class Eventos {
    string nome;
    string descricao;
public:
    Eventos(string nome,string descricao);
    string getNomeEvento();
    string getDescricao();
    void mostraEvento();
};



