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

#include "Tecnologia.h"
#include "Territorio.h"

using namespace std;

class Ilha : public Territorio{
    
public:
    Ilha(string nome,string tipo,int resistencia,int nprodutos,int nouro,int npontos,int n);
};



