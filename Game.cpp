#include "Funcoes.h"


void MainGame(typeCase myCase, char NomeJogador[]) {
	char texto[1500];
	int tempo, dias, horas, whereIam;
	int ansFlag, winFlag = 0, warrantFlag;
	int escolhaNum, posicaoLadrao=0;

	tempo = myCase.caseTime;
	dias = myCase.caseTime / 24;
	horas = myCase.caseTime % 24;
	whereIam = myCase.thiefPath[0] - 48;

	//CaseApresentation(myCase, NomeJogador, dias, horas);
	do {
		dias = tempo / 24;
		horas = tempo % 24;
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

		switch (escolhaNum) {
			case 1:
				whereIam = ChangeLocation(whereIam, &tempo); //escolhe um lugar pra ir e salva o numero desse lugar (SP - 7)
				break;
			case 2:
				SearchInto(myCase, whereIam, &tempo, &posicaoLadrao);
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

int ChangeLocation(int whereIam, int *tempo) {
	int flag = 0;
	int escolhaNum, count = 0;
	int dias, horas;
	dias = *tempo / 24;
	horas = *tempo % 24;

	system("cls");


	switch (whereIam) {
	case RS:
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                              VIAJAR                                 |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Tempo atual: %i dia[s] e %i hora[s]\n", dias, horas);
			printf(" Estado atual: Rio Grande do Sul\n");
			printf(" Escolha um estado para viajar:\n\n");
			printf("  1- Goiás\n");
			printf("  2- Mato Grosso do Sul\n");
			printf("  3- Espírito Santo\n");
			printf("  4- Voltar\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 4) {
				switch (escolhaNum) {
				case 1:
					whereIam = 2;

					break;
				case 2:
					whereIam = 1;
					break;
				case 3:
					whereIam = 3;
					break;
				case 4:
					return whereIam;
					break;
				}
				*tempo = *tempo - 1;

				flag = 1;

			}
		} while (flag == 0);
		break;
	case MS:
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                              VIAJAR                                 |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Tempo atual: %i dia[s] e %i hora[s]\n", dias, horas);
			printf(" Estado atual: Mato Grosso do Sul\n");
			printf(" Escolha um estado para viajar:\n\n");
			printf("  1- Rio Grande do Sul\n");
			printf("  2- Mato Grosso\n");
			printf("  3- Santa Catarina\n");
			printf("  4- Voltar\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 4) {
				switch (escolhaNum) {
				case 1:
					whereIam = 0;
					break;
				case 2:
					whereIam = 4;
					break;
				case 3:
					whereIam = 5;
					break;
				case 4:
					return whereIam;
				}
				flag = 1;
				*tempo = *tempo - 1;
			}
		} while (flag == 0);
		break;
	case GO:
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                              VIAJAR                                 |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Tempo atual: %i dia[s] e %i hora[s]\n", dias, horas);
			printf(" Estado atual: Goiás\n");
			printf(" Escolha um estado para viajar:\n\n");
			printf("  1- Rio Grande do Sul\n");
			printf("  2- Minas Gerais\n");
			printf("  3- São Paulo\n");
			printf("  4- Volat\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 4) {
				switch (whereIam) {
				case 1:
					whereIam = 0;
					break;
				case 2:
					whereIam = 6;
					break;
				case 3:
					whereIam = 7;
					break;
				case 4:
					whereIam;
				}
				flag = 1;
				*tempo = *tempo - 1;
			}
		} while (flag == 0);
		break;
	case ES:
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                              VIAJAR                                 |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Tempo atual: %i dia[s] e %i hora[s]\n", dias, horas);
			printf(" Estado atual: Espírito Santo\n");
			printf(" Escolha um estado para viajar:\n\n");
			printf("  1- Rio Grande do Sul\n");
			printf("  2- Paraná\n");
			printf("  3- Rio de Janeiro\n");
			printf("  4- Voltar.\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 4) {
				switch (escolhaNum) {
				case 1:
					whereIam = 0;
					break;
				case 2:
					whereIam = 8;
					break;
				case 3:
					whereIam = 9;
					break;
				}
				flag = 1;
				*tempo = *tempo - 1;
			}
		} while (flag == 0);
		break;
	case MT:
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                              VIAJAR                                 |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Tempo atual: %i dia[s] e %i hora[s]\n", dias, horas);
			printf(" Estado atual: Mato Grosso\n");
			printf(" Escolha um estado para viajar:\n\n");
			printf("  1- Mato Grosso do Sul\n");
			printf("  2- São Paulo\n");
			printf("  3- Minas Gerais\n");
			printf("  4- Voltar\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 4) {
				switch (escolhaNum) {
				case 1:
					whereIam = 1;
					break;
				case 2:
					whereIam = 7;
					break;
				case 3:
					whereIam = 6;
					break;
				case 4:
					return whereIam;
					break;
				}
				flag = 1;
				*tempo = *tempo - 1;
			}
		} while (flag == 0);
		break;
	case SC:
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                              VIAJAR                                 |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Tempo atual: %i dia[s] e %i hora[s]\n", dias, horas);
			printf(" Estado atual: Santa Catarina\n");
			printf(" Escolha um estado para viajar:\n\n");
			printf("  1- Mato Grosso do Sul\n");
			printf("  2- Paraná\n");
			printf("  3- Minas Gerais\n");
			printf("  4- Voltar\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 4) {
				switch (escolhaNum) {
				case 1:
					whereIam = 1;
					break;
				case 2:
					whereIam = 8;
					break;
				case 3:
					whereIam = 6;
					break;
				case 4:
					return whereIam;
					break;
				}
				flag = 1;
				*tempo = *tempo - 1;
			}
		} while (flag == 0);
		break;
	case MG:
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                              VIAJAR                                 |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Tempo atual: %i dia[s] e %i hora[s]\n", dias, horas);
			printf(" Estado atual: Minas Gerais\n");
			printf(" Escolha um estado para viajar:\n\n");
			printf("  1- Goiás\n");
			printf("  2- Mato Grosso\n");
			printf("  3- Santa Catarina\n");
			printf("  4- Voltar\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 4) {
				switch (escolhaNum) {
				case 1:
					whereIam = 2;
					break;
				case 2:
					whereIam = 4;
					break;
				case 3:
					whereIam = 5;
					break;
				case 4:
					return whereIam;
				}
				flag = 1;
				*tempo = *tempo - 1;
			}
		} while (flag == 0);
		break;
	case SP:
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                              VIAJAR                                 |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Tempo atual: %i dia[s] e %i hora[s]\n", dias, horas);
			printf(" Estado atual: São Paulo\n");
			printf(" Escolha um estado para viajar:\n\n");
			printf("  1- Goiás\n");
			printf("  2- Mato Grosso\n");
			printf("  3- Rio de Janeiro\n");
			printf("  4- Voltar\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 4) {
				switch (escolhaNum) {
				case 1:
					whereIam = 2;
					break;
				case 2:
					whereIam = 4;
					break;
				case 3:
					whereIam = 9;
					break;
				case 4:
					return whereIam;
				}
				flag = 1;
				*tempo = *tempo - 1;
			}
		} while (flag == 0);
		break;
	case PR:
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                              VIAJAR                                 |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Tempo atual: %i dia[s] e %i hora[s]\n", dias, horas);
			printf(" Estado atual: Paraná\n");
			printf(" Escolha um estado para viajar:\n\n");
			printf("  1- Espírito Santo\n");
			printf("  2- Santa Catarina\n");
			printf("  3- Rio de Janeiro\n");
			printf("  4- Voltar\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 4) {
				switch (escolhaNum) {
				case 1:
					whereIam = 3;
					break;
				case 2:
					whereIam = 5;
					break;
				case 3:
					whereIam = 9;
					break;
				case 4:
					return whereIam;
					break;
				}
				flag = 1;
				*tempo = *tempo - 1;
			}
		} while (flag == 0);
		break;
	case RJ:
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                              VIAJAR                                 |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Tempo atual: %i dia[s] e %i hora[s]\n", dias, horas);
			printf(" Estado atual: Rio de Janeiro\n");
			printf(" Escolha um estado para viajar:\n\n");
			printf("  1- Espírito Santo\n");
			printf("  2- São Paulo\n");
			printf("  3- Paraná\n");
			printf("  4- Voltar\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 4) {
				switch (escolhaNum) {
				case 1:
					whereIam = 3;
					break;
				case 2:
					whereIam = 7;
					break;
				case 3:
					whereIam = 8;
					break;
				case 4:
					return whereIam;
					break;
				}
				flag = 1;
				*tempo = *tempo - 1;
			}
		} while (flag == 0);
		break;

	}
	return whereIam;





	return 0;
}

void SearchInto(typeCase dadosCaso, int estadoAtual, int *ponteiro_tempo, int *ponteiro_posicaoLadrao)
{
	int escolhaLocal, dias, horas, i, flagCaminho, frase_escolhida;
	char texto[500], frasesProntas[3][100], pessoa[3][10];
	time_t t;

	srand(time(&t));
	strcpy(frasesProntas[0], "Me desculpe, eu não vi ninguém assim por aqui.");
	strcpy(frasesProntas[1], "Me desculpe, eu nunca vi a pessoa que você está procurando.");
	strcpy(frasesProntas[2], "Ninguém assim veio aqui.");

	strcpy(pessoa[0], "Maria");
	strcpy(pessoa[1], "Pedro");
	strcpy(pessoa[2], "Roger");

	flagCaminho = 0;
	dias = *ponteiro_tempo / 24;
	horas = *ponteiro_tempo % 24;

	/*for (i = 0; dadosCaso.thiefPath[i] != '\0'; i++)
	{
		if (dadosCaso.thiefPath[i] == (estadoAtual+48))
		{
			flagCaminho = 1;
		}
	}*/

	i = 0;
	do {
		if (dadosCaso.thiefPath[i] == (estadoAtual + 48))
		{
			flagCaminho = 1;
		}
		i++;
	} while (dadosCaso.thiefPath[i] != '\0' && (i-1) != *ponteiro_posicaoLadrao);

	system("cls");
	printf("----------------------------------------------------------------------\n");
	printf("|                             INVESTIGAR                             |\n");
	printf("----------------------------------------------------------------------\n");

	printf(" Tempo restante: %i dias e %i horas\n", dias, horas);
	printf(" Tempo de investigação: 1 hora\n\n");

	printf(" Escolha um local para investigar:\n\n");
	printf("  1 - Praça\n");
	printf("  2 - Hotel\n");
	printf("  3 - Banco\n");
	printf("----------------------------------------------------------------------\n Resposta: ");
	scanf("%i", &escolhaLocal);

	printf("\n----------------------------------------------------------------------\n");

	frase_escolhida = (rand() % 3);
	switch (escolhaLocal)
	{
	case 1:

		if (flagCaminho == 1) //Caminho do ladrão
		{

			if (dadosCaso.thiefPath[*ponteiro_posicaoLadrao] == (estadoAtual + 48)) //Se encontrar o atual estado do ladrão
			{
				*ponteiro_posicaoLadrao = *ponteiro_posicaoLadrao + 1;

				if (dadosCaso.thiefPath[*ponteiro_posicaoLadrao] == '\0') // Se for o estado do esconderijo
				{
					//printf("  Você está próximo!!\n");
					*ponteiro_posicaoLadrao = *ponteiro_posicaoLadrao - 1;

					if (dadosCaso.hideout == 1)
					{
						printf("  Parabéns, você achou o ladrão :]\n");
					}
					else
					{
						printf("  Você está próximo!\n");
					}

				}
				else // Ele passa por aqui, porém não é o esconderijo
				{
					strcpy(texto, dadosCaso.tips[0][estadoAtual]);

					printf("  %s: %s\n", pessoa[frase_escolhida], texto);
				}
			}
			else
			{
				strcpy(texto, dadosCaso.tips[0][estadoAtual]);

				printf("  %s: %s\n", pessoa[frase_escolhida], texto);
			}

			
		}
		else
		{
			printf("  %s: %s\n", pessoa[frase_escolhida], frasesProntas[frase_escolhida]);
		}

		system("pause");
		break;
	case 2:

		if (flagCaminho == 1) //Caminho do ladrão
		{

			if (dadosCaso.thiefPath[*ponteiro_posicaoLadrao] == (estadoAtual + 48)) //Se encontrar o atual estado do ladrão
			{
				*ponteiro_posicaoLadrao = *ponteiro_posicaoLadrao + 1;

				if (dadosCaso.thiefPath[*ponteiro_posicaoLadrao] == '\0') // Se for o estado do esconderijo
				{
					//printf("  Você está próximo!!\n");
					*ponteiro_posicaoLadrao = *ponteiro_posicaoLadrao - 1;

					if (dadosCaso.hideout == 2)
					{
						printf("  Parabéns, você achou o ladrão :]\n");
					}
					else
					{
						printf("  Você está próximo!\n");
					}

				}
				else // Ele passa por aqui, porém não é o esconderijo
				{
						strcpy(texto, dadosCaso.tips[1][estadoAtual]);

						printf("  Gerente do hotel: %s\n", texto);
				}
			}
			else
			{
				strcpy(texto, dadosCaso.tips[1][estadoAtual]);

				printf("  Gerente do hotel: %s\n", texto);
			}


		}
		else
		{
			printf("  Gerente do hotel: %s\n", frasesProntas[frase_escolhida]);
		}

		system("pause");
		break;

	case 3:

		if (flagCaminho == 1) //Caminho do ladrão
		{

			if (dadosCaso.thiefPath[*ponteiro_posicaoLadrao] == (estadoAtual + 48)) //Se encontrar o atual estado do ladrão
			{
				*ponteiro_posicaoLadrao = *ponteiro_posicaoLadrao + 1;

				if (dadosCaso.thiefPath[*ponteiro_posicaoLadrao] == '\0') // Se for o estado do esconderijo
				{
					//printf("  Você está próximo!!\n");
					*ponteiro_posicaoLadrao = *ponteiro_posicaoLadrao - 1;

					if (dadosCaso.hideout == 3)
					{
						printf("  Parabéns, você achou o ladrão :]\n");
					}
					else
					{
						printf("  Você está próximo!\n");
					}

				}
				else // Ele passa por aqui, porém não é o esconderijo
				{
						strcpy(texto, dadosCaso.tips[2][estadoAtual]);

						printf("  Caixa: %s\n", texto);
				}
			}
			else
			{
				strcpy(texto, dadosCaso.tips[2][estadoAtual]);

				printf("  Caixa: %s\n", texto);
			}


		}
		else
		{
			printf("  Caixa: %s\n", frasesProntas[frase_escolhida]);
		}

		system("pause");
		break;

	}

	*ponteiro_tempo = *ponteiro_tempo - 1;

}

int Computer() {

	return 0;
}