#include "Funcoes.h"

void LeituraJogador(char NomeCaso[], char NomeJogador[]) {
	FILE * arquivo;

	typeCase dadosCaso;

	char tituloCaso, historiaCaso, dicasCaso;
	char nomeLadrao, sexoLadrao, hobbyLadrao, cabeloLadrao, caracLadrao, veiculoLadrao;
	char caminhoLadrao;
	int lugaresLadrao, esconderijoLadrao, tempo;
	char lixo;
	int auxiliar_titulo = 0, flagTitulo = 0, auxiliar_historia = 0, flagHistoria = 0, i = 0, contEspacos = 0, j;

	strcat(NomeCaso, ".txt");
	arquivo = fopen(NomeCaso, "r");
	if (!arquivo) {
		printf("Erro na abertura do arquivo.\n");
	}
	//------------------------------------------------------------------------------------------
	do {
		tituloCaso = fgetc(arquivo);
		if (tituloCaso != '*') {
			dadosCaso.caseTitle[auxiliar_titulo] = tituloCaso; // recebendo o titulo do caso
			auxiliar_titulo++;
		} else {
			dadosCaso.caseTitle[auxiliar_titulo] = '\0'; //senao coloca \0
			flagTitulo = 1;
		}
	} while (flagTitulo == 0);

	//-----------------------------------------------------------------------------------------
	i = 0;
	contEspacos = 0;
	do {
		nomeLadrao = fgetc(arquivo);
		if (nomeLadrao != '-') {
			if (nomeLadrao != '\n') {
				dadosCaso.thief.charName[i] = nomeLadrao; //nome do ladrao
				i++;
			}
		} else {
			dadosCaso.thief.charName[i] = '\0';
			contEspacos = 1;
		}
	} while (contEspacos == 0);
	//----------------------------------------------------------

	contEspacos = 0;
	do {
		sexoLadrao = fgetc(arquivo);
		if (sexoLadrao != '-') {
			dadosCaso.thief.sexo = sexoLadrao; //sexo do ladrao

		} else {

			contEspacos = 1;
		}
	} while (contEspacos == 0);
	//------------------------------------------------------
	contEspacos = 0;
	do {
		hobbyLadrao = fgetc(arquivo);
		if (hobbyLadrao != '-') {
			dadosCaso.thief.hobby = hobbyLadrao; //hobby do ladrao

		} else {

			contEspacos = 1;
		}
	} while (contEspacos == 0);
	//------------------------------------------------------
	contEspacos = 0;
	do {
		cabeloLadrao = fgetc(arquivo);
		if (cabeloLadrao != '-') {
			dadosCaso.thief.cabelo = cabeloLadrao; //cabelo do ladrao

		} else {

			contEspacos = 1;
		}
	} while (contEspacos == 0);
	//-----------------------------------------------------------------
	contEspacos = 0;
	do {
		caracLadrao = fgetc(arquivo);
		if (caracLadrao != '-') {
			dadosCaso.thief.caracteristica = caracLadrao; //caracteristica do ladrao

		} else {

			contEspacos = 1;
		}
	} while (contEspacos == 0);
	//-------------------------------------------------


	//------------------------------------------------------------------
	contEspacos = 0;
	i = 0;
	do {
		veiculoLadrao = fgetc(arquivo);
		if (veiculoLadrao != '*') {
			dadosCaso.thief.veiculo = veiculoLadrao; //automovel do ladrao

		} else {

			contEspacos = 1;
		}
	} while (contEspacos == 0);
	//-------------------------------------------------------------
	//------------------------------------------------
	char aster;
	contEspacos = 0;
	do {
		fscanf(arquivo, "%i %c", &lugaresLadrao, &aster);

		if (lugaresLadrao != '*') {
			dadosCaso.howManyPlaces = lugaresLadrao; //qntd de lugares 

		}
		if (aster == '*') {
			contEspacos = 1;
		}

	} while (contEspacos == 0);
	//--------------------------------------------------
	lixo = fgetc(arquivo);
	//------------------------------------------------
	for (i = 0; i < lugaresLadrao; i++) {
		caminhoLadrao = fgetc(arquivo);
		if (caminhoLadrao != '*') {
			if (caminhoLadrao != '-') {
				dadosCaso.thiefPath[i] = caminhoLadrao; //caminho ladrao
			} else {
				i--;
			}
		}
		else {
			break;
		}
	}
	dadosCaso.thiefPath[i] = '\0';
	
	//-----------------------------------------------------
	fgetc(arquivo);
	contEspacos = 0;
	do {
		fscanf(arquivo, "%i %c", &esconderijoLadrao, &aster);

		if (esconderijoLadrao != '*') {
			dadosCaso.hideout = esconderijoLadrao; //esconderijo

		}
		if (aster == '*') {
			contEspacos = 1;
		}

	} while (contEspacos == 0);
	//-------------------------------------------------------
	lixo = fgetc(arquivo);

	fscanf(arquivo, "%i %c", &tempo, &aster);
	dadosCaso.caseTime = tempo;
	

	//-----------------------------------------------------------------------------------------

	do {
		historiaCaso = fgetc(arquivo);
		if (historiaCaso != '*') {
			if (historiaCaso != '\n') {
				dadosCaso.history[auxiliar_historia] = historiaCaso; //recebendo historia do caso
				auxiliar_historia++;
			}
		} else {
			dadosCaso.history[auxiliar_historia] = '\0';
			flagHistoria = 1;
		}
	} while (flagHistoria == 0);
	//----------------------------------------------------------------------------------------


	//------------------------------------------------
	int k = 0;
	for (i = 0; i < (dadosCaso.howManyPlaces - 1); i++) {
		for (j = 0; j < 3; j++) {
			k = 0;
			lixo = fgetc(arquivo);
			do {
				contEspacos = 0;
				dicasCaso = fgetc(arquivo);
				if (dicasCaso != '*' && dicasCaso != '\n') {
					dadosCaso.tips[j][i][k] = dicasCaso; //dicas do caso!@!@!

					k++;
				} else if (dicasCaso != '\n') {
					dadosCaso.tips[j][i][k] = '\0';
					contEspacos = 1;
				}
			} while (contEspacos == 0);
		}

	}
	fclose(arquivo);

	system("cls");
	printf("Nome do Caso: %s\n", dadosCaso.caseTitle);
	printf("O nome do Ladrão: %s\n", dadosCaso.thief.charName);
	printf("Sexo: %c\n", dadosCaso.thief.sexo);
	printf("Hobby: %c\n", dadosCaso.thief.hobby);
	printf("Cabelo: %c\n", dadosCaso.thief.cabelo);
	printf("Característica: %c\n", dadosCaso.thief.caracteristica);
	printf("Veículo: %c\n", dadosCaso.thief.veiculo);
	printf("Quantidade de lugares: %i\n", dadosCaso.howManyPlaces);
	printf("Lugares: ");
	for (i = 0; i < dadosCaso.howManyPlaces; i++) {
		if (i != dadosCaso.howManyPlaces - 1) {
			printf("%c-", dadosCaso.thiefPath[i]);
		} else {
			printf("%c\n", dadosCaso.thiefPath[i]);
		}
	}
	printf("Tempo do jogo: %i horas\n", dadosCaso.caseTime);
	printf("História: \"%s\"\n", dadosCaso.history);
	for (i = 0; i < dadosCaso.howManyPlaces - 1; i++) {
		for (j = 0; j < 3; j++) {
			printf("Dica %i.%i: \"%s\"\n", i+1, j+1, dadosCaso.tips[j][i]);
		}
	}
	

	system("pause");

	//------------------------------------------------Início do Jogo-----------------------------------------------------//
	MainGame(dadosCaso, NomeJogador);
}