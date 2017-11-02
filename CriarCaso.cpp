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
			printf("Título do Caso: ");															// Receber o titulo do caso
			scanf("%[^\n]", &caseToCreate.caseTitle);
			if ((caseToCreate.caseTitle[0] >= 65 && caseToCreate.caseTitle[0] <= 90) ||
				(caseToCreate.caseTitle[0] >= 97 && caseToCreate.caseTitle[0] <= 122)) {
				flag = 1;
			} else {
				system("cls");
				getchar();
			}
		} while (flag == 0); //Esse loop é para caso o nome do arquivo seja invalido (Ex: 0ARQ, 'po)99,  opQ)

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
	} while (flag == 0); //Esse loop é para caso o nome do caso ja tenha sido usado!

	printf("\nTítulo criado com Sucesso!\nAguarde...");
	Sleep(2000);

	flag = 0;
	do {
		system("cls");
		printf("Criando o Caso\n");
		printf("Introduza uma história inicial que será apresentada ao jogador:\n");		//Receber uma historia inicial
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
		printf("História Criada:\n\n  %s\n", caseToCreate.history);
		printf("\nGostaria de reescrever? (Sim/Não)\nResposta: ");
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
					printf("Introduza uma história inicial que será apresentada ao jogador:\n");		//Receber uma historia inicial
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

	fprintf(newCase,"%s*\n", caseToCreate.history);											//Colocar a história em um arquivo

	printf("\nHistória criada com Sucesso!\nAguarde...");
	Sleep(2000);																		//Esperar resposta do usuario

	ThiefCreation(caseToCreate);
	printf("\nLadrão criado com Sucesso!\nAguarde...");
	Sleep(2000);
	system("cls");

}

void ThiefCreation(typeCase whichCase) {
	int flag = 0, lenght, i, modificationFlag = 0;
	char escolha[10];
	do {
		system("cls");
		printf("Criando o ladrão\n");
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
		printf("Criando o ladrão\n");
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
		printf("Criando o ladrão\n");
		printf("Hobby:\n1- Futebol\n2- Samba\n3- Praia\n4- Natação\n5- Luta\nEscolha: ");
		scanf("%c", &whichCase.thief.hobby);
		if (whichCase.thief.hobby >= '1' && whichCase.thief.hobby <= '5') {
			flag = 1;
			whichCase.thief.hobby -= 48;
		}
	} while (flag == 0);

	flag = 0;
	do {
		system("cls");
		printf("Criando o ladrão\n");
		printf("Cabelo:\n1- Preto\n2- Loiro\n3- Ruivo\n4- Castanho\n5- Grisálho\nEscolha: ");
		scanf("%c", &whichCase.thief.cabelo);
		if (whichCase.thief.cabelo >= '1' && whichCase.thief.cabelo <= '5') {
			flag = 1;
			whichCase.thief.cabelo -= 48;
		}
	} while (flag == 0);


	flag = 0;
	do {
		system("cls");
		printf("Criando o ladrão\n");
		printf("Caracteristica:\n1- Anel\n2- Pulseira\n3- Colar\n4- Boné\n5- Tatuagem\nEscolha: ");
		scanf("%c", &whichCase.thief.caracteristica);
		if (whichCase.thief.caracteristica >= '1' && whichCase.thief.caracteristica <= '5') {
			flag = 1;
			whichCase.thief.caracteristica -= 48;
		}
	} while (flag == 0);

	flag = 0;
	do {
		system("cls");
		printf("Criando o ladrão\n");
		printf("Veiculo:\n1- Carro\n2- Moto\n3- Helicóptero\n4- Bicicleta\n5- Jatinho\nEscolha: ");
		scanf("%c", &whichCase.thief.veiculo);
		if (whichCase.thief.veiculo >= '1' && whichCase.thief.veiculo <= '5') {
			flag = 1;
			whichCase.thief.veiculo -= 48;
		}
	} while (flag == 0);

	system("cls");
	printf("Detalhes do Ladrão:\n\n");
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
			printf("Hobby:              Natação\n");
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
			printf("Cabelo:             Grisálho\n");
			break;
	}
	switch (whichCase.thief.caracteristica) {
		case 1:
			printf("Característica:     Anel\n");
			break;
		case 2:
			printf("Característica:     Pulseira\n");
			break;
		case 3:
			printf("Característica:     Colar\n");
			break;
		case 4:
			printf("Característica:     Boné\n");
			break;
		case 5:
			printf("Característica:     Tatuagem\n");
			break;
	}
	switch (whichCase.thief.veiculo) {
		case 1:
			printf("Veículo:            Carro\n");
			break;
		case 2:
			printf("Veículo:            Moto\n");
			break;
		case 3:
			printf("Veículo:            Helicóptero\n");
			break;
		case 4:
			printf("Veículo:            Bicicleta\n");
			break;
		case 5:
			printf("Veículo:            Jatinho\n");
			break;
	}

	flag = 0;
	printf("\nGostaria de alterar alguma informação? (Sim/Não)\n");
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
				printf("Escolha uma informação para ser alterada:\n");
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
						printf("  3- Hobby:                     Natação\n");
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
						printf("  4- Cabelo:                    Grisálho\n");
						break;
				}
				switch (whichCase.thief.caracteristica) {
					case 1:
						printf("  5- Característica:            Anel\n");
						break;
					case 2:
						printf("  5- Característica:            Pulseira\n");
						break;
					case 3:
						printf("  5- Característica:            Colar\n");
						break;
					case 4:
						printf("  5- Característica:            Boné\n");
						break;
					case 5:
						printf("  5- Característica:            Tatuagem\n");
						break;
				}
				switch (whichCase.thief.veiculo) {
					case 1:
						printf("  6- Veículo:                   Carro\n");
						break;
					case 2:
						printf("  6- Veículo:                   Moto\n");
						break;
					case 3:
						printf("  6- Veículo:                   Helicóptero\n");
						break;
					case 4:
						printf("  6- Veículo:                   Bicicleta\n");
						break;
					case 5:
						printf("  6- Veículo:                   Jatinho\n");
						break;
				}
				printf("  7- Confirmar Modificações.\n");
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
										printf("Hobby: Natação\n");
										break;
									case 5:
										printf("Hobby: Luta\n");
										break;
								}
								printf("Novo Hobby:\n1- Futebol\n2- Samba\n3- Praia\n4- Natação\n5- Luta\nEscolha: ");
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
										printf("Cabelo: Grisálho\n");
										break;
								}
								printf("Novo Cabelo:\n1- Preto\n2- Loiro\n3- Ruivo\n4- Castanho\n5- Grisálho\nEscolha: ");
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
								printf("Modificando a Característica\n");
								switch (whichCase.thief.caracteristica) {
									case 1:
										printf("Característica: Anel\n");
										break;
									case 2:
										printf("Característica: Pulseira\n");
										break;
									case 3:
										printf("Característica: Colar\n");
										break;
									case 4:
										printf("Característica: Boné\n");
										break;
									case 5:
										printf("Característica: Tatuagem\n");
										break;
								}
								printf("Nova Caracteristica:\n1- Anel\n2- Pulseira\n3- Colar\n4- Boné\n5- Tatuagem\nEscolha: ");
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
								printf("Modificando o Veículo\n");
								switch (whichCase.thief.veiculo) {
									case 1:
										printf("Veículo: Carro\n");
										break;
									case 2:
										printf("Veículo: Moto\n");
										break;
									case 3:
										printf("Veículo: Helicóptero\n");
										break;
									case 4:
										printf("Veículo: Bicicleta\n");
										break;
									case 5:
										printf("Veículo: Jatinho\n");
										break;
								}
								printf("Novo Veiculo:\n1- Carro\n2- Moto\n3- Helicóptero\n4- Bicicleta\n5- Jatinho\nEscolha: ");
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