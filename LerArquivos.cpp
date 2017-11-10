#include "Funcoes.h"

void LeituraJogador() {
	FILE * arquivo;
	typeCase dadosCaso;
	typeChar dadosLadrao;
	char nomeMocinho;
	char tituloCaso, historiaCaso, dicasCaso;
	char nomeLadrao, sexoLadrao, hobbyLadrao, cabeloLadrao, caracLadrao, veiculoLadrao;
	char caminhoLadrao;
	int lugaresLadrao, esconderijoLadrao;
	char lixo;
	int auxiliar_titulo = 0, flagTitulo = 0, auxiliar_historia = 0, flagHistoria = 0, i = 0, contEspacos = 0, j;
	arquivo = fopen("caso1.txt", "r");
	if (!arquivo) {
		printf("Erro na abertura do arquivo.\n");
	}
	//------------------------------------------------------------------------------------------
	printf("Ola, o nome do seu caso eh:  ");
	do {
		tituloCaso = fgetc(arquivo);
		if (tituloCaso != '*') {
			dadosCaso.caseTitle[auxiliar_titulo] = tituloCaso; // recebendo o titulo do caso
			auxiliar_titulo++;

		}
		else {
			dadosCaso.caseTitle[auxiliar_titulo] = '\0'; //senao coloca \0
			flagTitulo = 1;
		}


	} while (flagTitulo == 0);
	printf("%s", dadosCaso.caseTitle);
	
	//-----------------------------------------------------------------------------------------
	i = 0;
	contEspacos = 0;
	do {
		nomeLadrao = fgetc(arquivo);
		if (nomeLadrao != '-') {
			dadosLadrao.charName[i] = nomeLadrao; //nome do ladrao
			i++;
		}
		else {
			dadosLadrao.charName[i] = '\0';
			contEspacos = 1;
		}
	} while (contEspacos == 0);
	printf("%s", dadosLadrao.charName);
	//----------------------------------------------------------
	printf("\n");
	contEspacos = 0;
	do {
		sexoLadrao = fgetc(arquivo);
		if (sexoLadrao != '-') {
			dadosLadrao.sexo = sexoLadrao; //sexo do ladrao

		}
		else {

			contEspacos = 1;
		}
	} while (contEspacos == 0);
	printf("%c", dadosLadrao.sexo);
	//------------------------------------------------------
	printf("\n");
	contEspacos = 0;
	do {
		hobbyLadrao = fgetc(arquivo);
		if (hobbyLadrao != '-') {
			dadosLadrao.hobby = hobbyLadrao; //hobby do ladrao

		}
		else {

			contEspacos = 1;
		}
	} while (contEspacos == 0);
	printf("%c", dadosLadrao.hobby);
	//------------------------------------------------------
	printf("\n");
	contEspacos = 0;
	do {
		cabeloLadrao = fgetc(arquivo);
		if (cabeloLadrao != '-') {
			dadosLadrao.cabelo = cabeloLadrao; //cabelo do ladrao

		}
		else {

			contEspacos = 1;
		}
	} while (contEspacos == 0);
	printf("%c", dadosLadrao.cabelo);
	//-----------------------------------------------------------------
	printf("\n");
	contEspacos = 0;
	do {
		caracLadrao = fgetc(arquivo);
		if (caracLadrao != '-') {
			dadosLadrao.caracteristica = caracLadrao; //caracteristica do ladrao

		}
		else {

			contEspacos = 1;
		}
	} while (contEspacos == 0);
	printf("%c", dadosLadrao.caracteristica);
	//-------------------------------------------------


	//------------------------------------------------------------------
	printf("\n");
	contEspacos = 0;
	i = 0;
	do {
		veiculoLadrao = fgetc(arquivo);
		if (veiculoLadrao != '*') {
			dadosLadrao.veiculo = veiculoLadrao; //automovel do ladrao

		}
		else {

			contEspacos = 1;
		}
	} while (contEspacos == 0);
	printf("%c", dadosLadrao.veiculo);
	//-------------------------------------------------------------
//------------------------------------------------
	char aster;
	printf("\n");
	contEspacos = 0;
	do {
		fscanf(arquivo, "%i %c", &lugaresLadrao,&aster);

		if (lugaresLadrao != '*' ) {
			dadosCaso.howManyPlaces = lugaresLadrao; //qntd de lugares 

		}
		if (aster == '*') {
			contEspacos = 1;
		}
	
	} while (contEspacos == 0);
	printf("%i\n", dadosCaso.howManyPlaces);
//--------------------------------------------------
	lixo = fgetc(arquivo);
//------------------------------------------------
	for (i = 0; i < lugaresLadrao; i++) {
		j = 0;

		contEspacos = 0;
		do {
			caminhoLadrao = fgetc(arquivo);
			if (caminhoLadrao == '*') {
				contEspacos = 1;
			}
			if (caminhoLadrao != '-' && caminhoLadrao != '*') {
				dadosCaso.thiefPath[j] = caminhoLadrao; //caminho ladrao
				printf("%c", dadosCaso.thiefPath[j]);
				j++;
			}
			else {
				dadosCaso.thiefPath[j] = '\0';
				contEspacos = 1;
				printf("%c", dadosCaso.thiefPath[j]);
			}
		} while (contEspacos == 0);

	}
//-----------------------------------------------------
	printf("\n");
	contEspacos = 0;
	do {
		fscanf(arquivo, "%i %c", &esconderijoLadrao, &aster);

		if (lugaresLadrao != '*') {
			dadosCaso.hideout = esconderijoLadrao; //esconderijo

		}
		if (aster == '*') {
			contEspacos = 1;
		}

	} while (contEspacos == 0);
	printf("%i", dadosCaso.hideout);
//-------------------------------------------------------

	do {
		historiaCaso = fgetc(arquivo);
		if (historiaCaso != '*') {
			dadosCaso.history[auxiliar_historia] = historiaCaso; //recebendo historia do caso
			auxiliar_historia++;
		}
		else {
			dadosCaso.history[auxiliar_historia] = '\0';
			flagHistoria = 1;
		}
	} while (flagHistoria == 0);
	printf("%s\n", dadosCaso.history);
	//----------------------------------------------------------------------------------------
	

	//------------------------------------------------
	int k = 0;
	for (i = 0; i < (dadosCaso.howManyPlaces-1); i++) {

		for (j = 0; j < 3; j++) {
			k = 0;
			lixo = fgetc(arquivo);
			do {
				contEspacos = 0;
				dicasCaso = fgetc(arquivo);
				if (dicasCaso != '*' && dicasCaso !='\n') {
					dadosCaso.tips[j][i][k] = dicasCaso; //dicas do caso!@!@!
					
					k++;
				}
				else if(dicasCaso!='\n') {
					dadosCaso.tips[j][i][k] = '\0';
					contEspacos = 1;
				}
			} while (contEspacos == 0);
			printf("%s\n", dadosCaso.tips[j][i]);
			
		}
		
	}
	fclose(arquivo);

}
