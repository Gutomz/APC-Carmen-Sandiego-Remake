#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>


//-------------------------------------------------------------------------------------------------------------------------------//


//---------------------------------------Structs----------------------------------//
struct typeChar
{
	char charName[50]; // nome do personagem
	char sexo; // 1.feminino - 2.masculino
	char hobby; // 1.futebol - 2.samba - 3.praia - 4.natação - 5.luta
	char cabelo; // 1.preto - 2.loiro - 3.ruivo - 4.castanho - 5.grisálio
	char caracteristica; // 1.anel - 2.pulseira - 3.colar - 4.boné - 5.tatuagem
	char veiculo; // 1.carro - 2.moto - 3.helicóptero - 4.bicicleta - 5.jatinho
};

struct typeCase {
	char caseTitle[30]; // Titulo do caso
	char extension[5] = { '.','t','x','t' }; //Extensão para o arquivo
	char fileName[30]; // Titulo do caso + a extensão
	int caseTime;
	char history[1000]; // História inicial do caso
	int howManyPlaces;	// Quantidade de lugares que o ladrão vai passar
	char thiefPath[20]; //Caminho que o ladrão percorre no jogo
	int hideout;		//1. Praça - 2. Hotel - 3. Banco
	char tips[3][15][500]; //[profundidade][linha][coluna] --> Cada profundidade é uma dica de um lugar(Hotel, Praça...) no estado
	typeChar thief;
};


struct typePlayer{
	char name[50];
	int level;
	int exp;
};
//---------------------------------------Structs----------------------------------//


//-------------------------------------------------------------------------------------------------------------------------------//


//----------------------------------------Enums-----------------------------------//
enum States_enum
{
	RS = 0, MS, GO, ES, MT, SC, MG, SP, PR, RJ
};
//----------------------------------------Enums-----------------------------------//


//-------------------------------------------------------------------------------------------------------------------------------//


//---------------------------------Funções do Principal---------------------------//
int BemVindo();
void SetVideo();
//---------------------------------Funções do Principal---------------------------//


//-------------------------------------------------------------------------------------------------------------------------------//


//---------------------------------Funções ADM---------------------------//
int AdmLogin(char nomeADM[], char senhaADM[]);
void AdmCriacao(char nomeADM[], char senhaADM[]);
int AdmVerif();
int AdmMenu(char nomeADM[], char senhaADM[]);
void criptografa(char senha[]);
int AdmModif(char nomeADM[], char senhaADM[]);
//---------------------------------Funções ADM---------------------------//


//-------------------------------------------------------------------------------------------------------------------------------//


//---------------------------------Funções do Conta Jogador---------------------------//
int FazerLogin(typePlayer player[]);
void CriarContaJogador(typePlayer player[]);
void Verifica_Conta(typePlayer player[]);
void EscolherCaso(char NomeCaso[], typePlayer player[]);
int ContaJogadorMenu(typePlayer player[]);
int JogadorMenu();
int LoginConvidado(typePlayer player[]);
//---------------------------------Funções do Conta Jogador---------------------------//


//-------------------------------------------------------------------------------------------------------------------------------//


//---------------------------------Funções do CriarCaso---------------------------//
void CaseCreation();
void ThiefCreation(typeCase whichCase);
int ThiefPathCreation(typeCase whitchCase);
void TipsCreation(char path[], int howManyPlaces, typeCase caseToCreate);
void ModificarArqCasos(char caseName[], int difficulty);
//---------------------------------Funções do CriarCaso---------------------------//


//-------------------------------------------------------------------------------------------------------------------------------//


//---------------------------------Funções do Game--------------------------------//
void MainGame(typeCase myCase, typePlayer player[], int howManySuspects);

void PrintText(char texto[]);
void CaseApresentation(typeCase myCase, char NomeJogador[], int dias, int horas);

int Computer(char suspectsStatus[],int *tempo, int howManySuspects, typeChar suspects[], char suspeitoName[], int warrant);
int SearchInto(typeCase dadosCaso, int estadoAtual, int *ponteiro_tempo, int *ponteiro_posicaoLadrao, int warrantFlag, int *viagemFlag);
int ChangeLocation(int whereIam, int *tempo);
void ObterSuspeitos(typeChar suspeitos[], int howManySuspects);
void ModificarDadosJogador(typePlayer player[]);
//---------------------------------Funções do Game--------------------------------//


//-------------------------------------------------------------------------------------------------------------------------------//


//---------------------------------Funções do Ler Arquivo--------------------------------------//
void LerArquivoCaso(char nomeCaso[], typePlayer player[]);
int LerArquivoPersonagens(typeChar thief);
//---------------------------------Funções do Ler Arquivo--------------------------------------//


//-------------------------------------------------------------------------------------------------------------------------------//


//---------------------------------Função para Mostrar o Ranking--------------------------------------//
void MostrarRanking();
//---------------------------------Função para Mostrar o Ranking--------------------------------------//