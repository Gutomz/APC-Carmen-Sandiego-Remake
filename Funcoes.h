#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <locale.h>
#include <Windows.h>

//-------------------------------------------------------------------------------------------------------------------------------//


//---------------------------------------Structs----------------------------------//
struct typeChar
{
	char charName[20]; // nome do personagem
	char sexo; // 1.feminino - 2.masculino
	char hobby; // 1.futebol - 2.samba - 3.praia - 4.nata��o - 5.luta
	char cabelo; // 1.preto - 2.loiro - 3.ruivo - 4.castanho - 5.gris�lio
	char caracteristica; // 1.anel - 2.pulseira - 3.colar - 4.bon� - 5.tatuagem
	char veiculo; // 1.carro - 2.moto - 3.helic�ptero - 4.bicicleta - 5.jatinho
};

struct typeCase {
	char caseTitle[30]; // Titulo do caso
	char extension[5] = { '.','t','x','t' }; //Extens�o para o arquivo
	char fileName[30]; // Titulo do caso + a extens�o
	char history[1000]; // Hist�ria inicial do caso
	int howManyPlaces;	// Quantidade de lugares que o ladr�o vai passar
	char thiefPath[20]; //Caminho que o ladr�o percorre no jogo
	int hideout;		//1. Pra�a - 2. Hotel - 3. Banco
	char tips[3][15][500]; //[profundidade][linha][coluna] --> Cada profundidade � uma dica de um lugar(Hotel, Pra�a...) no estado
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


//---------------------------------Fun��es do Principal---------------------------//
int BemVindo();
int AdmSucesso();
void AdmCriacao();
int AdmVerif();
void criptografa(char senha[]);
//---------------------------------Fun��es do Principal---------------------------//


//-------------------------------------------------------------------------------------------------------------------------------//


//---------------------------------Fun��es do CriarCaso---------------------------//
void CaseCreation();
void ThiefCreation(typeCase whichCase);
void ThiefPathCreation(typeCase whitchCase);
void TipsCreation(char path[], int howManyPlaces, typeCase caseToCreate);
//---------------------------------Fun��es do Principal---------------------------//

