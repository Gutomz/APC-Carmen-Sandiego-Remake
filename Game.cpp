#include "Funcoes.h"


void MainGame(typeCase myCase, typePlayer player[], int howManySuspects) {
	char texto[1500], suspectsStatus[] = { 0, 0, 0, 0, 0 }, suspeitoName[50];
	int tempo, dias, horas, whereIam, posicaoLadrao = 0;
	int ansFlag, winFlag = 0, warrantFlag = 0, viagemFlag = 1;
	int escolhaNum;
	char quit[5];

	typeChar suspeitos[50];

	tempo = myCase.caseTime;
	dias = tempo / 24;
	horas = tempo % 24;
	whereIam = myCase.thiefPath[0] - 48;

	CaseApresentation(myCase, player[0].name, dias, horas);
	ObterSuspeitos(suspeitos, howManySuspects);

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
					printf("|                                 GOIÁS                              |\n");
					printf("----------------------------------------------------------------------\n");
					break;
				case ES:
					printf("----------------------------------------------------------------------\n");
					printf("|                             ESPÍRITO SANTO                         |\n");
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
					printf("|                               SÃO PAULO                            |\n");
					printf("----------------------------------------------------------------------\n");
					break;
				case PR:
					printf("----------------------------------------------------------------------\n");
					printf("|                                 PARANÁ                             |\n");
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
				viagemFlag = 1;
				break;
			case 2:
				winFlag = SearchInto(myCase, whereIam, &tempo, &posicaoLadrao, warrantFlag, &viagemFlag);
				viagemFlag = 0;
				//Retorno = 0 --> Continua o jogo normalmente, pois ainda não é o esconderijo
				//Retorno = 1 --> Tem mandato, achou o esconderijo, e precisa conferir se é o suspeito certo
				//Retorno = 2 --> Não tem o mandato e achou o esconderijo
				break;
			case 3:
				warrantFlag = Computer(suspectsStatus, &tempo, howManySuspects, suspeitos, suspeitoName, warrantFlag);
				break;
			case 4:

				printf("\n Tem certeza que gostaria de sair? (Sim/Não)\n Resposta: ");
				scanf("%s", &quit);

				if (quit[0] == 's' || quit[0] == 'S') {
					winFlag = 3;
				}

				break;
		}
	} while (winFlag == 0 && tempo > 0);

	if (winFlag != 3) {//Se winFlag for 3 --> Sair
		if (tempo <= 0) {
			winFlag = 0;
			//aparecer que perdeu pois acabou o tempo
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                            FIM DE JOGO                             |\n");
			printf("----------------------------------------------------------------------\n");
			printf("  Mensagem dos Superiores: ");

			strcpy(texto, "Más notícias... Nós acabamos de receber a \n");
			PrintText(texto);

			strcpy(texto, "informação de que o suspeito escapou pelos seus dedos porque sua \n");
			PrintText(texto);

			strcpy(texto, "investigação demorou demais!\n\n");
			PrintText(texto);

			system("pause");
		}

		if (winFlag == 1) {//Verificar se o suspeito do mandado é o mesmo suspeito do caso
			//se for o mesmo suspito aparece mensagem de vitoria
			//Se não for perdeu
		} else if (winFlag == 2) {
			//Perdeu pois não tinha o mandado de prisão
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                            FIM DE JOGO                             |\n");
			printf("----------------------------------------------------------------------\n");
			printf("  Mensagem dos Superiores: ");

			strcpy(texto, "Você capturou o suspeito. Contudo, sem um \n");
			PrintText(texto);

			strcpy(texto, "mandado, nós não podemos efetuar a prisão!\n");
			PrintText(texto);

			strcpy(texto, "  Parece que a guangue da Carminha ficará impune de mais um crime!\n\n");
			PrintText(texto);

			system("pause");
		}
	}
}

void CaseApresentation(typeCase myCase, char NomeJogador[], int dias, int horas) {
	char texto[1500];

	system("cls");
	printf("----------------------------------------------------------------------\n");
	printf("|                        APRESENTAÇÂO DO CASO                        |\n");
	printf("----------------------------------------------------------------------\n\n  ");

	PrintText(myCase.history);
	printf("\n\n");

	strcpy(texto, "  Seu objetivo é seguir as pistas e deter o ladrão em seu esconderijo!\n\n");
	PrintText(texto);

	strcpy(texto, "  Você tem ");
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
		if (texto[i] != ' ') {
			Sleep(40);
		}
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
				printf("|                              VIAJAR                                |\n");
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
					*tempo -= 2;

					flag = 1;
				}
			} while (flag == 0);
			break;
		case MS:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                              VIAJAR                                |\n");
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
					*tempo -= 2;
				}
			} while (flag == 0);
			break;
		case GO:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                              VIAJAR                                |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Tempo atual: %i dia[s] e %i hora[s]\n", dias, horas);
				printf(" Estado atual: Goiás\n");
				printf(" Escolha um estado para viajar:\n\n");
				printf("  1- Rio Grande do Sul\n");
				printf("  2- Minas Gerais\n");
				printf("  3- São Paulo\n");
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
							whereIam = 6;
							break;
						case 3:
							whereIam = 7;
							break;
						case 4:
							whereIam;
					}
					flag = 1;
					*tempo -= 2;
				}
			} while (flag == 0);
			break;
		case ES:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                              VIAJAR                                |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Tempo atual: %i dia[s] e %i hora[s]\n", dias, horas);
				printf(" Estado atual: Espírito Santo\n");
				printf(" Escolha um estado para viajar:\n\n");
				printf("  1- Rio Grande do Sul\n");
				printf("  2- Paraná\n");
				printf("  3- Rio de Janeiro\n");
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
							whereIam = 8;
							break;
						case 3:
							whereIam = 9;
							break;
					}
					flag = 1;
					*tempo -= 2;
				}
			} while (flag == 0);
			break;
		case MT:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                              VIAJAR                                |\n");
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
					*tempo -= 2;
				}
			} while (flag == 0);
			break;
		case SC:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                              VIAJAR                                |\n");
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
					*tempo -= 2;
				}
			} while (flag == 0);
			break;
		case MG:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                              VIAJAR                                |\n");
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
					*tempo -= 2;
				}
			} while (flag == 0);
			break;
		case SP:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                              VIAJAR                                |\n");
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
					*tempo -= 2;
				}
			} while (flag == 0);
			break;
		case PR:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                              VIAJAR                                |\n");
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
					*tempo -= 2;
				}
			} while (flag == 0);
			break;
		case RJ:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                              VIAJAR                                |\n");
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
					*tempo -= 2;
				}
			} while (flag == 0);
			break;
	}
	printf("\n Viajando");
	Sleep(500);
	printf(".");
	Sleep(750);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(750);
	return whereIam;
}


int SearchInto(typeCase dadosCaso, int estadoAtual, int *ponteiro_tempo, int *ponteiro_posicaoLadrao, int warrantFlag, int *viagemFlag)
{
	int escolhaLocal, dias, horas, i, flagCaminho, frase_escolhida;
	char texto[500], frasesProntas[3][100], pessoa[3][10];
	time_t t;

	srand(time(&t));
	strcpy(frasesProntas[0], "Me desculpe, eu não vi ninguém assim por aqui.");
	strcpy(frasesProntas[1], "Me desculpe, eu nunca vi a pessoa que você está procurando.");
	strcpy(frasesProntas[2], "Ninguém assim passou por aqui.");

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
		if (dadosCaso.thiefPath[i] == (estadoAtual + 48)) {
			flagCaminho = 1;
		}
		i++;
	} while (dadosCaso.thiefPath[i] != '\0' && (i - 1) != *ponteiro_posicaoLadrao);

	if ((dadosCaso.thiefPath[*ponteiro_posicaoLadrao] == (estadoAtual + 48)) && (*viagemFlag == 1)) // Colocar um contador em viagens
	{																		// para a msg aparecer apenas 1 vez.
		printf("----------------------------------------------------------------------\n");
		printf("  Um dos comparsas foi visto! Você deve estar no caminho certo.\n");
		Sleep(2500);
	}

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
	switch (escolhaLocal) {
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

						if (dadosCaso.hideout == 1) {
							if (warrantFlag == 1) {
								return 1;
							} else {
								return 2;
							}
						} else {
							printf("  %s: Tudo o que sei é que está acontecendo algo suspeito no estado\n", pessoa[frase_escolhida]);
						}

					} else // Ele passa por aqui, porém não é o esconderijo
					{
						strcpy(texto, dadosCaso.tips[0][estadoAtual]);

						printf("  %s: %s\n", pessoa[frase_escolhida], texto);
					}
				} else {
					strcpy(texto, dadosCaso.tips[0][estadoAtual]);

					printf("  %s: %s\n", pessoa[frase_escolhida], texto);
				}


			} else {
				printf("  %s: %s\n", pessoa[frase_escolhida], frasesProntas[frase_escolhida]);
			}

			printf("\n");
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

						if (dadosCaso.hideout == 2) {
							if (warrantFlag == 1) {
								//printf("  Parabéns, você achou o ladrão :]\n"); // Verificar se tem o mandato
								return 1;
							} else {
								return 2;
							}
						} else {
							printf("  Gerente do hotel: Tudo o que sei é que está acontecendo algo suspeito no estado\n");
						}

					} else // Ele passa por aqui, porém não é o esconderijo
					{
						strcpy(texto, dadosCaso.tips[1][estadoAtual]);

						printf("  Gerente do hotel: %s\n", texto);
					}
				} else {
					strcpy(texto, dadosCaso.tips[1][estadoAtual]);

					printf("  Gerente do hotel: %s\n", texto);
				}


			} else {
				printf("  Gerente do hotel: %s\n", frasesProntas[frase_escolhida]);
			}

			printf("\n");
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

						if (dadosCaso.hideout == 3) {
							if (warrantFlag == 1) {
								//printf("  Parabéns, você achou o ladrão :]\n"); // Verificar se tem o mandato
								return 1;
							} else {
								return 2;
							}
						} else {
							printf("  Caixa: Tudo o que sei é que está acontecendo algo suspeito no estado\n");
						}

					} else // Ele passa por aqui, porém não é o esconderijo
					{
						strcpy(texto, dadosCaso.tips[2][estadoAtual]);

						printf("  Caixa: %s\n", texto);
					}
				} else {
					strcpy(texto, dadosCaso.tips[2][estadoAtual]);

					printf("  Caixa: %s\n", texto);
				}


			} else {
				printf("  Caixa: %s\n", frasesProntas[frase_escolhida]);
			}

			printf("\n");
			system("pause");
			break;

	}

	*ponteiro_tempo = *ponteiro_tempo - 1;
	return 0;
}

int Computer(char suspectsStatus[], int *tempo, int howManySuspects, typeChar suspects[], char suspeitoName[], int warrant) {
	int ansNum, modificationFlag = 0, i;
	char suspectNameAux[50];
	int nSuspeitos = 0;

	do {
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                          DADOS DO SUSPEITO                         |\n");
			printf("----------------------------------------------------------------------\n\n");
			printf("  1- Sexo: ");
			switch (suspectsStatus[0]) {
				case 0:
					printf("\n");
					break;
				case 1:
					printf("                   Feminino\n");
					break;
				case 2:
					printf("                   Masculino\n");
					break;
			}
			printf("  2- Hobby: ");
			switch (suspectsStatus[1]) {
				case 0:
					printf("\n");
					break;
				case 1:
					printf("                  Futebol\n");
					break;
				case 2:
					printf("                  Samba\n");
					break;
				case 3:
					printf("                  Praia\n");
					break;
				case 4:
					printf("                  Natação\n");
					break;
				case 5:
					printf("                  Luta\n");
					break;
			}
			printf("  3- Cabelo: ");
			switch (suspectsStatus[2]) {
				case 0:
					printf("\n");
					break;
				case 1:
					printf("                 Preto\n");
					break;
				case 2:
					printf("                 Loiro\n");
					break;
				case 3:
					printf("                 Ruivo\n");
					break;
				case 4:
					printf("                 Castanho\n");
					break;
				case 5:
					printf("                 Grisálio\n");
					break;
			}
			printf("  4- Característica: ");
			switch (suspectsStatus[3]) {
				case 0:
					printf("\n");
					break;
				case 1:
					printf("         Anel\n");
					break;
				case 2:
					printf("         Pulseira\n");
					break;
				case 3:
					printf("         Colar\n");
					break;
				case 4:
					printf("         Boné\n");
					break;
				case 5:
					printf("         Tatuagem\n");
					break;
			}
			printf("  5- Veículo: ");
		switch (suspectsStatus[4]) {
			case 0:
				printf("\n");
				break;
			case 1:
				printf("                Carro\n");
				break;
			case 2:
				printf("                Moto\n");
				break;
			case 3:
				printf("                Helicóptero\n");
				break;
			case 4:
				printf("                Bicicleta\n");
				break;
			case 5:
				printf("                Jatinho\n");
				break;
		}
			printf("\n  6- Computar\n  7- Voltar\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			scanf("%i", &ansNum);
		} while (ansNum < 1 || ansNum > 7);

		switch (ansNum) {
			case 1:
				do {
					system("cls");
					printf("----------------------------------------------------------------------\n");
					printf("|                                 SEXO                               |\n");
					printf("----------------------------------------------------------------------\n\n");
					printf("  1- Feminino\n  2- Masculino\n\n  3- Nenhum\n");
					printf("----------------------------------------------------------------------\n");
					printf(" Resposta: ");
					scanf("%c", &suspectsStatus[0]);
					if (suspectsStatus[0] == '1' || suspectsStatus[0] == '2') {
						suspectsStatus[0] -= 48;
					}
					else if (suspectsStatus[0] == '3') {
						suspectsStatus[0] = 0;
					}
				} while (suspectsStatus[0] < 0 || suspectsStatus[0] > 5);	//Loop de verificação do sexo
				break;
			case 2:
				do {
					system("cls");
					printf("----------------------------------------------------------------------\n");
					printf("|                                HOBBY                               |\n");
					printf("----------------------------------------------------------------------\n\n");
					printf("  1- Futebol\n  2- Samba\n  3- Praia\n  4- Natação\n  5- Luta\n\n  6- Nenhum\n");
					printf("----------------------------------------------------------------------\n");
					printf(" Resposta: ");
					scanf("%c", &suspectsStatus[1]);
					if (!(suspectsStatus[1] < '1' || suspectsStatus[1] > '5')) {
						suspectsStatus[1] -= 48;
					}
					else if (suspectsStatus[1] == '6') {
						suspectsStatus[1] = 0;
					}
				} while (suspectsStatus[1] < 0 || suspectsStatus[1] > 5);	//Loop de verificação do sexo
				break;
			case 3:
				do {
					system("cls");
					printf("----------------------------------------------------------------------\n");
					printf("|                                CABELO                              |\n");
					printf("----------------------------------------------------------------------\n\n");
					printf("  1- Preto\n  2- Loiro\n  3- Ruivo\n  4- Castanho\n  5- Grisálio\n\n  6- Nenhum\n");
					printf("----------------------------------------------------------------------\n");
					printf(" Resposta: ");
					scanf("%c", &suspectsStatus[2]);
					if (!(suspectsStatus[2] < '1' || suspectsStatus[2] > '5')) {
						suspectsStatus[2] -= 48;
					}
					else if (suspectsStatus[2] == '6') {
						suspectsStatus[2] = 0;
					}
				} while (suspectsStatus[2] < 0 || suspectsStatus[2] > 5);	//Loop de verificação do sexo
				break;
			case 4:
				do {
					system("cls");
					printf("----------------------------------------------------------------------\n");
					printf("|                            CARACTERÍSTICA                          |\n");
					printf("----------------------------------------------------------------------\n\n");
					printf("  1- Anel\n  2- Pulseira\n  3- Colar\n  4- Boné\n  5- Tatuagem\n\n  6- Nenhum\n");
					printf("----------------------------------------------------------------------\n");
					printf(" Resposta: ");
					scanf("%c", &suspectsStatus[3]);
					if (!(suspectsStatus[3] < '1' || suspectsStatus[3] > '5')) {
						suspectsStatus[3] -= 48;
					}
					else if (suspectsStatus[3] == '6') {
						suspectsStatus[3] = 0;
					}
				} while (suspectsStatus[3] < 0 || suspectsStatus[3] > 5);	//Loop de verificação do sexo
				break;
			case 5:
				do {
					system("cls");
					printf("----------------------------------------------------------------------\n");
					printf("|                                 VEÍCULO                            |\n");
					printf("----------------------------------------------------------------------\n\n");
					printf("  1- Carro\n  2- Moto\n  3- Helicóptero\n  4- Bicicleta\n  5- Jatinho\n\n  6- Nenhum\n");
					printf("----------------------------------------------------------------------\n");
					printf(" Resposta: ");
					scanf("%c", &suspectsStatus[4]);
					if (!(suspectsStatus[4] < '1' || suspectsStatus[4] > '5')) {
						suspectsStatus[4] -= 48;
					}
					else if (suspectsStatus[4] == '6') {
						suspectsStatus[4] = 0;
					}
				} while (suspectsStatus[4] < 0 || suspectsStatus[4] > 5);	//Loop de verificação do sexo
				break;
			case 6:
				nSuspeitos = 0;
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                          LISTA DE SUSPEITOS                        |\n");
				printf("----------------------------------------------------------------------\n\n");
				for (i = 0; i < howManySuspects; i++) {
					if (suspectsStatus[0] != 0) {//sexo
						if ((suspects[i].sexo - 48) == suspectsStatus[0]) {
							if (suspectsStatus[1] != 0) {//hobby
								if (suspects[i].hobby - 48 == suspectsStatus[1]) {
									if (suspectsStatus[2] != 0) {//cabelo
										if (suspects[i].cabelo - 48 == suspectsStatus[2]) {
											if (suspectsStatus[3] != 0) {//característica
												if (suspects[i].caracteristica - 48 == suspectsStatus[3]) {
													if (suspectsStatus[4] != 0) {//veículo
														if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
															//Printa o nome dele
															//Acrescenta 1 no numero de possíveis suspeitos
															printf(" %s\n", suspects[i].charName);
															nSuspeitos++;
															strcpy(suspectNameAux, suspects[i].charName);
														}
													} else {//veículo = all
														//Printa o nome dele
														//Acrescenta 1 no numero de possíveis suspeitos
														printf(" %s\n", suspects[i].charName);
														nSuspeitos++;
														strcpy(suspectNameAux, suspects[i].charName);
													}
												}
											} else {//característica = all
												if (suspectsStatus[4] != 0) {//veículo
													if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
														//Printa o nome dele
														//Acrescenta 1 no numero de possíveis suspeitos
														printf(" %s\n", suspects[i].charName);
														nSuspeitos++;
														strcpy(suspectNameAux, suspects[i].charName);
													}
												} else {//veículo = all
													//Printa o nome dele
													//Acrescenta 1 no numero de possíveis suspeitos
													printf(" %s\n", suspects[i].charName);
													nSuspeitos++;
													strcpy(suspectNameAux, suspects[i].charName);
												}
											}
										}
									} else {//cabelo = all
										if (suspectsStatus[3] != 0) {//característica
											if (suspects[i].caracteristica - 48 == suspectsStatus[3]) {
												if (suspectsStatus[4] != 0) {//veículo
													if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
														//Printa o nome dele
														//Acrescenta 1 no numero de possíveis suspeitos
														printf(" %s\n", suspects[i].charName);
														nSuspeitos++;
														strcpy(suspectNameAux, suspects[i].charName);
													}
												} else {//veículo = all
													//Printa o nome dele
													//Acrescenta 1 no numero de possíveis suspeitos
													printf(" %s\n", suspects[i].charName);
													nSuspeitos++;
													strcpy(suspectNameAux, suspects[i].charName);
												}
											}
										} else {//característica = all
											if (suspectsStatus[4] != 0) {//veículo
												if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
													//Printa o nome dele
													//Acrescenta 1 no numero de possíveis suspeitos
													printf(" %s\n", suspects[i].charName);
													nSuspeitos++;
													strcpy(suspectNameAux, suspects[i].charName);
												}
											} else {//veículo = all
												//Printa o nome dele
												//Acrescenta 1 no numero de possíveis suspeitos
												printf(" %s\n", suspects[i].charName);
												nSuspeitos++;
												strcpy(suspectNameAux, suspects[i].charName);
											}
										}
									}
								}
							} else {//hobby = all
								if (suspectsStatus[2] != 0) {//cabelo
									if (suspects[i].cabelo - 48 == suspectsStatus[2]) {
										if (suspectsStatus[3] != 0) {//característica
											if (suspects[i].caracteristica - 48 == suspectsStatus[3]) {
												if (suspectsStatus[4] != 0) {//veículo
													if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
														//Printa o nome dele
														//Acrescenta 1 no numero de possíveis suspeitos
														printf(" %s\n", suspects[i].charName);
														nSuspeitos++;
														strcpy(suspectNameAux, suspects[i].charName);
													}
												} else {//veículo = all
													//Printa o nome dele
													//Acrescenta 1 no numero de possíveis suspeitos
													printf(" %s\n", suspects[i].charName);
													nSuspeitos++;
													strcpy(suspectNameAux, suspects[i].charName);
												}
											}
										} else {//característica = all
											if (suspectsStatus[4] != 0) {//veículo
												if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
													//Printa o nome dele
													//Acrescenta 1 no numero de possíveis suspeitos
													printf(" %s\n", suspects[i].charName);
													nSuspeitos++;
													strcpy(suspectNameAux, suspects[i].charName);
												}
											} else {//veículo = all
												//Printa o nome dele
												//Acrescenta 1 no numero de possíveis suspeitos
												printf(" %s\n", suspects[i].charName);
												nSuspeitos++;
												strcpy(suspectNameAux, suspects[i].charName);
											}
										}
									}
								} else {//cabelo = all
									if (suspectsStatus[3] != 0) {//característica
										if (suspects[i].caracteristica - 48 == suspectsStatus[3]) {
											if (suspectsStatus[4] != 0) {//veículo
												if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
													//Printa o nome dele
													//Acrescenta 1 no numero de possíveis suspeitos
													printf(" %s\n", suspects[i].charName);
													nSuspeitos++;
													strcpy(suspectNameAux, suspects[i].charName);
												}
											} else {//veículo = all
												//Printa o nome dele
												//Acrescenta 1 no numero de possíveis suspeitos
												printf(" %s\n", suspects[i].charName);
												nSuspeitos++;
												strcpy(suspectNameAux, suspects[i].charName);
											}
										}
									} else {//característica = all
										if (suspectsStatus[4] != 0) {//veículo
											if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
												//Printa o nome dele
												//Acrescenta 1 no numero de possíveis suspeitos
												printf(" %s\n", suspects[i].charName);
												nSuspeitos++;
												strcpy(suspectNameAux, suspects[i].charName);
											}
										} else {//veículo = all
											//Printa o nome dele
											//Acrescenta 1 no numero de possíveis suspeitos
											printf(" %s\n", suspects[i].charName);
											nSuspeitos++;
											strcpy(suspectNameAux, suspects[i].charName);
										}
									}
								}
							}

						}
					} else {//sexo = all
						if (suspectsStatus[1] != 0) {//hobby
							if (suspects[i].hobby - 48 == suspectsStatus[1]) {
								if (suspectsStatus[2] != 0) {//cabelo
									if (suspects[i].cabelo - 48 == suspectsStatus[2]) {
										if (suspectsStatus[3] != 0) {//característica
											if (suspects[i].caracteristica - 48 == suspectsStatus[3]) {
												if (suspectsStatus[4] != 0) {//veículo
													if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
														//Printa o nome dele
														//Acrescenta 1 no numero de possíveis suspeitos
														printf(" %s\n", suspects[i].charName);
														nSuspeitos++;
														strcpy(suspectNameAux, suspects[i].charName);
													}
												} else {//veículo = all
													//Printa o nome dele
													//Acrescenta 1 no numero de possíveis suspeitos
													printf(" %s\n", suspects[i].charName);
													nSuspeitos++;
													strcpy(suspectNameAux, suspects[i].charName);
												}
											}
										} else {//característica = all
											if (suspectsStatus[4] != 0) {//veículo
												if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
													//Printa o nome dele
													//Acrescenta 1 no numero de possíveis suspeitos
													printf(" %s\n", suspects[i].charName);
													nSuspeitos++;
													strcpy(suspectNameAux, suspects[i].charName);
												}
											} else {//veículo = all
												//Printa o nome dele
												//Acrescenta 1 no numero de possíveis suspeitos
												printf(" %s\n", suspects[i].charName);
												nSuspeitos++;
												strcpy(suspectNameAux, suspects[i].charName);
											}
										}
									}
								} else {//cabelo = all
									if (suspectsStatus[3] != 0) {//característica
										if (suspects[i].caracteristica - 48 == suspectsStatus[3]) {
											if (suspectsStatus[4] != 0) {//veículo
												if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
													//Printa o nome dele
													//Acrescenta 1 no numero de possíveis suspeitos
													printf(" %s\n", suspects[i].charName);
													nSuspeitos++;
													strcpy(suspectNameAux, suspects[i].charName);
												}
											} else {//veículo = all
												//Printa o nome dele
												//Acrescenta 1 no numero de possíveis suspeitos
												printf(" %s\n", suspects[i].charName);
												nSuspeitos++;
												strcpy(suspectNameAux, suspects[i].charName);
											}
										}
									} else {//característica = all
										if (suspectsStatus[4] != 0) {//veículo
											if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
												//Printa o nome dele
												//Acrescenta 1 no numero de possíveis suspeitos
												printf(" %s\n", suspects[i].charName);
												nSuspeitos++;
												strcpy(suspectNameAux, suspects[i].charName);
											}
										} else {//veículo = all
											//Printa o nome dele
											//Acrescenta 1 no numero de possíveis suspeitos
											printf(" %s\n", suspects[i].charName);
											nSuspeitos++;
											strcpy(suspectNameAux, suspects[i].charName);
										}
									}
								}
							}
						} else {//hobby = all
							if (suspectsStatus[2] != 0) {//cabelo
								if (suspects[i].cabelo - 48 == suspectsStatus[2]) {
									if (suspectsStatus[3] != 0) {//característica
										if (suspects[i].caracteristica - 48 == suspectsStatus[3]) {
											if (suspectsStatus[4] != 0) {//veículo
												if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
													//Printa o nome dele
													//Acrescenta 1 no numero de possíveis suspeitos
													printf(" %s\n", suspects[i].charName);
													nSuspeitos++;
													strcpy(suspectNameAux, suspects[i].charName);
												}
											} else {//veículo = all
												//Printa o nome dele
												//Acrescenta 1 no numero de possíveis suspeitos
												printf(" %s\n", suspects[i].charName);
												nSuspeitos++;
												strcpy(suspectNameAux, suspects[i].charName);
											}
										}
									} else {//característica = all
										if (suspectsStatus[4] != 0) {//veículo
											if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
												//Printa o nome dele
												//Acrescenta 1 no numero de possíveis suspeitos
												printf(" %s\n", suspects[i].charName);
												nSuspeitos++;
												strcpy(suspectNameAux, suspects[i].charName);
											}
										} else {//veículo = all
											//Printa o nome dele
											//Acrescenta 1 no numero de possíveis suspeitos
											printf(" %s\n", suspects[i].charName);
											nSuspeitos++;
											strcpy(suspectNameAux, suspects[i].charName);
										}
									}
								}
							} else {//cabelo = all
								if (suspectsStatus[3] != 0) {//característica
									if (suspects[i].caracteristica - 48 == suspectsStatus[3]) {
										if (suspectsStatus[4] != 0) {//veículo
											if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
												//Printa o nome dele
												//Acrescenta 1 no numero de possíveis suspeitos
												printf(" %s\n", suspects[i].charName);
												nSuspeitos++;
												strcpy(suspectNameAux, suspects[i].charName);
											}
										} else {//veículo = all
											//Printa o nome dele
											//Acrescenta 1 no numero de possíveis suspeitos
											printf(" %s\n", suspects[i].charName);
											nSuspeitos++;
											strcpy(suspectNameAux, suspects[i].charName);
										}
									}
								} else {//característica = all
									if (suspectsStatus[4] != 0) {//veículo
										if (suspects[i].veiculo - 48 == suspectsStatus[4]) {
											//Printa o nome dele
											//Acrescenta 1 no numero de possíveis suspeitos
											printf(" %s\n", suspects[i].charName);
											nSuspeitos++;
											strcpy(suspectNameAux, suspects[i].charName);
										}
									} else {//veículo = all
										//Printa o nome dele
										//Acrescenta 1 no numero de possíveis suspeitos
										printf(" %s\n", suspects[i].charName);
										nSuspeitos++;
										strcpy(suspectNameAux, suspects[i].charName);
									}
								}
							}
						}
					}
				}
				*tempo -= 1;
				if (nSuspeitos == 0) {
					printf(" Nenhum suspeito encontrado com esses dados!\n");
					printf("----------------------------------------------------------------------\n");
				}
				else if (nSuspeitos == 1) {
					printf("----------------------------------------------------------------------\n");
					strcpy(suspeitoName, suspectNameAux);
					printf("\n Mandato de prisão para %s adquirido!\n", suspeitoName);
					warrant = 1;
				} else {
					warrant = 0;
					printf("----------------------------------------------------------------------\n");
				}
				system("pause>nul");
			case 7:
				return warrant;
				break;
		}
	} while (modificationFlag == 0);
}

void ObterSuspeitos(typeChar suspeitos[], int howManySuspects) {
	FILE *suspeitosFile;
	char caracter;
	suspeitosFile = fopen("personagens_Jogo.txt", "r");
	for (int i = 0; i < howManySuspects; i++) {
		int j = 0;
		do {
			caracter = fgetc(suspeitosFile);
			if (caracter != '-') {
				suspeitos[i].charName[j] = caracter;
				j++;
			}
		} while (caracter != '-');
		suspeitos[i].charName[j] = '\0';

		suspeitos[i].sexo = fgetc(suspeitosFile);
		caracter = fgetc(suspeitosFile);

		suspeitos[i].hobby = fgetc(suspeitosFile);
		caracter = fgetc(suspeitosFile);

		suspeitos[i].cabelo = fgetc(suspeitosFile);
		caracter = fgetc(suspeitosFile);

		suspeitos[i].caracteristica = fgetc(suspeitosFile);
		caracter = fgetc(suspeitosFile);

		suspeitos[i].veiculo = fgetc(suspeitosFile);
		caracter = fgetc(suspeitosFile);
		caracter = fgetc(suspeitosFile);
	}
	fclose(suspeitosFile);
}