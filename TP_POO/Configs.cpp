/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Configs.cpp
 * Author: FNAC
 * 
 * Created on 10 de novembro de 2020, 17:41
 */

#include "Configs.h"

using namespace std;

int Configs::num_id = 1;

Configs::Configs()
{
	game = new jogo();
}

Configs::~Configs()
{
	delete game;
}

int Configs::setTamanho(int tamanho)
{
	this->tamanho = tamanho;
}

int Configs::procuraJogo(string nome)
{
	for (int i = 0; i < gestorjogo.size(); i++)
	{
		if (gestorjogo[i].nome == nome)
			return 1;
	}
	return 0;
}

void Configs::gravajogo(string nome,jogo* aux)
{
	jogo copia = *aux;
	guarda_jogo savegame = {&copia,nome};
	gestorjogo.push_back(savegame);
	cout << "Jogo Gravado com sucesso!!" << endl;
	
}

void Configs::apagajogo(string nome)
{
	for (int i = 0; i < gestorjogo.size(); i++)
	{
		if (nome == gestorjogo[i].nome)
		{
			gestorjogo.erase(gestorjogo.begin() + i);
			cout << "Jogo apagado com sucesso !!\n\n"
				 << endl;
			return;
		}
	}
	cout << "Nao existe nenhum jogo chamado:" << nome << endl;
	return;
}

void Configs::ativajogo(string nome,jogo* aux)
{
	if(gestorjogo.size() == 0)
	{
		cout << "Nao existem jogos gravados!!" << endl;
	}
	else
	{
		for(int i = 0; i < gestorjogo.size(); i++)
		{
			if(gestorjogo[i].nome == nome)
			{
				aux = gestorjogo[i].gamez;
				return;
			}
			
		}
		cout << "Nao existe um jogo com esse nome !!\n" << endl;
	}
	
	
}
//Menu principal

void Configs::comecar()
{
	system("cls");
	int turno = 1, fase = 1, ano = 1;
	string comando;
	vector<string> subcomando;
	game->preencheEventos(new Eventos("Recurso Abandonado", "Fornece uma unidade de produto no 1 ano e uma unidade de ouro no 2 ano"));
	game->preencheEventos(new Eventos("Invasao", "Um dos territorios do Imperio esta a ser invadido por outro Imperio Concorrente"));
	game->preencheEventos(new Eventos("Alianca Diplomatica", "O Imperio alia-se a outro ganhando uma unidade de forca militar"));
	game->preencheEventos(new Eventos("Sem Evento", "Nada Acontece e todos podem dormir descansados"));

	cout << "\n\n\n";

	cout << "  -----------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "  ----------------------------------------->       Jogo de Conquista de Territorios       <------------------------------------" << endl;
	cout << "\n\n\n";
	cout << "                                       ---------------->     Menu Inicial      <----------------                               " << endl;
	cout << "\n\n\n";
	cout << "  -> Seja bem vindo ao jogo [Conquista de Territorios] !!\n"
		 << endl;
	cout << "  -> Neste jogo ira poder conquistar territorios com ajuda de tecnologias e poder militar e formar um imperio rico de recursos !!\n"
		 << endl;

	cout << "  -> Nesta configuracao inicial apenas podera introduzir comandos de debug/lista e comandos cria e carrega.\n\n"
		 << endl;
	do
	{
		cout << "Insira o comando: ";
		
		getline(cin, comando);
		for (int i = 0; i < comando.size(); i++)

			subcomando = divideString(comando);
		cout << "\n";

	} while (leComando(subcomando));
}

//Inicia o jogo com as fases depois do comando avanca

int Configs::iniciaJogo()
{
	string comando;
	vector<string> subcomando;
	int turno, ano, fase, turnoAux = 1;
	int temp = tamanho;
	int temp2 = tentativa;
	int temp3 = tentativaRecursos;

	turno = game->getTurno();
	ano = game->getAno();
	fase = game->getFase();

	system("cls");
	cout << "\n"
		 << endl;
	cout << "O jogo comecou !! " << endl;
	cout << "\n"
		 << endl;

	do
	{

		do
		{
			do
			{
				if (fase == 1)
				{
					cout << "\n"
						 << endl;
					cout << "-------------------------------------------------------------------------------------" << endl;
					cout << "\n"
						 << endl;
					cout << "Ano : " << game->getAno() << endl;
					cout << "Fase " << game->getFase() << " do Turno " << game->getTurno() << endl;
					cout << "\n\n"
						 << endl;
					cout << "Nesta fase podera efetuar comandos de debug/listar e escolher conquistar um territorio ou passar o mesmo !!\n"
						 << endl;
					do
					{
						cout << "Insira o comando: ";

						getline(cin, comando);
						for (int i = 0; i < comando.size(); i++)

							subcomando = divideString(comando);
						cout << "\n";

					} while (leComando2(subcomando));
					turnoAux = turno;
					do
					{
						cout << "Insira o comando: ";

						getline(cin, comando);
						for (int i = 0; i < comando.size(); i++)

							subcomando = divideString(comando);
						cout << "\n";

					} while (leComandoAvanca(subcomando));
				}
				else if (fase == 2)
				{
					temp3 = tentativaRecursos;
					system("cls");
					string escolha;
					game->geraRecursosTerritorios(turno, ano, game->getVectorTerritorio(), turnoAux);
					game->geraRecursosTerritorios(turno, ano, game->getVectorTerrImperio(), turnoAux);
					game->guardaOuro(game->ouroTotal());
					game->guardaProdutos(game->produtosTotal());
					cout << "\n"
						 << endl;
					cout << "-------------------------------------------------------------------------------------" << endl;
					cout << "\n"
						 << endl;
					cout << "Ano : " << game->getAno() << endl;
					cout << "Fase " << game->getFase() << " do Turno " << game->getTurno() << endl;
					cout << "\n\n"
						 << endl;
					cout << "Nesta fase sera feita a recolha de ouro e produtos e vao ser utilizados comandos para aumenta-los\n"
						 << endl;

					do
					{
						cout << "Insira o comando: ";

						getline(cin, comando);
						for (int i = 0; i < comando.size(); i++)

							subcomando = divideString(comando);
						cout << "\n";

					} while (leComando3(subcomando,temp3));
				}
				else if (fase == 3)
				{
					system("cls");
					temp = tamanho;
					temp2 = tentativa;
					cout << "\n"
						 << endl;
					cout << "-------------------------------------------------------------------------------------" << endl;
					cout << "\n"
						 << endl;
					cout << "Ano : " << game->getAno() << endl;
					cout << "Fase " << game->getFase() << " do Turno " << game->getTurno() << endl;
					cout << "\n\n"
						 << endl;
					cout << "Nesta fase podera comprar tecnologias novas e/ou adquirir mais poder militar" << endl;
					do
					{
						cout << "Insira o comando: ";

						getline(cin, comando);

						for (int i = 0; i < comando.size(); i++)

							subcomando = divideString(comando);
						cout << "\n";

					} while (leComando4(subcomando, temp,temp2));
				}
				else if (fase == 4)
				{
					system("cls");
					cout << "\n"
						 << endl;
					cout << "-------------------------------------------------------------------------------------" << endl;
					cout << "\n"
						 << endl;
					cout << "Ano : " << game->getAno() << endl;
					cout << "Fase " << game->getFase() << " do Turno " << game->getTurno() << endl;
					cout << "\n\n"
						 << endl;
					cout << "Nesta fase ira ocorrer um evento aleatoriamente" << endl;
					game->eventoRandom(ano);
					do
					{
						cout << "Insira o comando: ";

						getline(cin, comando);
						for (int i = 0; i < comando.size(); i++)

							subcomando = divideString(comando);
						cout << "\n";

					} while (leComandoAvanca(subcomando));
				}
				else
					;
				fase++;
				game->setFase(fase);
			} while (fase <= 4);
			system("cls");
			game->resetaOuro(game->getVectorTerrImperio());
			game->resetaOuro(game->getVectorTerritorio());
			game->resetaProdutos(game->getVectorTerrImperio());
			game->resetaProdutos(game->getVectorTerritorio());
			fase = 1;
			game->setFase(fase);
			turno++;
			turnoAux++;
			game->setTurno(turno);
		} while (turno <= 6);
		system("cls");
		turno = 1;
		game->setTurno(turno);
		ano++;
		game->setAno(ano);
	} while (ano <= 2);

	system("cls");

	cout << "\n";
	
	acabaJogo();
	exit(0);
}

int Configs::acabaJogo()
{
	cout << "---------------------------------------------------------->\n" << endl;
	cout << "O Jogo acabou !! A sua pontuacao final foi : " << game->pontuacaoTotal() << endl;
	cout << "\n" << endl;

	cout << "Os seus dados de jogo finais sao os seguintes: \n\n" << endl;

	cout << "<------Territorios do Seu Imperio----->" << endl;
	game->listarTerritorios(game->getVectorTerrImperio());
	cout << "\n\n";
	cout << "<------Tecnologias do Seu Imperio----->" << endl;
	game->listarTecsImperio();
	cout << "\n\n";
	cout << "<-------Recursos do Seu Imperio------->" << endl;
	game->listaRecursos();
	game->ListarforcaMilitar();
	cout <<"\n\n";
		 
}
//Le os comandos da configuração inicial

int Configs::leComando(vector<string> subcomando)
{


	if (subcomando.size() != 0)
	{
		if (subcomando[0] == "carrega")
		{
			if (subcomando.size() == 2)
			{

				if (subcomando[1] == "Territorio.txt")
				{

					carregaTerritorio(subcomando[1]);
					return 1;
				}
				if (subcomando[1] == "tecnologias.txt")
				{
					if (game->getVectorTecnologia().empty())
					{
						carregaTecnologia(subcomando[1]);
						return 1;
					}
					else
					{
						cout << "Ja introduziu esse ficheiro !!" << endl;
						cout << "\n";
						return 1;
					}
				}
				else
				{
					cout << "Nao existe o ficheiro que introduziu" << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado!\n"
					 << endl;
				return 1;
			}

			return 1;
		}
	}

	if (subcomando[0] == "cria") //Mal feito
	{
		int n;

		if (subcomando.size() == 1)
		{
			cout << "Comando mal implementado!\n"
				 << endl;
			return 1;
		}
		//cria territorios
		if (subcomando[1] == "Planicie" || subcomando[1] == "Montanha" || subcomando[1] == "Fortaleza" || subcomando[1] == "Mina" || subcomando[1] == "Duna" || subcomando[1] == "Castelo")
		{
			if (subcomando.size() == 3)
			{

				if (atoi(subcomando[2].c_str()) > 0) //rever esta parte
				{

					int extra = game->verificaN(subcomando[1]);

					n = atoi(subcomando[2].c_str());
					do
					{
						extra++;
						game->adicionaTerritorio(new Continente(subcomando[1], "Continente", 0, 0, 0, 1, extra,0));

						n--;
					} while (n > 0);
				}
				else
				{
					cout << "Comando mal implementado" << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado!\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Pescaria") // completar refugio dos piratas
		{
			if (subcomando.size() == 3)
			{
				if (atoi(subcomando[2].c_str()) > 0)
				{
					int extra = game->verificaN(subcomando[1]);
					int n = atoi(subcomando[2].c_str());
					do
					{
						extra++;
						game->adicionaTerritorio(new Ilha(subcomando[1], "Ilha", 0, 0, 0, 2, extra));

						n--;

					} while (n > 0);
				}
				else
				{
					cout << "Comando mal implementado" << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado" << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Refugio" && subcomando[2] == "dos" && subcomando[3] == "Piratas")
		{
			string temp;
			temp = subcomando[1] + ' ' + subcomando[2] + ' ' + subcomando[3];
			if (subcomando.size() == 5)
			{
				if (atoi(subcomando[4].c_str()) > 0)
				{
					int extra = game->verificaN(temp);
					int n = atoi(subcomando[4].c_str());
					do
					{
						extra++;
						game->adicionaTerritorio(new Ilha(temp, "Ilha", 0, 0, 0, 2, extra));

						n--;

					} while (n > 0);
				}
				else
				{
					cout << "Comando mal implementado" << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado" << endl;
				return 1;
			}
		}
		else
		{
			cout << "Tipo de Territorio Invalido" << endl;
			return 1;
		}
		return 1;
	}

	if (subcomando[0] == "lista")
	{
		if (subcomando.size() == 1)
		{
				
				system("cls");
				cout << "  <----------------------------------- Territorios Existentes por conquistar ------------------------------->" << endl;
				cout << "\n";
				game->listarTerritorios(game->getVectorTerritorio());
				cout << "\n";
				cout << "  <----------------------------------- Informacoes do Imperio ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTerritorios(game->getVectorTerrImperio());
				cout << "\n";
				cout << "  <--------------------------------------------------------------------------------------------------------->" << endl;
				cout << "\n";
				game->listaRecursos();
				game->ListarforcaMilitar();
				cout << "\n";
				cout << "  <----------------------------------- Tecnologias do Imperio ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTecsImperio();
				cout << "\n";
				cout << "  <----------------------------------- Tecnologias existentes ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTecnologias();
				cout << "\n";
				cout << "  <----------------------------------- Eventos Que Podem Ocorrer-------------------------------------------->" << endl;
				cout << "\n";
				game->listarEventos();
				cout << "\n";
				return 1;
		}
		else if (subcomando[1] == "Refugio")
		{
			if (subcomando.size() == 4)
			{
				string temp2;
				temp2 = subcomando[1] + ' ' + subcomando[2] + ' ' + subcomando[3];
				game->listaumTerritorio(temp2, game->getVectorTerrImperio());
				game->listaumTerritorio(temp2, game->getVectorTerritorio());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado" << endl;
				return 1;
			}
		}
		else
		{
			if (subcomando.size() == 2)
			{
				game->listaumTerritorio(subcomando[1], game->getVectorTerrImperio());
				game->listaumTerritorio(subcomando[1], game->getVectorTerritorio());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado" << endl;
				return 1;
			}
		}
		return 1;
	}

	if (subcomando[0] == "avanca")
	{
		if (game->getVectorTecnologia().empty() && game->getVectorTerritorio().empty())
		{
			cout << "Nao existem territorios por conquistar nem tecnologias para adquirir. Aplique os comandos carrega e criar !!\n"
				 << endl;
			return 1;
		}
		else if (game->getVectorTerritorio().empty() && !game->getVectorTecnologia().empty())
		{
			cout << "Nao existem territorios por conquistar !! Aplique os comandos carrega e criar\n"
				 << endl;
			return 1;
		}
		else if (!game->getVectorTerritorio().empty() && game->getVectorTecnologia().empty())
		{
			cout << "Nao existem tecnologias para adquirir !! Aplique o comando carrega\n"
				 << endl;
			return 1;
		}
		else
		{
			iniciaJogo();
		}
	}

	if (subcomando[0] == "toma")
	{
			if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando[1] == "terr")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}


			if (subcomando[2] == "Refugio")
			{
				if (subcomando.size() == 5)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3] + ' ' + subcomando[4];
					game->tomaTerritorio(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				if (subcomando.size() == 3)
				{
					game->tomaTerritorio(subcomando[2]);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
		}
		else if (subcomando[1] == "tec")
		{
			if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando[2] == "Bolsa" && subcomando[3] == "de" && subcomando[4] == "Valores")
			{
				if (subcomando.size() == 5)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3] + ' ' + subcomando[4];
					game->tomaTecnologia(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				if (subcomando.size() == 4)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3];
					game->tomaTecnologia(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n"
				 << endl;
			return 1;
		}
	}

	if (subcomando[0] == "modifica")
	{
		int n;
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando[1] == "ouro")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando.size() == 3)
			{
				if (atoi(subcomando[2].c_str()) >= 0 && atoi(subcomando[2].c_str()) <= game->verificaOuroMaximo())
				{
					n = atoi(subcomando[2].c_str());
					game->setCofre(n);
					return 1;
				}
				else
				{
					cout << "Excede o limite maximo de ouro para o cofre. !\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado !!\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "prod")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando.size() == 3)
			{
				if (atoi(subcomando[2].c_str()) >= 0 && atoi(subcomando[2].c_str()) <= game->verificaProdutosMaximo())
				{
					n = atoi(subcomando[2].c_str());
					game->setArmazem(n);
					return 1;
				}
				else
				{
					cout << "Excede o limite maximo de produtos para o armazem. !\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado !!\n"
					 << endl;
				return 1;
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n"
				 << endl;
			return 1;
		}
	}

	if (subcomando[0] == "fevento")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "Invasao")
		{
			if (subcomando.size() == 2)
			{
				game->Invasao(game->getAno());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Recurso" && subcomando[2] == "Abandonado")
		{
			if (subcomando.size() == 3)
			{
				game->recursoAbandonado(game->getAno());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Alianca" && subcomando[2] == "Diplomatica")
		{
			if (subcomando.size() == 3)
			{
				game->aliancaDiplomatica();
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Sem" && subcomando[2] == "Evento")
		{
			if (subcomando.size() == 3)
			{
				cout << "Nada acontece, todos podem dormir descansados !!\n\n"
					 << endl;
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else
		{
			cout << "Nao existe um evento com esse nome !!\n\n"
				 << endl;
		}
	}

	if (subcomando[0] == "grava")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			if (procuraJogo(subcomando[1]) == 1)
			{
				gravajogo(modificaIgual(subcomando[1]),game);
				return 1;
			}
			else
			{
				gravajogo(subcomando[1],game);
				return 1;
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n\n"
				 << endl;
				 return 1;
		}
	}

	if (subcomando[0] == "ativa")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			ativajogo(subcomando[1],game);
			return 1;
		}
		else
		{
			cout << "Comando mal implementado" << endl;
			return 1;
		}
	}

	if (subcomando[0] == "apaga")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			apagajogo(subcomando[1]);
			return 1;
		}
		else
		{
			cout << "Comando mal implementado" << endl;
			return 1;
		}
	}

	return 1;
}

//Le os comandos da Fase 1 do Jogo(conquista ou passa)

int Configs::leComando2(vector<string> subcomando)
{
	if (subcomando[0] == "conquista")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "Refugio")
		{
			string temp;
			temp = subcomando[1] + ' ' + subcomando[2] + ' ' + subcomando[3];
			if (game->buscaTerritorio(temp) == 0)
			{
				cout << "Nao existe um territorio com esse nome!!\n\n"
					 << endl;
				return 1;
			}
			else
			{
				if (game->buscaIlha(temp) == 1)
				{
					if (subcomando.size() == 4)
					{
						if (game->getVectorTerritorio().empty())
						{
							cout << "Nao existem mais territorios para conquistar !! Venceu o jogo !!\n"
								 << endl;
							return 0;
						}
						else
						{
							if (game->procuraTecnologia("Misseis Teleguiados") == 1 && game->getVectorTerrImperio().size() >= 5)
							{
								game->conquistaTerritorio(temp);
								return 0;
							}
							else
							{
								cout << "Nao possui os requesitos para conquistar uma ilha !!\n\n"
									 << endl;
								return 1;
							}
						}
					}
					else
					{
						cout << "Comando mal implementado" << endl;
						return 1;
					}
					return 1;
				}
				else
					;
				return 1;
			}
		}
		else
		{
			if (game->buscaTerritorio(subcomando[1]) == 0)
			{
				cout << "Nao existe um territorio com esse nome!!\n\n"
					 << endl;
				return 1;
			}
			else
			{
				if (game->buscaIlha(subcomando[1]) == 1)//Busca ilha da return a um valor dependendo se for continente ou ilha
				{
					if (subcomando.size() == 2)
					{
						if (game->getVectorTerritorio().empty())
						{
							cout << "Nao existem mais territorios para conquistar !! Venceu o jogo !!\n"
								 << endl;
							return 0;
						}
						else
						{
							if (game->procuraTecnologia("Misseis Teleguiados") == 1 && game->getVectorTerrImperio().size() >= 5)
							{
								game->conquistaTerritorio(subcomando[1]);
								return 0;
							}
							else
							{
								cout << "Nao possui os requesitos para conquistar uma ilha !!\n\n"
									 << endl;
								return 1;
							}
						}
					}
					else
					{
						cout << "Comando mal implementado" << endl;
						return 1;
					}
				}
				else
				{
					if (subcomando.size() == 2)
					{
						if (game->getVectorTerritorio().empty())
						{
							cout << "Nao existem mais territorios para conquistar !! Venceu o jogo !!\n"
								 << endl;
							return 0;
						}
						else
						{
							game->conquistaTerritorio(subcomando[1]);
							return 0;
						}
					}
					else
					{
						cout << "Comando mal implementado" << endl;
						return 1;
					}
				}
				return 1;
			}
			return 1;
		}
	}

	if (subcomando[0] == "passa")
	{
		cout << "Fase passada com sucesso !!\n"
			 << endl;
		return 0;
	}

	if (subcomando[0] == "lista")
	{
		if (subcomando.size() == 1)
		{
				
				system("cls");
				cout << "  <----------------------------------- Territorios Existentes por conquistar ------------------------------->" << endl;
				cout << "\n";
				game->listarTerritorios(game->getVectorTerritorio());
				cout << "\n";
				cout << "  <----------------------------------- Informacoes do Imperio ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTerritorios(game->getVectorTerrImperio());
				cout << "\n";
				cout << "  <--------------------------------------------------------------------------------------------------------->" << endl;
				cout << "\n";
				game->listaRecursos();
				game->ListarforcaMilitar();
				cout << "\n";
				cout << "  <----------------------------------- Tecnologias do Imperio ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTecsImperio();
				cout << "\n";
				cout << "  <----------------------------------- Tecnologias existentes ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTecnologias();
				cout << "\n";
				cout << "  <----------------------------------- Eventos Que Podem Ocorrer-------------------------------------------->" << endl;
				cout << "\n";
				game->listarEventos();
				cout << "\n";
				return 1;
		}
		else if (subcomando[1] == "Refugio")
		{
			if (subcomando.size() == 4)
			{
				string temp2;
				temp2 = subcomando[1] + ' ' + subcomando[2] + ' ' + subcomando[3];
				game->listaumTerritorio(temp2, game->getVectorTerrImperio());
				game->listaumTerritorio(temp2, game->getVectorTerritorio());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado" << endl;
				return 1;
			}
		}
		else
		{
			if (subcomando.size() == 2)
			{
				game->listaumTerritorio(subcomando[1], game->getVectorTerrImperio());
				game->listaumTerritorio(subcomando[1], game->getVectorTerritorio());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado" << endl;
				return 1;
			}
		}
		return 1;
	}


	if (subcomando[0] == "avanca")
	{
		cout << "Precisa primeiramente de conquistar ou passar nesta fase!!\n\n"
			 << endl;
		return 1;
	}
	if (subcomando[0] == "toma")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "terr")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando[2] == "Refugio")
			{
				if (subcomando.size() == 5)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3] + ' ' + subcomando[4];
					game->tomaTerritorio(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				if (subcomando.size() == 3)
				{
					game->tomaTerritorio(subcomando[2]);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
		}
		else if (subcomando[1] == "tec")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando[2] == "Bolsa" && subcomando[3] == "de" && subcomando[4] == "Valores")
			{
				if (subcomando.size() == 5)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3] + ' ' + subcomando[4];
					game->tomaTecnologia(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				if (subcomando.size() == 4)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3];
					game->tomaTecnologia(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n"
				 << endl;
			return 1;
		}
	}

	if (subcomando[0] == "modifica")
	{
		int n;
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "ouro")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando.size() == 3)
			{
				if (atoi(subcomando[2].c_str()) >= 0 && atoi(subcomando[2].c_str()) <= game->verificaOuroMaximo())
				{
					n = atoi(subcomando[2].c_str());
					game->setCofre(n);
					return 1;
				}
				else
				{
					cout << "Excede o limite maximo de ouro para o cofre. !\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado !!\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "prod")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando.size() == 3)
			{
				if (atoi(subcomando[2].c_str()) >= 0 && atoi(subcomando[2].c_str()) <= game->verificaProdutosMaximo())
				{
					n = atoi(subcomando[2].c_str());
					game->setArmazem(n);
					return 1;
				}
				else
				{
					cout << "Excede o limite maximo de produtos para o armazem. !\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado !!\n"
					 << endl;
				return 1;
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n"
				 << endl;
			return 1;
		}
	}

	if (subcomando[0] == "fevento")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "Invasao")
		{
			if (subcomando.size() == 2)
			{
				game->Invasao(game->getAno());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Recurso" && subcomando[2] == "Abandonado")
		{
			if (subcomando.size() == 3)
			{
				game->recursoAbandonado(game->getAno());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Alianca" && subcomando[2] == "Diplomatica")
		{
			if (subcomando.size() == 3)
			{
				game->aliancaDiplomatica();
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Sem" && subcomando[2] == "Evento")
		{
			if (subcomando.size() == 3)
			{
				cout << "Nada acontece, todos podem dormir descansados !!\n\n"
					 << endl;
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else
		{
			cout << "Nao existe um evento com esse nome !!\n\n"
				 << endl;
		}
	}

		if (subcomando[0] == "grava")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			if (procuraJogo(subcomando[1]) == 1)
			{
				gravajogo(modificaIgual(subcomando[1]),game);
				return 1;
			}
			else
			{
				gravajogo(subcomando[1],game);
				return 1;
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n\n"
				 << endl;
				 return 1;
		}
	}
	if (subcomando[0] == "ativa")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			ativajogo(subcomando[1],game);
			return 1;
		}
		else
		{
			cout << "Comando mal implementado" << endl;
			return 1;
		}
	}

	if (subcomando[0] == "apaga")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			apagajogo(subcomando[1]);
			return 1;
		}
		else
		{
			cout << "Comando mal implementado" << endl;
			return 1;
		}
	}
	else
	{
		cout << "Nao pode utilizar este comando !!\n"
			 << endl;
		return 1;
	}

	return 1;
}

int Configs::leComando3(vector<string> subcomando,int temp3)
{
	if (subcomando[0] == "lista")
	{
		if (subcomando.size() == 1)
		{
				
				system("cls");
				cout << "  <----------------------------------- Territorios Existentes por conquistar ------------------------------->" << endl;
				cout << "\n";
				game->listarTerritorios(game->getVectorTerritorio());
				cout << "\n";
				cout << "  <----------------------------------- Informacoes do Imperio ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTerritorios(game->getVectorTerrImperio());
				cout << "\n";
				cout << "  <--------------------------------------------------------------------------------------------------------->" << endl;
				cout << "\n";
				game->listaRecursos();
				game->ListarforcaMilitar();
				cout << "\n";
				cout << "  <----------------------------------- Tecnologias do Imperio ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTecsImperio();
				cout << "\n";
				cout << "  <----------------------------------- Tecnologias existentes ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTecnologias();
				cout << "\n";
				cout << "  <----------------------------------- Eventos Que Podem Ocorrer-------------------------------------------->" << endl;
				cout << "\n";
				game->listarEventos();
				cout << "\n";
				return 1;
		}
		else if (subcomando[1] == "Refugio")
		{
			if (subcomando.size() == 4)
			{
				string temp2;
				temp2 = subcomando[1] + ' ' + subcomando[2] + ' ' + subcomando[3];
				game->listaumTerritorio(temp2, game->getVectorTerrImperio());
				game->listaumTerritorio(temp2, game->getVectorTerritorio());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado" << endl;
				return 1;
			}
		}
		else
		{
			if (subcomando.size() == 2)
			{
				game->listaumTerritorio(subcomando[1], game->getVectorTerrImperio());
				game->listaumTerritorio(subcomando[1], game->getVectorTerritorio());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado" << endl;
				return 1;
			}
		}
		return 1;
	}


	if (subcomando[0] == "maisouro")
	{
		if (subcomando.size() == 1)
		{
			if(game->procuraTecnologia("Bolsa de Valores") == 1)
			{
				if(temp3 == tentativaRecursos)
				{
					game->maisOuro();
					tentativaRecursos++;
					return 1;
				}
				else
				{
					cout << "So pode efetuar uma destas operacoes por turno ( maisouro / maisprod) !!\n\n";
					return 1;
				}
			}
			else
			{
				cout << "Nao possui a tecnologia necessaria [Bolsa de Valores] !!\n\n" << endl;
				return 1;
			}
			
		}
		else
		{
			cout << "Comando mal implementado" << endl;
			return 1;
		}
	}

	if (subcomando[0] == "maisprod")
	{
		if (subcomando.size() == 1)
		{
			if(game->procuraTecnologia("Bolsa de Valores") == 1)
			{
				if(temp3 == tentativaRecursos)
				{
					game->maisProdutos();
					tentativaRecursos++;
					return 1;
				}
				else
				{
					cout << "So pode efetuar uma destas operacoes por turno ( maisouro / maisprod) !!\n\n";
					return 1;
				}
			}
			else
			{
				cout << "Nao possui a tecnologia necessaria [Bolsa de Valores] !!\n\n" << endl;
				return 1;
			}
		}
		else
		{
			cout << "Comando mal implementado" << endl;
			return 1;
		}
	}

	if (subcomando[0] == "toma")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "terr")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando[2] == "Refugio")
			{
				if (subcomando.size() == 5)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3] + ' ' + subcomando[4];
					game->tomaTerritorio(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				if (subcomando.size() == 3)
				{
					game->tomaTerritorio(subcomando[2]);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
		}
		else if (subcomando[1] == "tec")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando[2] == "Bolsa" && subcomando[3] == "de" && subcomando[4] == "Valores")
			{
				if (subcomando.size() == 5)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3] + ' ' + subcomando[4];
					game->tomaTecnologia(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				if (subcomando.size() == 4)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3];
					game->tomaTecnologia(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n"
				 << endl;
			return 1;
		}
	}

	if (subcomando[0] == "modifica")
	{
		int n;
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "ouro")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando.size() == 3)
			{
				if (atoi(subcomando[2].c_str()) >= 0 && atoi(subcomando[2].c_str()) <= game->verificaOuroMaximo())
				{
					n = atoi(subcomando[2].c_str());
					game->setCofre(n);
					return 1;
				}
				else
				{
					cout << "Excede o limite maximo de ouro para o cofre. !\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado !!\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "prod")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando.size() == 3)
			{
				if (atoi(subcomando[2].c_str()) >= 0 && atoi(subcomando[2].c_str()) <= game->verificaProdutosMaximo())
				{
					n = atoi(subcomando[2].c_str());
					game->setArmazem(n);
					return 1;
				}
				else
				{
					cout << "Excede o limite maximo de produtos para o armazem. !\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado !!\n"
					 << endl;
				return 1;
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n"
				 << endl;
			return 1;
		}
	}

	if (subcomando[0] == "fevento")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "Invasao")
		{
			if (subcomando.size() == 2)
			{
				game->Invasao(game->getAno());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Recurso" && subcomando[2] == "Abandonado")
		{
			if (subcomando.size() == 3)
			{
				game->recursoAbandonado(game->getAno());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Alianca" && subcomando[2] == "Diplomatica")
		{
			if (subcomando.size() == 3)
			{
				game->aliancaDiplomatica();
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Sem" && subcomando[2] == "Evento")
		{
			if (subcomando.size() == 3)
			{
				cout << "Nada acontece, todos podem dormir descansados !!\n\n"
					 << endl;
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else
		{
			cout << "Nao existe um evento com esse nome !!\n\n"
				 << endl;
		}
	}

		if (subcomando[0] == "grava")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			if (procuraJogo(subcomando[1]) == 1)
			{
				gravajogo(modificaIgual(subcomando[1]),game);
				return 1;
			}
			else
			{
				gravajogo(subcomando[1],game);
				return 1;
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n\n"
				 << endl;
				 return 1;
		}
	}

	if (subcomando[0] == "ativa")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			ativajogo(subcomando[1],game);
			return 1;
		}
		else
		{
			cout << "Comando mal implementado" << endl;
			return 1;
		}
	}

	if (subcomando[0] == "apaga")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			apagajogo(subcomando[1]);
			return 1;
		}
		else
		{
			cout << "Comando mal implementado" << endl;
			return 1;
		}
	}

	if(subcomando[0] == "avanca")
	{
		return 0;
	}
	return 1;
}

int Configs::leComandoAvanca(vector<string> subcomando)
{
	if (subcomando[0] == "avanca")
	{
		return 0;
	}
	if (subcomando[0] == "lista")
	{
		if (subcomando.size() == 1)
		{
				
				system("cls");
				cout << "  <----------------------------------- Territorios Existentes por conquistar ------------------------------->" << endl;
				cout << "\n";
				game->listarTerritorios(game->getVectorTerritorio());
				cout << "\n";
				cout << "  <----------------------------------- Informacoes do Imperio ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTerritorios(game->getVectorTerrImperio());
				cout << "\n";
				cout << "  <--------------------------------------------------------------------------------------------------------->" << endl;
				cout << "\n";
				game->listaRecursos();
				game->ListarforcaMilitar();
				cout << "\n";
				cout << "  <----------------------------------- Tecnologias do Imperio ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTecsImperio();
				cout << "\n";
				cout << "  <----------------------------------- Tecnologias existentes ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTecnologias();
				cout << "\n";
				cout << "  <----------------------------------- Eventos Que Podem Ocorrer-------------------------------------------->" << endl;
				cout << "\n";
				game->listarEventos();
				cout << "\n";
				return 1;
		}
		else if (subcomando[1] == "Refugio")
		{
			if (subcomando.size() == 4)
			{
				string temp2;
				temp2 = subcomando[1] + ' ' + subcomando[2] + ' ' + subcomando[3];
				game->listaumTerritorio(temp2, game->getVectorTerrImperio());
				game->listaumTerritorio(temp2, game->getVectorTerritorio());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado" << endl;
				return 1;
			}
		}
		else
		{
			if (subcomando.size() == 2)
			{
				game->listaumTerritorio(subcomando[1], game->getVectorTerrImperio());
				game->listaumTerritorio(subcomando[1], game->getVectorTerritorio());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado" << endl;
				return 1;
			}
		}
		return 1;
	}


	if (subcomando[0] == "toma")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "terr")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando[2] == "Refugio")
			{
				if (subcomando.size() == 5)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3] + ' ' + subcomando[4];
					game->tomaTerritorio(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				if (subcomando.size() == 3)
				{
					game->tomaTerritorio(subcomando[2]);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
		}
		else if (subcomando[1] == "tec")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando[2] == "Bolsa" && subcomando[3] == "de" && subcomando[4] == "Valores")
			{
				if (subcomando.size() == 5)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3] + ' ' + subcomando[4];
					game->tomaTecnologia(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				if (subcomando.size() == 4)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3];
					game->tomaTecnologia(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n"
				 << endl;
			return 1;
		}
	}

	if (subcomando[0] == "modifica")
	{
		int n;
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "ouro")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando.size() == 3)
			{
				if (atoi(subcomando[2].c_str()) >= 0 && atoi(subcomando[2].c_str()) <= game->verificaOuroMaximo())
				{
					n = atoi(subcomando[2].c_str());
					game->setCofre(n);
					return 1;
				}
				else
				{
					cout << "Excede o limite maximo de ouro para o cofre. !\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado !!\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "prod")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando.size() == 3)
			{
				if (atoi(subcomando[2].c_str()) >= 0 && atoi(subcomando[2].c_str()) <= game->verificaProdutosMaximo())
				{
					n = atoi(subcomando[2].c_str());
					game->setArmazem(n);
					return 1;
				}
				else
				{
					cout << "Excede o limite maximo de produtos para o armazem. !\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado !!\n"
					 << endl;
				return 1;
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n"
				 << endl;
			return 1;
		}
	}

	if (subcomando[0] == "fevento")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "Invasao")
		{
			if (subcomando.size() == 2)
			{
				game->Invasao(game->getAno());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Recurso" && subcomando[2] == "Abandonado")
		{
			if (subcomando.size() == 3)
			{
				game->recursoAbandonado(game->getAno());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Alianca" && subcomando[2] == "Diplomatica")
		{
			if (subcomando.size() == 3)
			{
				game->aliancaDiplomatica();
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Sem" && subcomando[2] == "Evento")
		{
			if (subcomando.size() == 3)
			{
				cout << "Nada acontece, todos podem dormir descansados !!\n\n"
					 << endl;
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else
		{
			cout << "Nao existe um evento com esse nome !!\n\n"
				 << endl;
		}
	}
	if (subcomando[0] == "grava")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			if (procuraJogo(subcomando[1]) == 1)
			{
				gravajogo(modificaIgual(subcomando[1]),game);
				return 1;
			}
			else
			{
				gravajogo(subcomando[1],game);
				return 1;
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n\n"
				 << endl;
				 return 1;
		}
	}

	if (subcomando[0] == "ativa")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			ativajogo(subcomando[1],game);
			return 1;
		}
		else
		{
			cout << "Comando mal implementado" << endl;
			return 1;
		}
	}

	if (subcomando[0] == "apaga")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			apagajogo(subcomando[1]);
			return 1;
		}
		else
		{
			cout << "Comando mal implementado" << endl;
			return 1;
		}
	}
	else
	{
		cout << "So pode efetuar o comando avanca ou comandos de debug/lista !! \n"
			 << endl;
		return 1;
	}

	return 1;
}

int Configs::leComando4(vector<string> subcomando, int temp,int temp2)
{
	if (subcomando[0] == "adquire")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "Bolsa" && subcomando[2] == "de" && subcomando[3] == "Valores")
		{
			string une;
			une = subcomando[1] + ' ' + subcomando[2] + ' ' + subcomando[3];
			if (subcomando.size() == 4)
			{
				if (game->procuraTecnologia(une) == 0)
				{
					if (temp == tamanho)
					{
						game->compraTecnologia(une);
						tamanho++;
						setTamanho(tamanho);
						return 1;
					}
					else
					{
						cout << "So pode comprar uma tecnologia por turno !! \n"
							 << endl;
						return 1;
					}
				}
				else
				{
					cout << "Ja possui esta tecnologia !!\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado !!\n"
					 << endl;
				return 1;
			}
		}
		else
		{

			string une;
			une = subcomando[1] + ' ' + subcomando[2];
			
				if (subcomando.size() == 3)
				{
					if (game->procuraTecnologia(une) == 0)
					{
						if (temp == tamanho)
						{
							game->compraTecnologia(une);
							tamanho++;
							setTamanho(tamanho);
							return 1;
						}
						else
						{
							cout << "So pode comprar uma tecnologia por turno !! \n"
								 << endl;
							return 1;
						}
					}
					else
					{
						cout << "Ja possui esta tecnologia!!\n"
							 << endl;
						return 1;
					}
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			
		}
	}

	if (subcomando[0] == "maismilitar")
	{
		if (subcomando.size() == 1)
		{
			if (temp2 == tentativa)
			{
				game->maisMilitar();
				tentativa++;

				return 1;
			}
			else
			{
				cout << "Ja aumentou o seu poder militar nesta fase !!\n"
					 << endl;
				return 1;
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n"
				 << endl;
			return 1;
		}
	}

	if (subcomando[0] == "avanca")
	{
		return 0;
	}

	if (subcomando[0] == "lista")
	{
		if (subcomando.size() == 1)
		{
				
				system("cls");
				cout << "  <----------------------------------- Territorios Existentes por conquistar ------------------------------->" << endl;
				cout << "\n";
				game->listarTerritorios(game->getVectorTerritorio());
				cout << "\n";
				cout << "  <----------------------------------- Informacoes do Imperio ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTerritorios(game->getVectorTerrImperio());
				cout << "\n";
				cout << "  <--------------------------------------------------------------------------------------------------------->" << endl;
				cout << "\n";
				game->listaRecursos();
				game->ListarforcaMilitar();
				cout << "\n";
				cout << "  <----------------------------------- Tecnologias do Imperio ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTecsImperio();
				cout << "\n";
				cout << "  <----------------------------------- Tecnologias existentes ---------------------------------------------->" << endl;
				cout << "\n";
				game->listarTecnologias();
				cout << "\n";
				cout << "  <----------------------------------- Eventos Que Podem Ocorrer-------------------------------------------->" << endl;
				cout << "\n";
				game->listarEventos();
				cout << "\n";
				return 1;
		}
		else if (subcomando[1] == "Refugio")
		{
			if (subcomando.size() == 4)
			{
				string temp2;
				temp2 = subcomando[1] + ' ' + subcomando[2] + ' ' + subcomando[3];
				game->listaumTerritorio(temp2, game->getVectorTerrImperio());
				game->listaumTerritorio(temp2, game->getVectorTerritorio());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado" << endl;
				return 1;
			}
		}
		else
		{
			if (subcomando.size() == 2)
			{
				game->listaumTerritorio(subcomando[1], game->getVectorTerrImperio());
				game->listaumTerritorio(subcomando[1], game->getVectorTerritorio());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado" << endl;
				return 1;
			}
		}
		return 1;
	}


	if (subcomando[0] == "toma")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "terr")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando[2] == "Refugio")
			{
				if (subcomando.size() == 5)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3] + ' ' + subcomando[4];
					game->tomaTerritorio(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				if (subcomando.size() == 3)
				{
					game->tomaTerritorio(subcomando[2]);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
		}
		else if (subcomando[1] == "tec")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando[2] == "Bolsa" && subcomando[3] == "de" && subcomando[4] == "Valores")
			{
				if (subcomando.size() == 5)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3] + ' ' + subcomando[4];
					game->tomaTecnologia(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				if (subcomando.size() == 4)
				{
					string temp;
					temp = subcomando[2] + ' ' + subcomando[3];
					game->tomaTecnologia(temp);
					return 1;
				}
				else
				{
					cout << "Comando mal implementado !!\n"
						 << endl;
					return 1;
				}
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n"
				 << endl;
			return 1;
		}
	}

	if (subcomando[0] == "modifica")
	{
		int n;
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "ouro")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando.size() == 3)
			{
				if (atoi(subcomando[2].c_str()) >= 0 && atoi(subcomando[2].c_str()) <= game->verificaOuroMaximo())
				{
					n = atoi(subcomando[2].c_str());
					game->setCofre(n);
					return 1;
				}
				else
				{
					cout << "Excede o limite maximo de ouro para o cofre. !\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado !!\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "prod")
		{
			if (subcomando.size() == 2)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
			if (subcomando.size() == 3)
			{
				if (atoi(subcomando[2].c_str()) >= 0 && atoi(subcomando[2].c_str()) <= game->verificaProdutosMaximo())
				{
					n = atoi(subcomando[2].c_str());
					game->setArmazem(n);
					return 1;
				}
				else
				{
					cout << "Excede o limite maximo de produtos para o armazem. !\n"
						 << endl;
					return 1;
				}
			}
			else
			{
				cout << "Comando mal implementado !!\n"
					 << endl;
				return 1;
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n"
				 << endl;
			return 1;
		}
	}

	if (subcomando[0] == "fevento")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}
		if (subcomando[1] == "Invasao")
		{
			if (subcomando.size() == 2)
			{
				game->Invasao(game->getAno());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Recurso" && subcomando[2] == "Abandonado")
		{
			if (subcomando.size() == 3)
			{
				game->recursoAbandonado(game->getAno());
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Alianca" && subcomando[2] == "Diplomatica")
		{
			if (subcomando.size() == 3)
			{
				game->aliancaDiplomatica();
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else if (subcomando[1] == "Sem" && subcomando[2] == "Evento")
		{
			if (subcomando.size() == 3)
			{
				cout << "Nada acontece, todos podem dormir descansados !!\n\n"
					 << endl;
				return 1;
			}
			else
			{
				cout << "Comando mal implementado !! \n\n"
					 << endl;
				return 1;
			}
		}
		else
		{
			cout << "Nao existe um evento com esse nome !!\n\n"
				 << endl;
		}
	}

		if (subcomando[0] == "grava")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			if (procuraJogo(subcomando[1]) == 1)
			{
				gravajogo(modificaIgual(subcomando[1]),game);
				cout << "Jogo Gravado com sucesso !!\n\n" << endl;
				return 1;
			}
			else
			{
				gravajogo(subcomando[1],game);
				cout << "Jogo Gravado com sucesso !!\n\n" << endl;
				return 1;
			}
		}
		else
		{
			cout << "Comando mal implementado !!\n\n"
				 << endl;
				 return 1;
		}
	}

	if (subcomando[0] == "ativa")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			ativajogo(subcomando[1],game);
			return 1;
		}
		else
		{
			cout << "Comando mal implementado" << endl;
			return 1;
		}
	}

	if (subcomando[0] == "apaga")
	{
		if (subcomando.size() == 1)
			{
				cout << "Comando mal implementado!\n"
				 << endl;
				return 1;
			}

		if (subcomando.size() == 2)
		{
			apagajogo(subcomando[1]);
			return 1;
		}
		else
		{
			cout << "Comando mal implementado" << endl;
			return 1;
		}
	}

	return 1;
}

//-----------------Codigo relativo a ficheiros---------------->

//Carrega ficheiro de texto que inclui as tecnologias

bool Configs::carregaTecnologia(string ficheiro)
{
	ifstream fich(ficheiro);
	string linha;
	vector<string> stringSeparada;
	if (!fich.is_open())
	{
		cout << "ficheiro nao existe" << endl;
		return false;
	}
	while (!fich.eof())
	{
		getline(fich, linha);
		stringSeparada = divideString(linha);
		if (stringSeparada[0] == "Drones" && stringSeparada[1] == "Militares")
		{
			string temp;
			temp = stringSeparada[0] + ' ' + stringSeparada[1];
			string temp2;
			temp2 = stringSeparada[3] + ' ' + stringSeparada[4] + ' ' + stringSeparada[5] + ' ' + stringSeparada[6] + ' ' + stringSeparada[7] + ' ' + stringSeparada[8];
			string temp3;
			temp3 = stringSeparada[9] + ' ' + stringSeparada[10];
			game->adicionaTecnologia(new Tecnologia(temp, atoi(stringSeparada[2].c_str()), temp2, temp3));
		}
		else if (stringSeparada[0] == "Misseis" && stringSeparada[1] == "Teleguiados")
		{
			string temp;
			temp = stringSeparada[0] + ' ' + stringSeparada[1];
			string temp2;
			temp2 = stringSeparada[3] + ' ' + stringSeparada[4] + ' ' + stringSeparada[5] + ' ' + stringSeparada[6];
			string temp3;
			temp3 = stringSeparada[7] + ' ' + stringSeparada[8];
			game->adicionaTecnologia(new Tecnologia(temp, atoi(stringSeparada[2].c_str()), temp2, temp3));
		}
		else if (stringSeparada[0] == "Defesas" && stringSeparada[1] == "Territoriais")
		{
			string temp;
			temp = stringSeparada[0] + ' ' + stringSeparada[1];
			string temp2;
			temp2 = stringSeparada[3] + ' ' + stringSeparada[4] + ' ' + stringSeparada[5] + ' ' + stringSeparada[6];
			string temp3;
			temp3 = stringSeparada[7] + ' ' + stringSeparada[8];
			game->adicionaTecnologia(new Tecnologia(temp, atoi(stringSeparada[2].c_str()), temp2, temp3));
		}
		else if (stringSeparada[0] == "Bolsa" && stringSeparada[1] == "de" && stringSeparada[2] == "Valores")
		{
			string temp;
			temp = stringSeparada[0] + ' ' + stringSeparada[1] + ' ' + stringSeparada[2];
			string temp2;
			temp2 = stringSeparada[4] + ' ' + stringSeparada[5] + ' ' + stringSeparada[6] + ' ' + stringSeparada[7] + ' ' + stringSeparada[8] + ' ' + stringSeparada[9] + ' ' + stringSeparada[10] + ' ' + stringSeparada[11];
			string temp3;
			temp3 = stringSeparada[12] + ' ' + stringSeparada[13];
			game->adicionaTecnologia(new Tecnologia(temp, atoi(stringSeparada[3].c_str()), temp2, temp3));
		}
		else if (stringSeparada[0] == "Banco" && stringSeparada[1] == "Central")
		{
			string temp;
			temp = stringSeparada[0] + ' ' + stringSeparada[1];
			string temp2;
			temp2 = stringSeparada[3] + ' ' + stringSeparada[4] + ' ' + stringSeparada[5] + ' ' + stringSeparada[6] + ' ' + stringSeparada[7];
			string temp3;
			temp3 = stringSeparada[8] + ' ' + stringSeparada[9];
			game->adicionaTecnologia(new Tecnologia(temp, atoi(stringSeparada[2].c_str()), temp2, temp3));
		}
		else
		{
			cout << "Ficheiro com informacao errada" << endl;
		}
	}
	fich.close();
	return true;
}

//Carrega ficheiro de texto que inclui os territorios

bool Configs::carregaTerritorio(string ficheiro)
{
	ifstream fich(ficheiro);
	string linha;

	vector<string> stringSeparada;

	if (!fich.is_open())
	{
		cout << "ficheiro nao existe" << endl;
		return false;
	}
	while (!fich.eof()) //Enquanto nao chegar ao fim do ficheiro
	{
		getline(fich, linha);
		stringSeparada = divideString(linha);
		int n = 0;

		if (stringSeparada[0] == "cria")
		{
			if (stringSeparada[1] == "Planicie" || stringSeparada[1] == "Montanha" || stringSeparada[1] == "Fortaleza" || stringSeparada[1] == "Mina" || stringSeparada[1] == "Duna" || stringSeparada[1] == "Castelo")
			{
				if (atoi(stringSeparada[2].c_str()) > 0)
				{
					int extra = game->verificaN(stringSeparada[1]);
					n = atoi(stringSeparada[2].c_str());

					do
					{
						extra++;
						game->adicionaTerritorio(new Continente(stringSeparada[1], "Continente", 0, 0, 0, 1, extra,0));
						n--;
					} while (n > 0);
				}
				else
				{
					cout << "Ficheiro com informacao errada1 !!\n"
						 << endl;
				}
			}
			if (stringSeparada[1] == "Pescaria") // completar refugio dos piratas
			{
				if (atoi(stringSeparada[2].c_str()) > 0)
				{
					int extra = game->verificaN(stringSeparada[1]);
					int n = atoi(stringSeparada[2].c_str());
					do
					{
						extra++;
						game->adicionaTerritorio(new Ilha(stringSeparada[1], "Ilha", 0, 0, 0, 2, extra));

						n--;

					} while (n > 0);
				}
				else
				{
					cout << "Ficheiro com informacao errada !!\n"
						 << endl;
				}
			}
			if (stringSeparada[1] == "Refugio" && stringSeparada[2] == "dos" && stringSeparada[3] == "Piratas")
			{
				string temp;
				temp = stringSeparada[1] + ' ' + stringSeparada[2] + ' ' + stringSeparada[3];

				if (atoi(stringSeparada[4].c_str()) > 0)
				{
					int extra = game->verificaN(temp);
					int n = atoi(stringSeparada[4].c_str());
					do
					{
						extra++;
						game->adicionaTerritorio(new Ilha(temp, "Ilha", 0, 0, 0, 2, extra));

						n--;

					} while (n > 0);
				}
				else
				{
					cout << "Ficheiro com informacao errada !!\n"
						 << endl;
				}
			}
			else
				;
		}
		else
		{
			cout << "Ficheiro com informacao errada3 !!\n"
				 << endl;
		}
	}

	fich.close();

	return true;
}

//Funcao auxiliar que serve para ler os ficheiros de textos

vector<string> Configs::divideString(string comando)
{
	stringstream s;
	char espaco = ' ';
	vector<string> palavraSeparada;
	string word;

	s.str(comando);

	while (getline(s, word, espaco))
	{
		if (!word.empty())
		{
			palavraSeparada.push_back(word);
		}
	}

	return palavraSeparada;
}

string Configs::modificaIgual(string nome)
{
	string temp;
	ostringstream oss;

	oss << nome << num_id++;

	temp = oss.str();

	return temp;
}
