#include "Funcoes.h"


void MainGame(typeCase myCase, char NomeJogador[]) {
	char texto[1500];
	int tempo, dias, horas, whereIam;
	int ansFlag, winFlag = 0, warrantFlag;
	int escolhaNum;

	tempo = myCase.caseTime;
	dias = myCase.caseTime / 24;
	horas = myCase.caseTime % 24;
	whereIam = myCase.thiefPath[0] - 48;

	CaseApresentation(myCase, NomeJogador, dias, horas);
	do {
		ansFlag = 0;
		do {
			system("cls");
			switch (whereIam) {
				case RS:
					printf("----------------------------------------------------------------------\n");
					printf("|                           RIO GRANDE DO SUL                        |\n");
					printf("----------------------------------------------------------------------\n");
					break;
				case MS:
					printf("----------------------------------------------------------------------\n");
					printf("|                           MATO GROSSO DO SUL                       |\n");
					printf("----------------------------------------------------------------------\n");
					break;
				case GO:
					printf("----------------------------------------------------------------------\n");
					printf("|                                 GOI�S                              |\n");
					printf("----------------------------------------------------------------------\n");
					break;
				case ES:
					printf("----------------------------------------------------------------------\n");
					printf("|                             ESP�RITO SANTO                         |\n");
					printf("----------------------------------------------------------------------\n");
					break;
				case MT:
					printf("----------------------------------------------------------------------\n");
					printf("|                              MATO GROSSO                           |\n");
					printf("----------------------------------------------------------------------\n");
					break;
				case SC:
					printf("----------------------------------------------------------------------\n");
					printf("|                             SANTA CATARINA                         |\n");
					printf("----------------------------------------------------------------------\n");
					break;
				case MG:
					printf("----------------------------------------------------------------------\n");
					printf("|                              MINAS GERAIS                          |\n");
					printf("----------------------------------------------------------------------\n");
					break;
				case SP:
					printf("----------------------------------------------------------------------\n");
					printf("|                               S�O PAULO                            |\n");
					printf("----------------------------------------------------------------------\n");
					break;
				case PR:
					printf("----------------------------------------------------------------------\n");
					printf("|                                 PARAN�                             |\n");
					printf("----------------------------------------------------------------------\n");
					break;
				case RJ:
					printf("----------------------------------------------------------------------\n");
					printf("|                             RIO DE JANEIRO                         |\n");
					printf("----------------------------------------------------------------------\n");
					break;
			}
			printf(" Tempo Restante: %i dias e %i horas\n\n", dias, horas);
			printf("  1- Viajar\n");
			printf("  2- Investigar\n");
			printf("  3- Dados do suspeito\n");
			printf("  4- Sair\n");
			printf("----------------------------------------------------------------------\n Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 4)
				ansFlag = 1;
		} while (ansFlag == 0);

		switch (ansFlag) {
			case 1:
				whereIam = ChangeLocation(); //escolhe um lugar pra ir e salva o numero desse lugar (SP - 7)
				break;
			case 2:
				SearchInto();
				break;
			case 3:
				warrantFlag = Computer();
				break;
			case 4:
				//sair
				break;
		}
	} while (winFlag == 0 && tempo > 0);
	if (tempo < 0)
		winFlag = 0;

	if (winFlag == 1) {
		//winner
		//Precisa modificar o arquivo do jogador (Se existir um)
	} else {
		//loser
		//volta pro menu do jogador
		//para perguntar se ele gostaria de fazer outro caso
	}
}

void CaseApresentation(typeCase myCase, char NomeJogador[], int dias, int horas) {
	char texto[1500];

	system("cls");
	printf("----------------------------------------------------------------------\n");
	printf("|                                FLASH                               |\n");
	printf("----------------------------------------------------------------------\n\n  ");

	PrintText(myCase.history);
	printf("\n\n");

	strcpy(texto, "  Seu objetivo � seguir as pistas e encontrar o suspeito em seu\n");
	PrintText(texto);
	strcpy(texto, "esconderijo!\n\n");
	PrintText(texto);

	strcpy(texto, "  Voc� tem ");
	PrintText(texto);
	printf("%i", dias);
	strcpy(texto, " dias e ");
	PrintText(texto);
	printf("%i", horas);
	strcpy(texto, " horas.\n  Boa sorte!");
	PrintText(texto);

	system("pause>nul");
}

void PrintText(char texto[]) {
	int i = 0;

	do {
		printf("%c", texto[i]);
		Sleep(75);
		i++;
	} while (texto[i] != '\0');
}

int ChangeLocation() {
	return 0;
}

void SearchInto() {

}

int Computer() {

	return 0;
}