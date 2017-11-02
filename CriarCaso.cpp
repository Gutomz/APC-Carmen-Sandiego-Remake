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
			Sleep(3000);
			getchar();
		}
	} while (flag == 0); //Esse loop � para caso o nome do caso ja tenha sido usado!

	printf("\nT�tulo criado com Sucesso!\nAguarde...");
	Sleep(2000);

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
	Sleep(2000);																		//Esperar resposta do usuario

	ThiefCreation(caseToCreate);
	printf("\nLadr�o criado com Sucesso!\nAguarde...");
	Sleep(2000);
	system("cls");

}

void ThiefCreation(typeCase whichCase) {
	int flag = 0, lenght, i, modificationFlag = 0;
	char escolha[10];
	do {
		system("cls");
		printf("Criando o ladr�o\n");
		printf("Nome: ");
		getchar();
		scanf("%[^\n]", &whichCase.thief.charName);												//Adicionar nome do ladrao
		if ((whichCase.thief.charName[0] >= 65 && whichCase.thief.charName[0] <= 90) ||
			(whichCase.thief.charName[0] >= 97 && whichCase.thief.charName[0] <= 122)) {
			flag = 1;
		}
	} while (flag == 0);

	flag = 0;
	do {
		system("cls");
		printf("Criando o ladr�o\n");
		printf("Sexo:\n1- Feminino\n2- Masculino\nEscolha: ");
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
		printf("Hobby:\n1- Futebol\n2- Samba\n3- Praia\n4- Nata��o\n5- Luta\nEscolha: ");
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
		printf("Cabelo:\n1- Preto\n2- Loiro\n3- Ruivo\n4- Castanho\n5- Gris�lho\nEscolha: ");
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
		printf("Caracteristica:\n1- Anel\n2- Pulseira\n3- Colar\n4- Bon�\n5- Tatuagem\nEscolha: ");
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
		printf("Veiculo:\n1- Carro\n2- Moto\n3- Helic�ptero\n4- Bicicleta\n5- Jatinho\nEscolha: ");
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
			lenght = strlen(escolha);
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
				printf("Escolha: ");
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
								printf("Novo Sexo:\n1- Feminino\n2- Masculino\nEscolha: ");
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
								printf("Novo Hobby:\n1- Futebol\n2- Samba\n3- Praia\n4- Nata��o\n5- Luta\nEscolha: ");
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
								printf("Novo Cabelo:\n1- Preto\n2- Loiro\n3- Ruivo\n4- Castanho\n5- Gris�lho\nEscolha: ");
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
								printf("Nova Caracteristica:\n1- Anel\n2- Pulseira\n3- Colar\n4- Bon�\n5- Tatuagem\nEscolha: ");
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
								printf("Novo Veiculo:\n1- Carro\n2- Moto\n3- Helic�ptero\n4- Bicicleta\n5- Jatinho\nEscolha: ");
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
			Sleep(2000);
		case 'n':
		case 'N':
			fprintf(newCase, "%s-%i-%i-%i-%i-%i*", whichCase.thief.charName, whichCase.thief.sexo,
					whichCase.thief.hobby, whichCase.thief.cabelo, whichCase.thief.caracteristica, whichCase.thief.veiculo);
			break;
	}

}