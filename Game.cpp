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

		switch (ansFlag) {
			case 1:
				whereIam = ChangeLocation(whereIam,&tempo); //escolhe um lugar pra ir e salva o numero desse lugar (SP - 7)
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

int ChangeLocation(int whereIam, int *tempo) {
	int flag = 0;
	int escolhaNum, count = 0;
	int dias, horas;
	dias = *tempo / 24;
	horas = *tempo % 24;


	do {
		
		system("cls");
	
		
		switch (whereIam) {
		case RS:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                              VIAJAR                                 |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Tempo atual: %i dia[s] e %i hora[s]\n",dias,horas);
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
					*tempo--;
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
				printf(" Escolha atual: Mato Grosso do Sul\n");
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
					*tempo--;
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
				printf(" Escolha atual: Goiás\n");
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
					*tempo--;
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
				printf(" Escolha atual: Espírito Santo\n");
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
					*tempo--;
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
				printf(" Escolha atual: Mato Grosso\n");
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
					*tempo--;
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
				printf(" Escolha atual: Santa Catarina\n");
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
					*tempo--;
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
				printf(" Escolha atual: Minas Gerais\n");
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
					*tempo--;
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
				printf(" Escolha atual: São Paulo\n");
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
					*tempo--;
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
				printf(" Escolha atual: Paraná\n");
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
					*tempo--;
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
				printf(" Escolha atual: Rio de Janeiro\n");
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
					*tempo--;
				}
			} while (flag == 0);
			break;

		}
		return whereIam;
	} while (count < whereIam); //Loop das escolhas dos lugares

	
				

	return 0;
}

void SearchInto() {

}

int Computer() {

	return 0;
}