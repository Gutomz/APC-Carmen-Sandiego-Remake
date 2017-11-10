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
	char charName[20]; // nome do personagem
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
	char history[1000]; // História inicial do caso
	int howManyPlaces;	// Quantidade de lugares que o ladrão vai passar
	char thiefPath[20]; //Caminho que o ladrão percorre no jogo
	int hideout;		//1. Praça - 2. Hotel - 3. Banco
	char tips[3][15][500]; //[profundidade][linha][coluna] --> Cada profundidade é uma dica de um lugar(Hotel, Praça...) no estado
	typeChar thief;
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
int AdmSucesso(char nomeADM[], char senhaADM[]);
void AdmCriacao(char nomeADM[], char senhaADM[]);
int AdmVerif();
void criptografa(char senha[]);

int FazerLogin(char NomeJogador[]);
int CriarContaJogador(char NomeJogador[]);
void Verifica_Conta(char NomeJogador[], char NomeCaso[]);

//---------------------------------Funções do Principal---------------------------//


//-------------------------------------------------------------------------------------------------------------------------------//


//---------------------------------Funções do CriarCaso---------------------------//
void CaseCreation();
void ThiefCreation(typeCase whichCase);
void ThiefPathCreation(typeCase whitchCase);
void TipsCreation(char path[], int howManyPlaces, typeCase caseToCreate);
//---------------------------------Funções do Principal---------------------------//

void LeituraJogador(char nomeCaso[]);

void AdmMenu(char nomeADM[], char senhaADM[]);