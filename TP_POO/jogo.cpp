/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   jogo.cpp
 * Author: FNAC
 * 
 * Created on 10 de novembro de 2020, 14:51
 */

#include "jogo.h"

using namespace std;

jogo::jogo()
{
	Imperio = new imperio;

	Imperio->impInicial(new Inicial("Inicial","Territorio Inicial",9,0,0,0));
}

int jogo::getFase()
{
	return fase;
}

int jogo::getTurno()
{
	return turno;
}

int jogo::getAno()
{
	return ano;
}

string jogo::getnomeJogo()
{
	return nomeJogo;
}

string jogo::setnomeJogo(string nome)
{
	this->nomeJogo = nome;
}

int jogo::setFase(int fase)
{
	this->fase = fase;
}

int jogo::setTurno(int turno)
{
	this->turno = turno;
}

int jogo::setAno(int ano)
{
	this->ano = ano;
}

int jogo::setCofre(int cofre)
{
	Imperio->setCofre(cofre);
}

int jogo::setForcaMilitar(int forca)
{
	Imperio->setforcaMilitar(forca);
}

int jogo::setArmazem(int armazem)
{
	Imperio->setArmazem(armazem);
}

int jogo::getArmazem()
{
	return Imperio->getArmazem();
}

int jogo::getCofre()
{
	return Imperio->getCofre();
}

int jogo::getForcaMilitar()
{
	return Imperio->getforcaMilitar();
}

void jogo::preencheEventos(Eventos *evento)
{
	eventos.push_back(evento);
}

void jogo::adicionaTerritorio(Territorio *c)
{
	territorios.push_back(c);
}

void jogo::adicionaTecnologia(Tecnologia *c)
{
	tecnologias.push_back(c);
}

void jogo::imperioInicial(Inicial* inicio)
{
	getVectorTerrImperio().push_back(inicio);
}

vector<Eventos*> jogo::getVectorEventos()
{
	return eventos;
}

//Funcao auxiliar que é usada no conquistaTerritorio

int jogo::geraNRandom()
{
	int random, forcaTotal;

	srand(time(NULL));

	random = 1 + (rand() % 6);

	forcaTotal = random + Imperio->getforcaMilitar();

	return forcaTotal;
}

//Funcao que serve para conquistar

void jogo::conquistaTerritorio(string tipo) //Notas: fazer a parte de apagar o territorio depois de conquistado para sair do vetor de territorios,introduzir as tecnologias
{
	int poderImperio, forcaMilitar = Imperio->getforcaMilitar();
	poderImperio = geraNRandom();

	for (int i = 0; i < territorios.size(); i++)
	{
		if (territorios[i]->getnomeConca() == tipo && territorios[i]->getTipo() == "Continente")
		{
			if (poderImperio >= territorios[i]->getResistencia())
			{
				cout << "Parabens !! Territorio conquistado com sucesso!" << endl;
				territorios[i]->setTurnoConquista(turno);
				Imperio->preencheContinente(new Continente(territorios[i]->getNome(), territorios[i]->getTipo(), territorios[i]->getResistencia(), territorios[i]->getProdutos(), territorios[i]->getOuro(), territorios[i]->getPontos(),territorios[i]->getN(),territorios[i]->getTurnoConquista()));
				territorios.erase(territorios.begin() + i);
			}
			else
			{
				cout << "A forca do Imperio foi inferior a forca do territorio que desejou conquistar. Insucesso !!!" << endl;
				if (forcaMilitar > 0 && forcaMilitar <= verificaforcaMaxima())
				{
					forcaMilitar--;
					Imperio->setforcaMilitar(forcaMilitar);
				}
				else
				{
					Imperio->setforcaMilitar(forcaMilitar);
				}
			}
		}
		else
		{
			if (territorios[i]->getnomeConca() == tipo && territorios[i]->getTipo() == "Ilha")
		
			if (poderImperio >= territorios[i]->getResistencia())
			{
				cout << "Parabens !! Territorio conquistado com sucesso!" << endl;
				Imperio->preencheIlha(new Ilha(territorios[i]->getNome(), territorios[i]->getTipo(), territorios[i]->getResistencia(), territorios[i]->getProdutos(), territorios[i]->getOuro(), territorios[i]->getPontos(),territorios[i]->getN()));
				territorios.erase(territorios.begin() + i);
			}
			else
			{
				cout << "A forca do Imperio foi inferior a forca do territorio que desejou conquistar. Insucesso !!!" << endl;
				if (forcaMilitar > 0 && forcaMilitar <= verificaforcaMaxima())
				{
					forcaMilitar--;
					Imperio->setforcaMilitar(forcaMilitar);
				}
				else
				{
					Imperio->setforcaMilitar(forcaMilitar);
				}
			}
		
		}
	}
}


	void jogo::listarEventos()
	{
		for (int i = 0; i < eventos.size(); i++)
		{
			eventos[i]->mostraEvento();
		}
	}

	void jogo::ListarTempo(int turno, int ano, int fase)
	{
		cout << "Fase: " << fase << endl;
		cout << "Turno: " << turno << endl;
		cout << "Ano: " << ano << endl;
	}

	void jogo::ListarforcaMilitar()
	{
		cout << "A forca militar deste Imperio e " << Imperio->getforcaMilitar() << " Forca Maxima: " << verificaforcaMaxima() << endl;
	}

	void jogo::listarTecnologias()
	{
		for (Tecnologia *c : tecnologias)
		{
			c->mostraTecnologias();
		}
	}

	void jogo::listarTerritorios(vector<Territorio *> terr)
	{
		for (int i = 0; i < terr.size(); i++)
		{
			terr[i]->mostraTerritorio();
		}
	}

	//Procura uma tecnologia no vector de tecnologias do imperio

	int jogo::procuraTecnologia(string nome)
	{
		for (int i = 0; i < Imperio->getVectorTecsImperio().size(); i++)
		{
			if (Imperio->getVectorTecsImperio()[i]->getNome() == nome)
			{
				return 1;
			}
		}
		return 0;
	}

	//Lista um territorio á escolha

	void jogo::listaumTerritorio(string nome, vector<Territorio *> um)
	{
		for (int i = 0; i < um.size(); i++)
		{
			if (um[i]->getnomeConca() == nome)
			{
				um[i]->mostraTerritorio();
			}
		}
	}

	//Lista todas as tecnologias do imperio

	void jogo::listarTecsImperio()
	{
		for (int i = 0; i < Imperio->getVectorTecsImperio().size(); i++)
		{
			Imperio->getVectorTecsImperio()[i]->mostraTecnologias();
		}
	}

	//Funcoes que retornam o vetor que constitui os territorios do imperio e os por conquistar

	vector<Territorio *> jogo::getVectorTerritorio()
	{
		return territorios;
	}

	vector<Tecnologia *> jogo::getVectorTecnologia()
	{
		return tecnologias;
	}

	//Funcao para gerir os recursos de cada territorio

	void jogo::geraRecursosTerritorios(int turno, int ano, vector<Territorio *> territorios, int aux)
	{
		for (int i = 0; i < territorios.size(); i++)
		{
			if (territorios[i]->getNome() == "Planicie")
			{
				if (turno >= 1 && turno <= 6 && ano == 1)
				{
					int produtos = territorios[i]->getProdutos();
					int ouro = territorios[i]->getOuro();
					ouro++;
					produtos++;
					territorios[i]->setProdutos(produtos);
					territorios[i]->setOuro(ouro);
				}
				else if (turno >= 1 && turno <= 6 && ano == 2)
				{
					int produtos = territorios[i]->getProdutos();
					int ouro = territorios[i]->getOuro();
					ouro++;
					produtos += 2;
					territorios[i]->setProdutos(produtos);
					territorios[i]->setOuro(ouro);
				}
				else
					;
			}
			else if (territorios[i]->getNome() == "Montanha")
			{
				if (aux >= territorios[i]->getTurnoConquista() + 2 && aux <= 12 && ano <= 2) 
				{
					int produtos = territorios[i]->getProdutos();
					produtos++;
					territorios[i]->setProdutos(produtos);
				}
				else
					;
			}
			else if (territorios[i]->getNome() == "Mina")
			{
				if (turno >= 1 && turno <= 3 && ano <= 2)
				{
					int ouro = territorios[i]->getOuro();
					ouro++;
					territorios[i]->setOuro(ouro);
				}
				if (turno > 3 && turno <= 6 && ano <= 2)
				{
					int ouro = territorios[i]->getOuro();
					ouro++;
					territorios[i]->setOuro(ouro);
				}
				else
					;
			}
			else if (territorios[i]->getNome() == "Duna")
			{
				if (turno >= 1 && turno <= 6 && ano <= 2)
				{
					int produtos = territorios[i]->getProdutos();
					produtos++;
					territorios[i]->setProdutos(produtos);
				}
				else
					;
			}
			else if (territorios[i]->getNome() == "Castelo")
			{
				if (turno >= 1 && turno <= 6 && ano <= 2)
				{
					int ouro = territorios[i]->getOuro();
					ouro++;
					territorios[i]->setOuro(ouro);
				}
				if (turno >= 1 && turno <= 2 && ano <= 2)
				{
					int produtos = territorios[i]->getProdutos();
					produtos += 3;
					territorios[i]->setProdutos(produtos);
				}
				else
					;
			}
			else if (territorios[i]->getNome() == "Refugio dos Piratas")
			{
				if (turno >= 1 && turno <= 6 && ano <= 2)
				{
					int ouro = territorios[i]->getOuro();
					ouro++;
					territorios[i]->setOuro(ouro);
				}
				else
					;
			}
			else if (territorios[i]->getNome() == "Pescaria")
			{
				if (turno >= 1 && turno <= 6 && ano == 1)
				{
					int produtos = territorios[i]->getProdutos();
					produtos += 2;
					territorios[i]->setProdutos(produtos);
				}
				if (turno >= 1 && turno <= 6 && ano == 2)
				{
					int produtos = territorios[i]->getProdutos();
					produtos += 4;
					territorios[i]->setProdutos(produtos);
				}
				else
					;
			}
			else if (territorios[i]->getNome() == "Inicial")
			{
				if (turno >= 1 && turno <= 6 && ano <= 2)
				{
					int produtos = territorios[i]->getProdutos();
					int ouro = territorios[i]->getOuro();
					produtos++;
					ouro++;
					territorios[i]->setProdutos(produtos);
					territorios[i]->setOuro(ouro);
				}
				else
					;
			}
			else
				;
		}
	}

	int jogo::verificaN(string nome)
	{
		int a;
		for (int i = 0; i < territorios.size(); i++)
		{

			if (territorios[i]->getNome() == nome)
			{

				a = territorios[i]->getN();
			}
			else
				;
		}

		if (territorios.empty())
		{
			a = 0;
			return a;
		}
		return a;
	}

int jogo::ouroTotal() // Esta mal feito.
{
	int ouroTotal = 0;

	for (int i = 0; i < getVectorTerrImperio().size(); i++)
	{
		ouroTotal = ouroTotal + getVectorTerrImperio()[i]->getOuro();
	}

	return ouroTotal;
}

int jogo::produtosTotal()
{
	int produtosTotal = 0;

	for (int i = 0; i < getVectorTerrImperio().size(); i++)
	{
		produtosTotal = produtosTotal + getVectorTerrImperio()[i]->getProdutos();
	}

	return produtosTotal;
}

	void jogo::guardaOuro(int totalOuro)
	{
		int cofre = Imperio->getCofre();
		int cofreTotal;
		int diferenca2;

		int cofreMaximo = verificaOuroMaximo();
		diferenca2 = cofreMaximo - cofre;
		if (cofre >= 0 && cofre < cofreMaximo && totalOuro >= cofreMaximo) //cofre maior que 0 e menor que o cofre maximo, ouro que recebes é maior que cofre maximo
		{
			cofreTotal = cofreMaximo;
			Imperio->setCofre(cofreTotal);
		}
		else if (cofre >= 0 && cofre < cofreMaximo && totalOuro < cofreMaximo && diferenca2 >= totalOuro)
		{
			cofreTotal = cofre + totalOuro;
			Imperio->setCofre(cofreTotal);
		}
		else if (cofre >= 0 && cofre < cofreMaximo && totalOuro < cofreMaximo && diferenca2 < totalOuro)
		{
			cofreTotal = cofre + diferenca2;
			Imperio->setCofre(cofreTotal);
		}
		else
			;
	}

	void jogo::guardaProdutos(int totalProdutos)
	{
		int armazem = Imperio->getArmazem();
		int armazemTotal;
		int diferenca2;

		int armazemMaximo = verificaProdutosMaximo();
		diferenca2 = armazemMaximo - armazem;
		if (armazem >= 0 && armazem < armazemMaximo && totalProdutos >= armazemMaximo)
		{
			armazemTotal = armazemMaximo;
			Imperio->setArmazem(armazemTotal);
		}
		else if (armazem >= 0 && armazem < armazemMaximo && totalProdutos < armazemMaximo && diferenca2 >= totalProdutos)
		{
			armazemTotal = armazem + totalProdutos;
			Imperio->setArmazem(armazemTotal);
		}
		else if (armazem >= 0 && armazem < armazemMaximo && totalProdutos < armazemMaximo && diferenca2 < totalProdutos)
		{
			armazemTotal = armazem + diferenca2;
			Imperio->setArmazem(armazemTotal);
		}
		else
			;
	}

	void jogo::listaRecursos()
	{
		cout << "Produtos no Armazem: " << Imperio->getArmazem() << " Produtos Maximo: " << verificaProdutosMaximo() << endl;
		cout << "Ouro no Cofre: " << Imperio->getCofre() << " Ouro Maximo: " << verificaOuroMaximo() << endl;
	}

	void jogo::resetaOuro(vector<Territorio *> terrs)
	{
		for (int i = 0; i < terrs.size(); i++)
		{
			terrs[i]->setOuro(0);
		}
	}

	void jogo::resetaProdutos(vector<Territorio *> terrs)
	{
		for (int i = 0; i < terrs.size(); i++)
		{
			terrs[i]->setProdutos(0);
		}
	}

	void jogo::maisOuro()
	{
		int ouro = Imperio->getCofre(), produtos = Imperio->getArmazem();
		;

		if (procuraTecnologia("Banco Central") == 1)
		{
			if (ouro >= 0 && ouro < 5 && produtos >= 2)
			{
				ouro++;
				produtos = produtos - 2;
				Imperio->setCofre(ouro);
				Imperio->setArmazem(produtos);
				cout << "Ouro aumentado com sucesso!!\n\n"
					 << endl;
			}
			else
			{
				cout << "Nao e possivel fazer esta troca !!\n"
					 << endl;
			}
		}
		else
		{
			if (ouro >= 0 && ouro < 3 && produtos >= 2)
			{
				ouro++;
				produtos = produtos - 2;
				Imperio->setCofre(ouro);
				Imperio->setArmazem(produtos);
				cout << "Ouro aumentado com sucesso!!\n\n"
					 << endl;
			}
			else
			{
				cout << "Nao e possivel fazer esta troca !!\n"
					 << endl;
			}
		}
	}

	void jogo::maisProdutos()
	{
		int ouro = Imperio->getCofre(), produtos = Imperio->getArmazem();
		;

		if (procuraTecnologia("Banco Central") == 1)
		{
			if (produtos >= 0 && produtos < 5 && ouro >= 2)
			{
				produtos++;
				ouro = ouro - 2;
				Imperio->setCofre(ouro);
				Imperio->setArmazem(produtos);
				cout << "Produtos aumentado com sucesso!!\n\n"
					 << endl;
			}
			else
			{
				cout << "Nao e possivel fazer esta troca !!\n"
					 << endl;
			}
		}
		else
		{
			if (produtos >= 0 && produtos < 3 && ouro >= 2)
			{
				produtos++;
				ouro = ouro - 2;
				Imperio->setCofre(ouro);
				Imperio->setArmazem(produtos);
				cout << "Produtos aumentado com sucesso!!\n\n"
					 << endl;
			}
			else
			{
				cout << "Nao e possivel fazer esta troca !!\n"
					 << endl;
			}
		}
	}

	void jogo::compraTecnologia(string nome)
	{
		int cofre = Imperio->getCofre();

		for (int i = 0; i < tecnologias.size(); i++)
		{
			if (tecnologias[i]->getNome() == nome)
			{
				if (cofre >= tecnologias[i]->getPreco())
				{
					string temp = " Adquirida";
					cout << "Tecnologia comprada com sucesso !\n"
						 << endl;
					tecnologias[i]->setEstado(temp);
					Imperio->preencheTecs(new Tecnologia(tecnologias[i]->getNome(), tecnologias[i]->getPreco(), tecnologias[i]->getObjetivo(), tecnologias[i]->getEstado()));
					cofre = cofre - tecnologias[i]->getPreco();
					Imperio->setCofre(cofre);
				}
				else
				{
					cout << "Nao possui dinheiro suficiente no cofre para poder comprar esta tecnologia !!\n"
						 << endl;
				}
			}
			else
				;
		}
	}

	void jogo::maisMilitar()
	{
		int militar = Imperio->getforcaMilitar();
		int cofre = Imperio->getCofre();
		int armazem = Imperio->getArmazem();

		int forcaMaxima = verificaforcaMaxima();

		if (cofre > 0 && armazem > 0)
		{
			if (militar >= 0 && militar < forcaMaxima)
			{
				cofre--;
				armazem--;
				militar++;
				Imperio->setCofre(cofre);
				Imperio->setArmazem(armazem);
				Imperio->setforcaMilitar(militar);
				cout << "Forca militar aumentada com sucesso !!\n"
					 << endl;
			}
			else
			{
				cout << "Ja atingiu o maximo de forca militar!!\n"
					 << endl;
			}
		}
		else
		{
			cout << "Nao tem recursos necessarios para aumentar a sua forca militar !!\n"
				 << endl;
		}
	}

	int jogo::verificaforcaMaxima()
	{
		int forcaMaxima;

		if (procuraTecnologia("Drones Militares") == 1)
		{
			forcaMaxima = 5;
			return forcaMaxima;
		}
		else
		{
			forcaMaxima = 3;
			return forcaMaxima;
		}
	}

	int jogo::verificaOuroMaximo()
	{
		int ouroMaximo;
		if (procuraTecnologia("Banco Central") == 1)
		{
			ouroMaximo = 5;
			return ouroMaximo;
		}
		else
		{
			ouroMaximo = 3;
			return ouroMaximo;
		}
	}

	int jogo::verificaProdutosMaximo()
	{
		int prodMaximo;
		if (procuraTecnologia("Banco Central") == 1)
		{
			prodMaximo = 5;
			return prodMaximo;
		}
		else
		{
			prodMaximo = 3;
			return prodMaximo;
		}
	}

	void jogo::eventoRandom(int ano)
	{
		int random;

		srand(time(NULL));

		random = 0 + (rand() % eventos.size());

		if (eventos[random]->getNomeEvento() == "Recurso Abandonado")
		{
			cout << " Evento que ocorreu -------> Recurso Abandonado" << endl;
			cout << " Descricao: " << eventos[random]->getDescricao();
			cout << "\n\n";
			recursoAbandonado(ano);
		}
		else if (eventos[random]->getNomeEvento() == "Invasao")
		{
			cout << " Evento que ocorreu -------> Invasao" << endl;
			cout << " Descricao: " << eventos[random]->getDescricao();
			cout << "\n\n";
			Invasao(ano);
		}
		else if (eventos[random]->getNomeEvento() == "Alianca Diplomatica")
		{
			cout << " Evento que ocorreu -------> Alianca Diplomatica" << endl;
			cout << " Descricao: " << eventos[random]->getDescricao();
			cout << "\n\n";
			aliancaDiplomatica();
		}
		else if (eventos[random]->getNomeEvento() == "Sem Evento")
		{
			cout << " Evento que ocorreu -------> Sem Evento" << endl;
			cout << " Descricao: " << eventos[random]->getDescricao();
			cout << "\n\n";
		}
		else
			;
	}

	void jogo::recursoAbandonado(int ano)
	{
		int cofre = Imperio->getCofre();
		int armazem = Imperio->getArmazem();
		if (ano == 1)
		{
			if (armazem >= 0 && armazem < verificaProdutosMaximo())
			{
				armazem++;
				Imperio->setArmazem(armazem);
			}
			else
			{
				cout << "O Armazem ja esta cheio de produtos!!\n"
					 << endl;
			}
		}
		else if (ano == 2)
		{
			if (cofre >= 0 && cofre < verificaOuroMaximo())
			{
				cofre++;
				Imperio->setCofre(cofre);
			}
			else
			{
				cout << "O Cofre ja esta cheio de ouro!!\n"
					 << endl;
			}
		}
		else
			;
	}

	void jogo::aliancaDiplomatica()
	{
		int militar = Imperio->getforcaMilitar();
		if (militar >= 0 && militar < verificaforcaMaxima())
		{
			militar++;
			Imperio->setforcaMilitar(militar);
		}
		else
		{
			cout << "A forca militar ja esta no maximo!!\n"
				 << endl;
		}
	}

	void jogo::Invasao(int ano)
	{
		int forcaInvasao, fatorSorte, forcaTotal, res;

		forcaInvasao = obtemforcaInvasao(ano);
		srand(time(NULL));
		fatorSorte = 1 + (rand() % 6);
		forcaTotal = forcaInvasao + fatorSorte;

		int n = getVectorTerrImperio().size();

		if (procuraTecnologia("Defesas Territoriais") == 1)
		{
			res = getVectorTerrImperio()[n - 1]->getResistencia();
			res++;
			getVectorTerrImperio()[n - 1]->setResistencia(res);

			cout << "A forca de invasao foi: " << forcaTotal << endl;
			cout << "A resistencia do imperio nesta invasao foi: " << getVectorTerrImperio()[n - 1]->getResistencia() << endl;
			cout << "\n";

			if (forcaTotal >= getVectorTerrImperio()[n - 1]->getResistencia() && getVectorTerrImperio()[n - 1]->getNome() == "Inicial")
			{
				Imperio->deleteLast();
				cout << "Perdeu todos os seus territorios. O jogo acabou e a sua pontuacao foi de:  " << endl; /*meter pontuacao*/
				cout << "\n";
				exit(0);
			}
			else if (forcaTotal >= getVectorTerrImperio()[n - 1]->getResistencia())
			{
				Imperio->deleteLast();
				cout << "Invasao feita com sucesso!!. Acabou de perder o seu territorio mais recente !!\n"
					 << endl;
			}
			else
			{
				cout << "A invasao feita ao seu territorio falhou !!\n"
					 << endl;
			}
		}
		else
		{
			cout << "A forca de invasao foi: " << forcaTotal << endl;
			cout << "A resistencia do imperio nesta invasao foi: " << getVectorTerrImperio()[n - 1]->getResistencia() << endl;
			cout << "\n";

			if (forcaTotal >= getVectorTerrImperio()[n - 1]->getResistencia() && getVectorTerrImperio()[n - 1]->getNome() == "Inicial")
			{
				Imperio->deleteLast();
				cout << "Perdeu todos os seus territorios. O jogo acabou e a sua pontuacao foi de:  " << pontuacaoTotal() << endl;
				cout << "\n";
				exit(0);
			}
			else if (forcaTotal >= getVectorTerrImperio()[n - 1]->getResistencia())
			{
				Imperio->deleteLast();
				cout << "Invasao feita com sucesso!!. Acabou de perder o seu territorio mais recente !!\n"
					 << endl;
			}
			else
			{
				cout << "A invasao feita ao seu territorio falhou !!\n"
					 << endl;
			}
		}
	}

	int jogo::obtemforcaInvasao(int ano)
	{
		int forca;

		if (ano == 1)
		{
			forca = 2;
			return forca;
		}
		else if (ano == 2)
		{
			forca = 3;
			return forca;
		}
	}


	int jogo::pontuacaoTotal()
	{
		int pontuacao = 0;

		pontuacao = pontuacaoTerritorios() + pontuacaoTecnologia() + pontuacaotodasTecnologias() + pontuacaotodosTerritorios();
	}

	int jogo::pontuacaoTerritorios()
	{
		int pontuacao = 0;

		for (int i = 0; i < getVectorTerrImperio().size(); i++)
		{
			pontuacao = pontuacao + getVectorTerrImperio()[i]->getPontos();
		}
		return pontuacao;
	}

	int jogo::pontuacaotodasTecnologias()
	{
		int pontuacao;

		if (Imperio->getVectorTecsImperio().size() == 5)
		{
			pontuacao = 1;
			return pontuacao;
		}
		else
		{
			pontuacao = 0;
			return pontuacao;
		}
	}
	

	int jogo::pontuacaoTecnologia()
	{
		int pontuacao = Imperio->getVectorTecsImperio().size();
		return pontuacao;
	}

	int jogo::pontuacaotodosTerritorios()
	{
		int pontuacao;
		if (getVectorTerritorio().empty())
		{
			pontuacao = 3;
			return pontuacao;
		}
		else
		{
			pontuacao = 0;
			return pontuacao;
		}
	}

	vector<Territorio*> jogo::getVectorTerrImperio()
	{
		return Imperio->getVectorTerrImperio();
	}

	void jogo::tomaTecnologia(string nome)
	{
		for (int i = 0; i < tecnologias.size(); i++)
		{
			if (tecnologias[i]->getNome() == nome)
			{
				if(procuraTecnologia(nome) == 0)
				{
					string temp = " Adquirida";
					cout << "Sucesso !!\n"
					 << endl;
					tecnologias[i]->setEstado(temp);
					Imperio->preencheTecs(new Tecnologia(tecnologias[i]->getNome(), tecnologias[i]->getPreco(), tecnologias[i]->getObjetivo(), tecnologias[i]->getEstado()));
				}
				else
				{
					cout << "\nJa possui esta tecnologia !!\n" << endl;
				}
				
			}
			else
				;
		}
	}

	void jogo::tomaTerritorio(string nome)
	{
		for (int i = 0; i < territorios.size(); i++)
		{
			if (territorios[i]->getnomeConca() == nome && territorios[i]->getTipo() =="Continente")
			{
				cout << "Sucesso !!\n"
					 << endl;
				territorios[i]->setTurnoConquista(turno);
				Imperio->preencheContinente(new Continente(territorios[i]->getNome(), territorios[i]->getTipo(), territorios[i]->getResistencia(), territorios[i]->getProdutos(), territorios[i]->getOuro(), territorios[i]->getPontos(),territorios[i]->getN(),territorios[i]->getTurnoConquista()));
				territorios.erase(territorios.begin() + i);
			}
			if(territorios[i]->getnomeConca() == nome && territorios[i]->getTipo() =="Ilha")
			{
				cout << "Sucesso !!\n"
					 << endl;
				Imperio->preencheIlha(new Ilha(territorios[i]->getNome(), territorios[i]->getTipo(), territorios[i]->getResistencia(), territorios[i]->getProdutos(), territorios[i]->getOuro(), territorios[i]->getPontos(),territorios[i]->getN()));
				territorios.erase(territorios.begin() + i);
			}
			else;

		}
				
	}

	int jogo::buscaIlha(string nome)
	{
		int n = 0;
		for (int i = 0; i < territorios.size(); i++)
		{
			if (territorios[i]->getnomeConca() == nome && territorios[i]->getTipo() == "Continente")
			{
				n = 0;
			}
			else if (territorios[i]->getnomeConca() == nome && territorios[i]->getTipo() == "Ilha")
			{
				n++;
			}
			else
				;
		}
		return n;
	}

	int jogo::buscaTerritorio(string nome)
	{
		int n = 0;
		for (int i = 0; i < territorios.size(); i++)
		{
			if (territorios[i]->getnomeConca() == nome)
			{
				n++;
			}
			else
				;
		}
		return n;
	}

	int jogo::buscaTecnologia(string nome)
	{
		int n = 0;
		for (int i = 0; i < tecnologias.size(); i++)
		{
			if (tecnologias[i]->getNome() == nome)
			{
				n++;
			}
			else
			{
				n = 0;
			}
		}
		return n;
	}

vector<Tecnologia*> jogo::getVectorTecImperio()
{
	return Imperio->getVectorTecsImperio();
}


jogo::~jogo()
{


	for (int i = 0; i < territorios.size(); i++)
	{
		delete territorios[i];
	}

	for(int i = 0; i < tecnologias.size(); i++)
	{
		delete tecnologias[i];
	}


}

jogo::jogo(jogo& copia_jogo)
{
	//Imperio = copia_jogo.Imperio; 
	Imperio = new Imperio(*copia_jogo.Imperio); 
		

	for(int i = 0; i < copia_jogo.territorios.size(); i++)
	{
		adicionaTerritorio(copia_jogo.territorios[i]->duplica());

		if(copia_jogo.territorios[i]->getTipo() == "Continente")
		{
			adicionaTerritorio(new Continente(copia_jogo.territorios[i]->getNome(),copia_jogo.territorios[i]->getTipo(),copia_jogo.territorios[i]->getResistencia(),copia_jogo.territorios[i]->getProdutos(),copia_jogo.territorios[i]->getOuro(),copia_jogo.territorios[i]->getPontos(),copia_jogo.territorios[i]->getN(),copia_jogo.territorios[i]->getTurnoConquista()));
		}
		if(copia_jogo.territorios[i]->getTipo() == "Ilha")
		{
			adicionaTerritorio(new Ilha(copia_jogo.territorios[i]->getNome(),copia_jogo.territorios[i]->getTipo(),copia_jogo.territorios[i]->getResistencia(),copia_jogo.territorios[i]->getProdutos(),copia_jogo.territorios[i]->getOuro(),copia_jogo.territorios[i]->getPontos(),copia_jogo.territorios[i]->getN()));
		}
		
	}

	
	for(int i = 0; i < copia_jogo.tecnologias.size(); i++)
	{
		adicionaTecnologia(new Tecnologia(copia_jogo.tecnologias[i]->getNome(),copia_jogo.tecnologias[i]->getPreco(),copia_jogo.tecnologias[i]->getObjetivo(),copia_jogo.tecnologias[i]->getEstado()));
	}

	ano = copia_jogo.ano;
	fase = copia_jogo.fase;
	turno = copia_jogo.turno;

	//Imperio = nullptr;


}