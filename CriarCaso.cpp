#include "Funcoes.h"

FILE *newCase;	//Variavel para o arquivo do caso novo

void CaseCreation() {

	typeCase caseToCreate;
	int flag = 0, i, modificationFlag = 0;
	char escolha[10];
	
	do {
		do {
			system("cls");
			printf("Criando o Caso\n");
			printf("T�tulo do Caso: ");															// Receber o titulo do caso
			scanf("%[^\n]", &caseToCreate.caseTitle);
			if ((caseToCreate.caseTitle[0] >= 65 && caseToCreate.caseTitle[0] <= 90) ||
				(caseToCreate.caseTitle[0] >= 97 && caseToCreate.caseTitle[0] <= 122)) {
				flag = 1;
			} else {
				system("cls");
				getchar();
			}
		} while (flag == 0); //Esse loop � para caso o nome do arquivo seja invalido (Ex: 0ARQ, 'po)99,  opQ)

		strcpy(caseToCreate.fileName, caseToCreate.caseTitle);
		strcat(caseToCreate.fileName, caseToCreate.extension);
		newCase = fopen(caseToCreate.fileName, "r");
		flag = 0;
		if (newCase == NULL) {
			flag = 1;
			newCase = fopen(caseToCreate.fileName, "w");
			fprintf(newCase, "%s*\n", caseToCreate.caseTitle);										//Colocar no arquivo o titulo do caso
		} else {
			printf("\nCaso existente! Tente outro Nome.\nAguarde...");
			Sleep(2350);
			getchar();
		}
	} while (flag == 0); //Esse loop � para caso o nome do caso ja tenha sido usado!

	printf("\nT�tulo criado com Sucesso!\nAguarde...");
	Sleep(1500);

	flag = 0;
	do {
		system("cls");
		printf("Criando o Caso\n");
		printf("Introduza uma hist�ria inicial que ser� apresentada ao jogador:\n");		//Receber uma historia inicial
		getchar();
		scanf("%[^\n]", &caseToCreate.history);
		if ((caseToCreate.history[0] >= 65 && caseToCreate.history[0] <= 90) ||
			(caseToCreate.history[0] >= 97 && caseToCreate.history[0] <= 122)) {
			flag = 1;
		} else {
			system("cls");
		}
	} while (flag == 0);
	printf("\nAguarde...");
	Sleep(1500);

	do {
		getchar();
		system("cls");
		printf("Hist�ria Criada:\n\n  %s\n", caseToCreate.history);
		printf("\nGostaria de reescrever? (Sim/N�o)\nResposta: ");
		flag = 0;
		do {
			scanf("%s", &escolha);
			if (escolha[0] != 'N' && escolha[0] != 'S' && escolha[0] != 'n' && escolha[0] != 's') {
				for (i = 0; i < 110; i++) {//tela 120
					printf("\b \b");
				}
			} else {
				flag = 1;
			}
		} while (flag == 0);
		switch (escolha[0]) {
			case 's':
			case'S':
				flag = 0;
				do {
					system("cls");
					printf("Criando o Caso\n");
					printf("Introduza uma hist�ria inicial que ser� apresentada ao jogador:\n");		//Receber uma historia inicial
					getchar();
					scanf("%[^\n]", &caseToCreate.history);
					if ((caseToCreate.history[0] >= 65 && caseToCreate.history[0] <= 90) ||
						(caseToCreate.history[0] >= 97 && caseToCreate.history[0] <= 122)) {
						flag = 1;
					} else {
						system("cls");
					}
				} while (flag == 0);
				printf("\nAguarde...");
				Sleep(1500);
				break;
			case 'n':
			case 'N':
				modificationFlag = 1;
				break;
		}
	} while (modificationFlag == 0);

	fprintf(newCase,"%s*\n", caseToCreate.history);											//Colocar a hist�ria em um arquivo

	printf("\nHist�ria criada com Sucesso!\nAguarde...");
	Sleep(1500);																		//Esperar resposta do usuario

	ThiefCreation(caseToCreate);
	printf("\nLadr�o criado com Sucesso!\nAguarde...");
	Sleep(1500);
	system("cls");

	ThiefPathCreation(caseToCreate);

	fclose(newCase);
}

void ThiefCreation(typeCase whichCase) {
	int flag = 0, i, modificationFlag = 0;
	char escolha[10];
	do {
		system("cls");
		printf("Criando o ladr�o\n");
		printf("Nome: ");
		getchar();
		scanf("%[^\n]", whichCase.thief.charName);												//Adicionar nome do ladrao
		if ((whichCase.thief.charName[0] >= 65 && whichCase.thief.charName[0] <= 90) ||
			(whichCase.thief.charName[0] >= 97 && whichCase.thief.charName[0] <= 122)) {
			flag = 1;
		}
	} while (flag == 0);

	flag = 0;
	do {
		system("cls");
		printf("Criando o ladr�o\n");
		printf("Sexo:\n1- Feminino\n2- Masculino\nResposta: ");
		scanf("%c", &whichCase.thief.sexo);
		if (whichCase.thief.sexo == '1' || whichCase.thief.sexo == '2') {
			flag = 1;
			whichCase.thief.sexo -= 48;
		}
	} while (flag == 0);

	flag = 0;
	do {
		system("cls");
		printf("Criando o ladr�o\n");
		printf("Hobby:\n1- Futebol\n2- Samba\n3- Praia\n4- Nata��o\n5- Luta\nResposta: ");
		scanf("%c", &whichCase.thief.hobby);
		if (whichCase.thief.hobby >= '1' && whichCase.thief.hobby <= '5') {
			flag = 1;
			whichCase.thief.hobby -= 48;
		}
	} while (flag == 0);

	flag = 0;
	do {
		system("cls");
		printf("Criando o ladr�o\n");
		printf("Cabelo:\n1- Preto\n2- Loiro\n3- Ruivo\n4- Castanho\n5- Gris�lho\nResposta: ");
		scanf("%c", &whichCase.thief.cabelo);
		if (whichCase.thief.cabelo >= '1' && whichCase.thief.cabelo <= '5') {
			flag = 1;
			whichCase.thief.cabelo -= 48;
		}
	} while (flag == 0);


	flag = 0;
	do {
		system("cls");
		printf("Criando o ladr�o\n");
		printf("Caracteristica:\n1- Anel\n2- Pulseira\n3- Colar\n4- Bon�\n5- Tatuagem\nResposta: ");
		scanf("%c", &whichCase.thief.caracteristica);
		if (whichCase.thief.caracteristica >= '1' && whichCase.thief.caracteristica <= '5') {
			flag = 1;
			whichCase.thief.caracteristica -= 48;
		}
	} while (flag == 0);

	flag = 0;
	do {
		system("cls");
		printf("Criando o ladr�o\n");
		printf("Veiculo:\n1- Carro\n2- Moto\n3- Helic�ptero\n4- Bicicleta\n5- Jatinho\nResposta: ");
		scanf("%c", &whichCase.thief.veiculo);
		if (whichCase.thief.veiculo >= '1' && whichCase.thief.veiculo <= '5') {
			flag = 1;
			whichCase.thief.veiculo -= 48;
		}
	} while (flag == 0);

	system("cls");
	printf("Detalhes do Ladr�o:\n\n");
	printf("Nome:               %s\n", whichCase.thief.charName);
	switch (whichCase.thief.sexo) {
		case 1:
			printf("Sexo:               Feminino\n");
			break;
		case 2:
			printf("Sexo:               Masculino\n");
			break;
	}
	switch (whichCase.thief.hobby) {
		case 1:
			printf("Hobby:              Futebol\n");
			break;
		case 2:
			printf("Hobby:              Samba\n");
			break;
		case 3:
			printf("Hobby:              Praia\n");
			break;
		case 4:
			printf("Hobby:              Nata��o\n");
			break;
		case 5:
			printf("Hobby:              Luta\n");
			break;
	}
	switch (whichCase.thief.cabelo) {
		case 1:
			printf("Cabelo:             Preto\n");
			break;
		case 2:
			printf("Cabelo:             Loiro\n");
			break;
		case 3:
			printf("Cabelo:             Ruivo\n");
			break;
		case 4:
			printf("Cabelo:             Castanho\n");
			break;
		case 5:
			printf("Cabelo:             Gris�lho\n");
			break;
	}
	switch (whichCase.thief.caracteristica) {
		case 1:
			printf("Caracter�stica:     Anel\n");
			break;
		case 2:
			printf("Caracter�stica:     Pulseira\n");
			break;
		case 3:
			printf("Caracter�stica:     Colar\n");
			break;
		case 4:
			printf("Caracter�stica:     Bon�\n");
			break;
		case 5:
			printf("Caracter�stica:     Tatuagem\n");
			break;
	}
	switch (whichCase.thief.veiculo) {
		case 1:
			printf("Ve�culo:            Carro\n");
			break;
		case 2:
			printf("Ve�culo:            Moto\n");
			break;
		case 3:
			printf("Ve�culo:            Helic�ptero\n");
			break;
		case 4:
			printf("Ve�culo:            Bicicleta\n");
			break;
		case 5:
			printf("Ve�culo:            Jatinho\n");
			break;
	}

	flag = 0;
	printf("\nGostaria de alterar alguma informa��o? (Sim/N�o)\n");
	printf("Resposta: ");
	do {
		scanf("%s", &escolha);
		if (escolha[0] != 'N' && escolha[0] != 'S' && escolha[0] != 'n' && escolha[0] != 's') {
			for (i = 0; i < 110; i++) {//tela 120
				printf("\b \b");
			}
		} else {
			flag = 1;
		}
	} while (flag == 0);
	
	switch (escolha[0]) {
		case 's':
		case 'S':
			do {
				system("cls");
				printf("Escolha uma informa��o para ser alterada:\n");
				printf("  1- Nome:                      %s\n", whichCase.thief.charName);
				switch (whichCase.thief.sexo) {
					case 1:
						printf("  2- Sexo:                      Feminino\n");
						break;
					case 2:
						printf("  2- Sexo:                      Masculino\n");
						break;
				}
				switch (whichCase.thief.hobby) {
					case 1:
						printf("  3- Hobby:                     Futebol\n");
						break;
					case 2:
						printf("  3- Hobby:                     Samba\n");
						break;
					case 3:
						printf("  3- Hobby:                     Praia\n");
						break;
					case 4:
						printf("  3- Hobby:                     Nata��o\n");
						break;
					case 5:
						printf("  3- Hobby:                     Luta\n");
						break;
				}
				switch (whichCase.thief.cabelo) {
					case 1:
						printf("  4- Cabelo:                    Preto\n");
						break;
					case 2:
						printf("  4- Cabelo:                    Loiro\n");
						break;
					case 3:
						printf("  4- Cabelo:                    Ruivo\n");
						break;
					case 4:
						printf("  4- Cabelo:                    Castanho\n");
						break;
					case 5:
						printf("  4- Cabelo:                    Gris�lho\n");
						break;
				}
				switch (whichCase.thief.caracteristica) {
					case 1:
						printf("  5- Caracter�stica:            Anel\n");
						break;
					case 2:
						printf("  5- Caracter�stica:            Pulseira\n");
						break;
					case 3:
						printf("  5- Caracter�stica:            Colar\n");
						break;
					case 4:
						printf("  5- Caracter�stica:            Bon�\n");
						break;
					case 5:
						printf("  5- Caracter�stica:            Tatuagem\n");
						break;
				}
				switch (whichCase.thief.veiculo) {
					case 1:
						printf("  6- Ve�culo:                   Carro\n");
						break;
					case 2:
						printf("  6- Ve�culo:                   Moto\n");
						break;
					case 3:
						printf("  6- Ve�culo:                   Helic�ptero\n");
						break;
					case 4:
						printf("  6- Ve�culo:                   Bicicleta\n");
						break;
					case 5:
						printf("  6- Ve�culo:                   Jatinho\n");
						break;
				}
				printf("  7- Confirmar Modifica��es.\n");
				printf("Resposta: ");
				scanf("%c", &escolha[0]);
				if (escolha[0] >= '1' && escolha[0] <= '7') {
					switch (escolha[0]) {
						case '1':
							flag = 0;
							do {
								system("cls");
								printf("Modificando o Nome\n");
								printf("Nome: %s\n", whichCase.thief.charName);
								printf("Novo Nome: ");
								getchar();
								scanf("%[^\n]", &whichCase.thief.charName);												//Adicionar nome do ladrao
								if ((whichCase.thief.charName[0] >= 65 && whichCase.thief.charName[0] <= 90) ||
									(whichCase.thief.charName[0] >= 97 && whichCase.thief.charName[0] <= 122)) {
									flag = 1;
								}
							} while (flag == 0);
							break;
						case '2':
							flag = 0;
							do {
								system("cls");
								printf("Modificando o Sexo\n");
								switch (whichCase.thief.sexo) {
									case 1:
										printf("Sexo: Feminino\n");
										break;
									case 2:
										printf("Sexo: Masculino\n");
										break;
								}
								printf("Novo Sexo:\n1- Feminino\n2- Masculino\nResposta: ");
								scanf("%c", &whichCase.thief.sexo);
								if (whichCase.thief.sexo == '1' || whichCase.thief.sexo == '2') {
									flag = 1;
									whichCase.thief.sexo -= 48;
								}
							} while (flag == 0);
							break;
						case '3':
							flag = 0;
							do {
								system("cls");
								printf("Modificando o Hobby\n");
								switch (whichCase.thief.hobby) {
									case 1:
										printf("Hobby: Futebol\n");
										break;
									case 2:
										printf("Hobby: Samba\n");
										break;
									case 3:
										printf("Hobby: Praia\n");
										break;
									case 4:
										printf("Hobby: Nata��o\n");
										break;
									case 5:
										printf("Hobby: Luta\n");
										break;
								}
								printf("Novo Hobby:\n1- Futebol\n2- Samba\n3- Praia\n4- Nata��o\n5- Luta\nResposta: ");
								scanf("%c", &whichCase.thief.hobby);
								if (whichCase.thief.hobby >= '1' && whichCase.thief.hobby <= '5') {
									flag = 1;
									whichCase.thief.hobby -= 48;
								}
							} while (flag == 0);
							break;
						case '4':
							flag = 0;
							do {
								system("cls");
								printf("Modificando o Cabelo\n");
								switch (whichCase.thief.cabelo) {
									case 1:
										printf("Cabelo: Preto\n");
										break;
									case 2:
										printf("Cabelo: Loiro\n");
										break;
									case 3:
										printf("Cabelo: Ruivo\n");
										break;
									case 4:
										printf("Cabelo: Castanho\n");
										break;
									case 5:
										printf("Cabelo: Gris�lho\n");
										break;
								}
								printf("Novo Cabelo:\n1- Preto\n2- Loiro\n3- Ruivo\n4- Castanho\n5- Gris�lho\nResposta: ");
								scanf("%c", &whichCase.thief.cabelo);
								if (whichCase.thief.cabelo >= '1' && whichCase.thief.cabelo <= '5') {
									flag = 1;
									whichCase.thief.cabelo -= 48;
								}
							} while (flag == 0);
							break;
						case '5':
							flag = 0;
							do {
								system("cls");
								printf("Modificando a Caracter�stica\n");
								switch (whichCase.thief.caracteristica) {
									case 1:
										printf("Caracter�stica: Anel\n");
										break;
									case 2:
										printf("Caracter�stica: Pulseira\n");
										break;
									case 3:
										printf("Caracter�stica: Colar\n");
										break;
									case 4:
										printf("Caracter�stica: Bon�\n");
										break;
									case 5:
										printf("Caracter�stica: Tatuagem\n");
										break;
								}
								printf("Nova Caracteristica:\n1- Anel\n2- Pulseira\n3- Colar\n4- Bon�\n5- Tatuagem\nResposta: ");
								scanf("%c", &whichCase.thief.caracteristica);
								if (whichCase.thief.caracteristica >= '1' && whichCase.thief.caracteristica <= '5') {
									flag = 1;
									whichCase.thief.caracteristica -= 48;
								}
							} while (flag == 0);
							break;
						case '6':
							flag = 0;
							do {
								system("cls");
								printf("Modificando o Ve�culo\n");
								switch (whichCase.thief.veiculo) {
									case 1:
										printf("Ve�culo: Carro\n");
										break;
									case 2:
										printf("Ve�culo: Moto\n");
										break;
									case 3:
										printf("Ve�culo: Helic�ptero\n");
										break;
									case 4:
										printf("Ve�culo: Bicicleta\n");
										break;
									case 5:
										printf("Ve�culo: Jatinho\n");
										break;
								}
								printf("Novo Veiculo:\n1- Carro\n2- Moto\n3- Helic�ptero\n4- Bicicleta\n5- Jatinho\nResposta: ");
								scanf("%c", &whichCase.thief.veiculo);
								if (whichCase.thief.veiculo >= '1' && whichCase.thief.veiculo <= '5') {
									flag = 1;
									whichCase.thief.veiculo -= 48;
								}
							} while (flag == 0);
							break;
						case '7':
							modificationFlag = 1;
							break;
					}
				}
			}while (modificationFlag == 0);
			printf("\nDados Alterados com Sucesso!\nAguarde...");
			Sleep(1500);
		case 'n':
		case 'N':
			fprintf(newCase, "%s-%i-%i-%i-%i-%i*", whichCase.thief.charName, whichCase.thief.sexo,
					whichCase.thief.hobby, whichCase.thief.cabelo, whichCase.thief.caracteristica, whichCase.thief.veiculo);
			break;
	}

}

void ThiefPathCreation(typeCase whitchCase) {
	int escolhaNum, flag = 0, count = 0, i;
	int maxPlaces = 10, modificationFlag = 0;
	char escolha[5];

	flag = 0;
	do {
		system("cls");
		printf("Criando caminho percorrido pelo ladr�o\n");
		printf("Escolha quantos lugares o ladr�o ir� passar (2 - %i)\nResposta: ", maxPlaces);
		scanf("%i", &whitchCase.howManyPlaces);
		if (whitchCase.howManyPlaces >= 2 && whitchCase.howManyPlaces <= maxPlaces) {
			flag = 1;
		}
	} while (flag == 0);
	flag = 0;
	do {
		system("cls");
		printf("Criando caminho percorrido pelo ladr�o\n");
		printf("Escolha o local inicial do caso:\n");
		printf("  1- Rio Grande do Sul\n");
		printf("  2- Mato Grosso do Sul\n");
		printf("  3- Goi�s\n");
		printf("  4- Esp�rito Santo\n");
		printf("  5- Mato Grosso\n");
		printf("  6- Santa Catarina\n");
		printf("  7- Minas Gerais\n");
		printf("  8- S�o Paulo\n");
		printf("  9- Paran�\n");
		printf(" 10- Rio de Janeiro\n");
		printf("Resposta: ");
		scanf("%i", &escolhaNum);
		if (escolhaNum >= 1 && escolhaNum <= 10) {
			flag = 1;
			whitchCase.thiefPath[count] = escolhaNum;
			count++;
		}
	} while (flag == 0);

	do {
		system("cls");
		switch (whitchCase.thiefPath[count - 1]) {
			case RS:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Rio Grande do Sul\n");
					printf("Escolha o %i� lugar:\n", count + 1);
					printf("  1- Goi�s\n");
					printf("  2- Mato Grosso do Sul\n");
					printf("  3- Esp�rito Santo\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 3;
								break;
							case 2:
								whitchCase.thiefPath[count] = 2;
								break;
							case 3:
								whitchCase.thiefPath[count] = 4;
								break;
						}
						flag = 1;
						count++;
					}
				} while (flag == 0);
				break;
			case MS:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Mato Grosso do Sul\n");
					printf("Escolha o %i� lugar:\n", count + 1);
					printf("  1- Rio Grande do Sul\n");
					printf("  2- Mato Grosso\n");
					printf("  3- Santa Catarina\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 1;
								break;
							case 2:
								whitchCase.thiefPath[count] = 5;
								break;
							case 3:
								whitchCase.thiefPath[count] = 6;
								break;
						}
						flag = 1;
						count++;
					}
				} while (flag == 0);
				break;
			case GO:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Goi�s\n");
					printf("Escolha o %i� lugar:\n", count + 1);
					printf("  1- Rio Grande do Sul\n");
					printf("  2- Minas Gerais\n");
					printf("  3- S�o Paulo\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 1;
								break;
							case 2:
								whitchCase.thiefPath[count] = 7;
								break;
							case 3:
								whitchCase.thiefPath[count] = 8;
								break;
						}
						flag = 1;
						count++;
					}
				} while (flag == 0);
				break;
			case ES:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Esp�rito Santo\n");
					printf("Escolha o %i� lugar:\n", count + 1);
					printf("  1- Rio Grande do Sul\n");
					printf("  2- Paran�\n");
					printf("  3- Rio de Janeiro\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 1;
								break;
							case 2:
								whitchCase.thiefPath[count] = 9;
								break;
							case 3:
								whitchCase.thiefPath[count] = 10;
								break;
						}
						flag = 1;
						count++;
					}
				} while (flag == 0);
				break;
			case MT:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Mato Grosso\n");
					printf("Escolha o %i� lugar:\n", count + 1);
					printf("  1- Mato Grosso do Sul\n");
					printf("  2- S�o Paulo\n");
					printf("  3- Minas Gerais\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 2;
								break;
							case 2:
								whitchCase.thiefPath[count] = 8;
								break;
							case 3:
								whitchCase.thiefPath[count] = 7;
								break;
						}
						flag = 1;
						count++;
					}
				} while (flag == 0);
				break;
			case SC:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Santa Catarina\n");
					printf("Escolha o %i� lugar:\n", count + 1);
					printf("  1- Mato Grosso do Sul\n");
					printf("  2- Paran�\n");
					printf("  3- Minas Gerais\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 2;
								break;
							case 2:
								whitchCase.thiefPath[count] = 9;
								break;
							case 3:
								whitchCase.thiefPath[count] = 7;
								break;
						}
						flag = 1;
						count++;
					}
				} while (flag == 0);
				break;
			case MG:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Minas Gerais\n");
					printf("Escolha o %i� lugar:\n", count + 1);
					printf("  1- Goi�s\n");
					printf("  2- Mato Grosso\n");
					printf("  3- Santa Catarina\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 3;
								break;
							case 2:
								whitchCase.thiefPath[count] = 5;
								break;
							case 3:
								whitchCase.thiefPath[count] = 6;
								break;
						}
						flag = 1;
						count++;
					}
				} while (flag == 0);
				break;
			case SP:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: S�o Paulo\n");
					printf("Escolha o %i� lugar:\n", count + 1);
					printf("  1- Goi�s\n");
					printf("  2- Mato Grosso\n");
					printf("  3- Rio de Janeiro\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 3;
								break;
							case 2:
								whitchCase.thiefPath[count] = 5;
								break;
							case 3:
								whitchCase.thiefPath[count] = 10;
								break;
						}
						flag = 1;
						count++;
					}
				} while (flag == 0);
				break;
			case PR:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Paran�\n");
					printf("Escolha o %i� lugar:\n", count + 1);
					printf("  1- Esp�rito Santo\n");
					printf("  2- Santa Catarina\n");
					printf("  3- Rio de Janeiro\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 4;
								break;
							case 2:
								whitchCase.thiefPath[count] = 6;
								break;
							case 3:
								whitchCase.thiefPath[count] = 10;
								break;
						}
						flag = 1;
						count++;
					}
				} while (flag == 0);
				break;
			case RJ:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Rio de Janeiro\n");
					printf("Escolha o %i� lugar:\n", count + 1);
					printf("  1- Esp�rito Santo\n");
					printf("  2- S�o Paulo\n");
					printf("  3- Paran�\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 4;
								break;
							case 2:
								whitchCase.thiefPath[count] = 8;
								break;
							case 3:
								whitchCase.thiefPath[count] = 9;
								break;
						}
						flag = 1;
						count++;
					}
				} while (flag == 0);
				break;
		}
	} while (count < whitchCase.howManyPlaces);
	do {
		system("cls");
		printf("Ordem dos lugares escolhidos:\n");
		for (count = 0; count < whitchCase.howManyPlaces; count++) {
			switch (whitchCase.thiefPath[count]) {
				case RS:
					printf("  %i- Rio Grande do Sul\n", count + 1);
					break;
				case MS:
					printf("  %i- Mato Grosso do Sul\n", count + 1);
					break;
				case GO:
					printf("  %i- Goi�s\n", count + 1);
					break;
				case ES:
					printf("  %i- Esp�rito Santo\n", count + 1);
					break;
				case MT:
					printf("  %i- Mato Grosso\n", count + 1);
					break;
				case SC:
					printf("  %i- Santa Catarina\n", count + 1);
					break;
				case MG:
					printf("  %i- Minas Gerais\n", count + 1);
					break;
				case SP:
					printf("  %i- S�o Paulo\n", count + 1);
					break;
				case PR:
					printf("  %i- Paran�\n", count + 1);
					break;
				case RJ:
					printf("  %i- Rio de Janeiro\n", count + 1);
					break;
			}
		}
		printf("\nGostaria de alterar alguma informa��o? (Sim/N�o)\nResposta: ");
		scanf("%s", &escolha);
		if (escolha[0] != 'n' && escolha[0] != 'N' && escolha[0] != 's' && escolha[0] != 'S') {
			for (i = 0; i < 110; i++) { //tela 120
				printf("\b \b");
			}
		} else {
			switch (escolha[0]) {
				case 's':
				case 'S':
					system("cls");
					printf("Escolha a informa��o a ser alterada:\n");
					for (count = 0; count < whitchCase.howManyPlaces; count++) {
						switch (whitchCase.thiefPath[count]) {
							case RS:
								printf("  %i- Rio Grande do Sul\n", count + 1);
								break;
							case MS:
								printf("  %i- Mato Grosso do Sul\n", count + 1);
								break;
							case GO:
								printf("  %i- Goi�s\n", count + 1);
								break;
							case ES:
								printf("  %i- Esp�rito Santo\n", count + 1);
								break;
							case MT:
								printf("  %i- Mato Grosso\n", count + 1);
								break;
							case SC:
								printf("  %i- Santa Catarina\n", count + 1);
								break;
							case MG:
								printf("  %i- Minas Gerais\n", count + 1);
								break;
							case SP:
								printf("  %i- S�o Paulo\n", count + 1);
								break;
							case PR:
								printf("  %i- Paran�\n", count + 1);
								break;
							case RJ:
								printf("  %i- Rio de Janeiro\n", count + 1);
								break;
						}
					}
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= whitchCase.howManyPlaces) {
						for (count = escolhaNum - 1; count < whitchCase.howManyPlaces; count++) {
							system("cls");
							if (count == 0) {
								flag = 0;
								do {
									system("cls");
									printf("Criando caminho percorrido pelo ladr�o\n");
									printf("Escolha o local inicial do caso:\n");
									printf("  1- Rio Grande do Sul\n");
									printf("  2- Mato Grosso do Sul\n");
									printf("  3- Goi�s\n");
									printf("  4- Esp�rito Santo\n");
									printf("  5- Mato Grosso\n");
									printf("  6- Santa Catarina\n");
									printf("  7- Minas Gerais\n");
									printf("  8- S�o Paulo\n");
									printf("  9- Paran�\n");
									printf(" 10- Rio de Janeiro\n");
									printf("Resposta: ");
									scanf("%i", &escolhaNum);
									if (escolhaNum >= 1 && escolhaNum <= 10) {
										flag = 1;
										whitchCase.thiefPath[count] = escolhaNum;
									}
								} while (flag == 0);
							} else {
								switch (whitchCase.thiefPath[count - 1]) {
									case RS:
										flag = 0;
										do {
											system("cls");
											printf("Escolha anterior: Rio Grande do Sul\n");
											printf("Escolha o %i� lugar:\n", count + 1);
											printf("  1- Goi�s\n");
											printf("  2- Mato Grosso do Sul\n");
											printf("  3- Esp�rito Santo\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 3;
														break;
													case 2:
														whitchCase.thiefPath[count] = 2;
														break;
													case 3:
														whitchCase.thiefPath[count] = 4;
														break;
												}
												flag = 1;
											}
										} while (flag == 0);
										break;
									case MS:
										flag = 0;
										do {
											system("cls");
											printf("Escolha anterior: Mato Grosso do Sul\n");
											printf("Escolha o %i� lugar:\n", count + 1);
											printf("  1- Rio Grande do Sul\n");
											printf("  2- Mato Grosso\n");
											printf("  3- Santa Catarina\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 1;
														break;
													case 2:
														whitchCase.thiefPath[count] = 5;
														break;
													case 3:
														whitchCase.thiefPath[count] = 6;
														break;
												}
												flag = 1;
											}
										} while (flag == 0);
										break;
									case GO:
										flag = 0;
										do {
											system("cls");
											printf("Escolha anterior: Goi�s\n");
											printf("Escolha o %i� lugar:\n", count + 1);
											printf("  1- Rio Grande do Sul\n");
											printf("  2- Minas Gerais\n");
											printf("  3- S�o Paulo\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 1;
														break;
													case 2:
														whitchCase.thiefPath[count] = 7;
														break;
													case 3:
														whitchCase.thiefPath[count] = 8;
														break;
												}
												flag = 1;
											}
										} while (flag == 0);
										break;
									case ES:
										flag = 0;
										do {
											system("cls");
											printf("Escolha anterior: Esp�rito Santo\n");
											printf("Escolha o %i� lugar:\n", count + 1);
											printf("  1- Rio Grande do Sul\n");
											printf("  2- Paran�\n");
											printf("  3- Rio de Janeiro\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 1;
														break;
													case 2:
														whitchCase.thiefPath[count] = 9;
														break;
													case 3:
														whitchCase.thiefPath[count] = 10;
														break;
												}
												flag = 1;
											}
										} while (flag == 0);
										break;
									case MT:
										flag = 0;
										do {
											system("cls");
											printf("Escolha anterior: Mato Grosso\n");
											printf("Escolha o %i� lugar:\n", count + 1);
											printf("  1- Mato Grosso do Sul\n");
											printf("  2- S�o Paulo\n");
											printf("  3- Minas Gerais\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 2;
														break;
													case 2:
														whitchCase.thiefPath[count] = 8;
														break;
													case 3:
														whitchCase.thiefPath[count] = 7;
														break;
												}
												flag = 1;
											}
										} while (flag == 0);
										break;
									case SC:
										flag = 0;
										do {
											system("cls");
											printf("Escolha anterior: Santa Catarina\n");
											printf("Escolha o %i� lugar:\n", count + 1);
											printf("  1- Mato Grosso do Sul\n");
											printf("  2- Paran�\n");
											printf("  3- Minas Gerais\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 2;
														break;
													case 2:
														whitchCase.thiefPath[count] = 9;
														break;
													case 3:
														whitchCase.thiefPath[count] = 7;
														break;
												}
												flag = 1;
											}
										} while (flag == 0);
										break;
									case MG:
										flag = 0;
										do {
											system("cls");
											printf("Escolha anterior: Minas Gerais\n");
											printf("Escolha o %i� lugar:\n", count + 1);
											printf("  1- Goi�s\n");
											printf("  2- Mato Grosso\n");
											printf("  3- Santa Catarina\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 3;
														break;
													case 2:
														whitchCase.thiefPath[count] = 5;
														break;
													case 3:
														whitchCase.thiefPath[count] = 6;
														break;
												}
												flag = 1;
											}
										} while (flag == 0);
										break;
									case SP:
										flag = 0;
										do {
											system("cls");
											printf("Escolha anterior: S�o Paulo\n");
											printf("Escolha o %i� lugar:\n", count + 1);
											printf("  1- Goi�s\n");
											printf("  2- Mato Grosso\n");
											printf("  3- Rio de Janeiro\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 3;
														break;
													case 2:
														whitchCase.thiefPath[count] = 5;
														break;
													case 3:
														whitchCase.thiefPath[count] = 10;
														break;
												}
												flag = 1;
											}
										} while (flag == 0);
										break;
									case PR:
										flag = 0;
										do {
											system("cls");
											printf("Escolha anterior: Paran�\n");
											printf("Escolha o %i� lugar:\n", count + 1);
											printf("  1- Esp�rito Santo\n");
											printf("  2- Santa Catarina\n");
											printf("  3- Rio de Janeiro\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 4;
														break;
													case 2:
														whitchCase.thiefPath[count] = 6;
														break;
													case 3:
														whitchCase.thiefPath[count] = 10;
														break;
												}
												flag = 1;
											}
										} while (flag == 0);
										break;
									case RJ:
										flag = 0;
										do {
											system("cls");
											printf("Escolha anterior: Rio de Janeiro\n");
											printf("Escolha o %i� lugar:\n", count + 1);
											printf("  1- Esp�rito Santo\n");
											printf("  2- S�o Paulo\n");
											printf("  3- Paran�\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 4;
														break;
													case 2:
														whitchCase.thiefPath[count] = 8;
														break;
													case 3:
														whitchCase.thiefPath[count] = 9;
														break;
												}
												flag = 1;
											}
										} while (flag == 0);
										break;
								}
							}
						}
					}
					break;
				case 'n':
				case 'N':
					modificationFlag = 1;
					break;
			}
		}
	} while (modificationFlag == 0);
	fprintf(newCase, "\n%i*\n", whitchCase.howManyPlaces);
	for (count = 0; count < whitchCase.howManyPlaces; count++) {
		if (count == whitchCase.howManyPlaces - 1) {
			fprintf(newCase, "%i*\n", whitchCase.thiefPath[count]);
		} else {
			fprintf(newCase, "%i-", whitchCase.thiefPath[count]);
		}
	}

	printf("\nCaminho criado com sucesso!\nAguarde...");
	Sleep(1500);

	modificationFlag = 0;
	do {
		flag = 0;
		do {
			system("cls");
			switch (whitchCase.thiefPath[whitchCase.howManyPlaces - 1]) {
				case RS:
					printf("O �ltimo estado em que o ladr�o vai passar � Rio Grande do Sul.\n");
					break;
				case MS:
					printf("O �ltimo estado em que o ladr�o vai passar � Mato Grosso do Sul.\n");
					break;
				case GO:
					printf("O �ltimo estado em que o ladr�o vai passar � Goi�s.\n");
					break;
				case ES:
					printf("O �ltimo estado em que o ladr�o vai passar � Esp�rito Santo.\n");
					break;
				case MT:
					printf("O �ltimo estado em que o ladr�o vai passar � Mato Grosso.\n");
					break;
				case SC:
					printf("O �ltimo estado em que o ladr�o vai passar � Santa Catarina.\n");
					break;
				case MG:
					printf("O �ltimo estado em que o ladr�o vai passar � Minas Gerais.\n");
					break;
				case SP:
					printf("O �ltimo estado em que o ladr�o vai passar � S�o Paulo.\n");
					break;
				case PR:
					printf("O �ltimo estado em que o ladr�o vai passar � Paran�.\n");
					break;
				case RJ:
					printf("O �ltimo estado em que o ladr�o vai passar � Rio de Janeiro.\n");
					break;
			}
			printf("Escolha a localiza��o do esconderijo:\n");
			printf("  1- Pra�a\n");
			printf("  2- Hotel\n");
			printf("  3- Banco\n");
			printf("Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 3) {
				flag = 1;
				whitchCase.hideout = escolhaNum;
			}
		} while (flag == 0);
		flag = 0;
		do {
			system("cls");
			printf("Localiza��o do esconderijo: \n");
			switch (whitchCase.thiefPath[whitchCase.howManyPlaces - 1]) {
				case RS:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Rio Grande do Sul --> Pra�a\n");
							break;
						case 2:
							printf("  Rio Grande do Sul --> Hotel\n");
							break;
						case 3:
							printf("  Rio Grande do Sul --> Banco\n");
							break;
					}
					break;
				case MS:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Mato Grosso do Sul --> Pra�a\n");
							break;
						case 2:
							printf("  Mato Grosso do Sul --> Hotel\n");
							break;
						case 3:
							printf("  Mato Grosso do Sul --> Banco\n");
							break;
					}
					break;
				case GO:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Goi�s --> Pra�a\n");
							break;
						case 2:
							printf("  Goi�s --> Hotel\n");
							break;
						case 3:
							printf("  Goi�s --> Banco\n");
							break;
					}
					break;
				case ES:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Esp�rito Santo --> Pra�a\n");
							break;
						case 2:
							printf("  Esp�rito Santo --> Hotel\n");
							break;
						case 3:
							printf("  Esp�rito Santo --> Banco\n");
							break;
					}
					break;
				case MT:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Mato Grosso --> Pra�a\n");
							break;
						case 2:
							printf("  Mato Grosso --> Hotel\n");
							break;
						case 3:
							printf("  Mato Grosso --> Banco\n");
							break;
					}
					break;
				case SC:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Santa Catarina --> Pra�a\n");
							break;
						case 2:
							printf("  Santa Catarina --> Hotel\n");
							break;
						case 3:
							printf("  Santa Catarina --> Banco\n");
							break;
					}
					break;
				case MG:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Minas Gerais --> Pra�a\n");
							break;
						case 2:
							printf("  Minas Gerais --> Hotel\n");
							break;
						case 3:
							printf("  Minas Gerais --> Banco\n");
							break;
					}
					break;
				case SP:
					switch (whitchCase.hideout) {
						case 1:
							printf("  S�o Paulo --> Pra�a\n");
							break;
						case 2:
							printf("  S�o Paulo --> Hotel\n");
							break;
						case 3:
							printf("  S�o Paulo --> Banco\n");
							break;
					}
					break;
				case PR:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Paran� --> Pra�a\n");
							break;
						case 2:
							printf("  Paran� --> Hotel\n");
							break;
						case 3:
							printf("  Paran� --> Banco\n");
							break;
					}
					break;
				case RJ:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Rio de Janeiro --> Pra�a\n");
							break;
						case 2:
							printf("  Rio de Janeiro --> Hotel\n");
							break;
						case 3:
							printf("  Rio de Janeiro --> Banco\n");
							break;
					}
					break;
			}
			printf("\nGostaria de alterar a localiza��o final? (Sim/N�o)\nResposta: ");
			scanf("%s", &escolha);
			if (escolha[0] != 'n' && escolha[0] != 'N' && escolha[0] != 's' && escolha[0] != 'S') {
				for (i = 0; i < 110; i++) { //tela 120
					printf("\b \b");
				}
			} else {
				switch (escolha[0]) {
					case 'n':
					case 'N':
						modificationFlag = 1;
					case 's':
					case 'S':
						break;
				}
				flag = 1;
			}
		} while (flag == 0);

	} while (modificationFlag == 0);
	fprintf(newCase, "%i*\n", whitchCase.hideout);

	printf("\nEsconderijo criado com sucesso!\nAguarde...");
	Sleep(1500);
	system("cls");

	TipsCreation(whitchCase.thiefPath, whitchCase.howManyPlaces);
}

void TipsCreation(char path[], int howManyPlaces) {


	printf("Ciando Dicas\n");

}