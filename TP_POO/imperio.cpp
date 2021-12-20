/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   imperio.cpp
 * Author: FNAC
 * 
 * Created on 3 de dezembro de 2020, 11:20
 */

#include "imperio.h"


using namespace std;

imperio::imperio()
{
	this->forcaMilitar = 0;
	this->armazem = 0;
	this->cofre = 0;
}

int imperio::setCofre(int cofre)
{
	this->cofre = cofre;
}

int imperio::setforcaMilitar(int forca)
{
	this->forcaMilitar = forca;
}

int imperio::getArmazem()
{
	return armazem;
}

int imperio::getCofre()
{
	return cofre;
}


int imperio::setArmazem(int armazem)
{
	this->armazem = armazem;
}

int imperio::getforcaMilitar()
{
	return forcaMilitar;
}

vector<Tecnologia *> imperio::getVectorTecsImperio()
{
	return tecsImperio;
}

vector<Territorio *> imperio::getVectorTerrImperio()
{
	return terrsImperio;
}

void imperio::impInicial(Inicial* inicio)
{
	terrsImperio.push_back(inicio);
}

void imperio::preencheContinente(Territorio* territorio)
{
    terrsImperio.push_back(territorio);
}

void imperio::preencheIlha(Territorio* territorio)
{
	terrsImperio.push_back(territorio);
}

void imperio::deleteLast()
{
    terrsImperio.pop_back();
}

void imperio::preencheTecs(Tecnologia* tecnologia)
{
	tecsImperio.push_back(tecnologia);
}

void imperio::listarterrsImperio(vector<Territorio *> terr)
{
	for (int i = 0; i < terr.size(); i++)
	{
		terr[i]->mostraTerritorio();
	}
}


void imperio::listaumTerritorioImp(string nome, vector<Territorio *> um)
{
		for (int i = 0; i < um.size(); i++)
		{
			if (um[i]->getnomeConca() == nome)
			{
				um[i]->mostraTerritorio();
			}
		}
}

vector<Territorio*> eliminaUltimo(vector<Territorio*> territorio)
 {
     territorio.erase(territorio.end() - 1);
     return territorio;
 }

imperio:: imperio(imperio& copia_imperio)
{
	
}

imperio::~imperio()
{
	for(int i = 0; i < tecsImperio.size(); i++)
	{
		delete tecsImperio[i];
	}

	for(int i = 0; i < terrsImperio.size(); i++)
	{
		delete terrsImperio[i];
	}


}


