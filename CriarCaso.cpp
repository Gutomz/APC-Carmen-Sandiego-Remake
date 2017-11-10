#include "Funcoes.h"

FILE *newCase;	//Variavel para o arquivo do caso novo

void CaseCreation() {

	typeCase caseToCreate;
	int flag = 0, i, modificationFlag = 0;
	char escolha[10];

	//------------------------------------------------Receber Título do Caso---------------------------------------------------//
	do {
		do {
			system("cls");
			printf("Criando o Caso\n");
			printf("Título do Caso: ");															
			scanf("%[^\n]", &caseToCreate.caseTitle);										// Receber o titulo do caso
			if ((caseToCreate.caseTitle[0] >= 65 && caseToCreate.caseTitle[0] <= 90) ||		// Verifica de está dentro do padrões
				(caseToCreate.caseTitle[0] >= 97 && caseToCreate.caseTitle[0] <= 122)) {	// Padrões: (Comçar com Letra)
				flag = 1;	//se estiver modifica a flag do loop e continua o código
			} else {
				system("cls"); //senão limpa a tela pede denovo o título
				getchar();
			}
		} while (flag == 0); //Esse loop é para caso o nome do arquivo seja invalido (Ex: 0ARQ, 'po)99,  opQ)

		strcpy(caseToCreate.fileName, caseToCreate.caseTitle);		//adicionar o nome na variavel do nome do arquivo
		strcat(caseToCreate.fileName, caseToCreate.extension);		//adicionar a extensão no nome do arquivo

		newCase = fopen(caseToCreate.fileName, "r");				//abrir o arquivo em forma de leitura
		flag = 0;
		if (newCase == NULL) {			// Verifica se o arquivo existe
			flag = 1;
			newCase = fopen(caseToCreate.fileName, "w");		//Se não existir cria um arquivo
			fprintf(newCase, "%s*\n", caseToCreate.caseTitle);
		} else {
			printf("\nCaso existente! Tente outro Nome.\nAguarde...");	//senão avisa que o arquivo existe e pede outro nome
			Sleep(2000);
			getchar();
		}
	} while (flag == 0); //Esse loop é para caso o nome do caso ja tenha sido usado!

	printf("\nTítulo criado com Sucesso!\nAguarde...");
	Sleep(1500);

	//------------------------------------------------Criar o Ladrão---------------------------------------------------//
	ThiefCreation(caseToCreate);						//Função para criar o ladrão
	printf("\nLadrão criado com Sucesso!\nAguarde...");
	Sleep(1500);
	system("cls");

	//------------------------------------------------Criar Caminho Percorrido---------------------------------------------------//
	ThiefPathCreation(caseToCreate);				//Função para criar o caminho percorrido pelo ladrão

	
	
	fclose(newCase);
}

void ThiefCreation(typeCase whichCase) {
	int flag = 0, i, modificationFlag = 0;
	char escolha[10];
	do {
		system("cls");
		printf("Criando o ladrão\n");
		printf("Nome: ");
		getchar();
		scanf("%[^\n]", whichCase.thief.charName);												//Adicionar nome do ladrao
		if ((whichCase.thief.charName[0] >= 65 && whichCase.thief.charName[0] <= 90) ||
			(whichCase.thief.charName[0] >= 97 && whichCase.thief.charName[0] <= 122)) {
			flag = 1;	//Se nome for válido sai do loop
		}
	} while (flag == 0);	//Loop de verificação do nome

	flag = 0;
	do {
		system("cls");
		printf("Criando o ladrão\n");
		printf("Sexo:\n1- Feminino\n2- Masculino\nResposta: ");
		scanf("%c", &whichCase.thief.sexo);
		if (whichCase.thief.sexo == '1' || whichCase.thief.sexo == '2') {
			flag = 1;
			whichCase.thief.sexo -= 48;
		}
	} while (flag == 0);	//Loop de verificação do sexo

	flag = 0;
	do {
		system("cls");
		printf("Criando o ladrão\n");
		printf("Hobby:\n1- Futebol\n2- Samba\n3- Praia\n4- Natação\n5- Luta\nResposta: ");
		scanf("%c", &whichCase.thief.hobby);
		if (whichCase.thief.hobby >= '1' && whichCase.thief.hobby <= '5') {
			flag = 1;
			whichCase.thief.hobby -= 48;
		}
	} while (flag == 0);	//Loop de verificação do hobby

	flag = 0;
	do {
		system("cls");
		printf("Criando o ladrão\n");
		printf("Cabelo:\n1- Preto\n2- Loiro\n3- Ruivo\n4- Castanho\n5- Grisálho\nResposta: ");
		scanf("%c", &whichCase.thief.cabelo);
		if (whichCase.thief.cabelo >= '1' && whichCase.thief.cabelo <= '5') {
			flag = 1;
			whichCase.thief.cabelo -= 48;
		}
	} while (flag == 0);	 //Loop de verificação do cabelo


	flag = 0;
	do {
		system("cls");
		printf("Criando o ladrão\n");
		printf("Caracteristica:\n1- Anel\n2- Pulseira\n3- Colar\n4- Boné\n5- Tatuagem\nResposta: ");
		scanf("%c", &whichCase.thief.caracteristica);
		if (whichCase.thief.caracteristica >= '1' && whichCase.thief.caracteristica <= '5') {
			flag = 1;
			whichCase.thief.caracteristica -= 48;
		}
	} while (flag == 0);	  //Loop de verificação da característica

	flag = 0;
	do {
		system("cls");
		printf("Criando o ladrão\n");
		printf("Veiculo:\n1- Carro\n2- Moto\n3- Helicóptero\n4- Bicicleta\n5- Jatinho\nResposta: ");
		scanf("%c", &whichCase.thief.veiculo);
		if (whichCase.thief.veiculo >= '1' && whichCase.thief.veiculo <= '5') {
			flag = 1;
			whichCase.thief.veiculo -= 48;
		}
	} while (flag == 0);	  //Loop de verificação do veículo

	system("cls");
	printf("Detalhes do Ladrão:\n\n");								//Mostrar as escolhas feitas para cada detalhe
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
	printf("\nGostaria de alterar alguma informação? (Sim/Não)\n");		//Modificação de algum detalhe
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
	} while (flag == 0);	  //Loop de verificação de resposta válida
	
	switch (escolha[0]) {		 //Switch da resposta
		case 's':	
		case 'S':	//Caso a resposta seja sim mostrar opções de mudança
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
				printf("Resposta: ");
				scanf("%c", &escolha[0]);
				if (escolha[0] >= '1' && escolha[0] <= '7') {	//Switch da escolha do que mudar
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
										printf("Hobby: Natação\n");
										break;
									case 5:
										printf("Hobby: Luta\n");
										break;
								}
								printf("Novo Hobby:\n1- Futebol\n2- Samba\n3- Praia\n4- Natação\n5- Luta\nResposta: ");
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
								printf("Novo Cabelo:\n1- Preto\n2- Loiro\n3- Ruivo\n4- Castanho\n5- Grisálho\nResposta: ");
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
								printf("Nova Caracteristica:\n1- Anel\n2- Pulseira\n3- Colar\n4- Boné\n5- Tatuagem\nResposta: ");
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
								printf("Novo Veiculo:\n1- Carro\n2- Moto\n3- Helicóptero\n4- Bicicleta\n5- Jatinho\nResposta: ");
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
			} while (modificationFlag == 0);	//Loop enquanto o usuário quiser modificar algo
			printf("\nDados Alterados com Sucesso!\nAguarde...");
			Sleep(1500);
		case 'n':
		case 'N':	//caso a resposta seja não salvar informações no arquivo
			fprintf(newCase, "%s-%i-%i-%i-%i-%i*", whichCase.thief.charName, whichCase.thief.sexo,
					whichCase.thief.hobby, whichCase.thief.cabelo, whichCase.thief.caracteristica, whichCase.thief.veiculo);
			break;
	}

}

void ThiefPathCreation(typeCase whitchCase) {
	int escolhaNum, flag = 0, count = 0, i;
	int maxPlaces = 10, modificationFlag = 0;
	char escolha[5];

	flag = 0;				//Escolher a quantidade de lugares que o ladão irá passar
	do {
		system("cls");
		printf("Criando caminho percorrido pelo ladrão\n");
		printf("Escolha quantos lugares o ladrão irá passar (2 - %i)\nResposta: ", maxPlaces);
		scanf("%i", &whitchCase.howManyPlaces);
		if (whitchCase.howManyPlaces >= 2 && whitchCase.howManyPlaces <= maxPlaces) {
			flag = 1;
		}
	} while (flag == 0);

	flag = 0;				//Mostrar os possíveis lugares para iniciar o caso
	do {
		system("cls");
		printf("Criando caminho percorrido pelo ladrão\n");
		printf("Escolha o local inicial do caso:\n");
		printf("  1- Rio Grande do Sul\n");
		printf("  2- Mato Grosso do Sul\n");
		printf("  3- Goiás\n");
		printf("  4- Espírito Santo\n");
		printf("  5- Mato Grosso\n");
		printf("  6- Santa Catarina\n");
		printf("  7- Minas Gerais\n");
		printf("  8- São Paulo\n");
		printf("  9- Paraná\n");
		printf(" 10- Rio de Janeiro\n");
		printf("Resposta: ");
		scanf("%i", &escolhaNum);
		if (escolhaNum >= 1 && escolhaNum <= 10) {
			flag = 1;
			whitchCase.thiefPath[count] = escolhaNum - 1;
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
					printf("Escolha o %i° lugar:\n", count + 1);
					printf("  1- Goiás\n");
					printf("  2- Mato Grosso do Sul\n");
					printf("  3- Espírito Santo\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 2;
								break;
							case 2:
								whitchCase.thiefPath[count] = 1;
								break;
							case 3:
								whitchCase.thiefPath[count] = 3;
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
					printf("Escolha o %i° lugar:\n", count + 1);
					printf("  1- Rio Grande do Sul\n");
					printf("  2- Mato Grosso\n");
					printf("  3- Santa Catarina\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 0;
								break;
							case 2:
								whitchCase.thiefPath[count] = 4;
								break;
							case 3:
								whitchCase.thiefPath[count] = 5;
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
					printf("Escolha anterior: Goiás\n");
					printf("Escolha o %i° lugar:\n", count + 1);
					printf("  1- Rio Grande do Sul\n");
					printf("  2- Minas Gerais\n");
					printf("  3- São Paulo\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 0;
								break;
							case 2:
								whitchCase.thiefPath[count] = 6;
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
			case ES:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Espírito Santo\n");
					printf("Escolha o %i° lugar:\n", count + 1);
					printf("  1- Rio Grande do Sul\n");
					printf("  2- Paraná\n");
					printf("  3- Rio de Janeiro\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 0;
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
			case MT:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Mato Grosso\n");
					printf("Escolha o %i° lugar:\n", count + 1);
					printf("  1- Mato Grosso do Sul\n");
					printf("  2- São Paulo\n");
					printf("  3- Minas Gerais\n");
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
								whitchCase.thiefPath[count] = 6;
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
					printf("Escolha o %i° lugar:\n", count + 1);
					printf("  1- Mato Grosso do Sul\n");
					printf("  2- Paraná\n");
					printf("  3- Minas Gerais\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 1;
								break;
							case 2:
								whitchCase.thiefPath[count] = 8;
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
			case MG:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Minas Gerais\n");
					printf("Escolha o %i° lugar:\n", count + 1);
					printf("  1- Goiás\n");
					printf("  2- Mato Grosso\n");
					printf("  3- Santa Catarina\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 2;
								break;
							case 2:
								whitchCase.thiefPath[count] = 4;
								break;
							case 3:
								whitchCase.thiefPath[count] = 5;
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
					printf("Escolha anterior: São Paulo\n");
					printf("Escolha o %i° lugar:\n", count + 1);
					printf("  1- Goiás\n");
					printf("  2- Mato Grosso\n");
					printf("  3- Rio de Janeiro\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 2;
								break;
							case 2:
								whitchCase.thiefPath[count] = 4;
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
			case PR:
				flag = 0;
				do {
					system("cls");
					printf("Escolha anterior: Paraná\n");
					printf("Escolha o %i° lugar:\n", count + 1);
					printf("  1- Espírito Santo\n");
					printf("  2- Santa Catarina\n");
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
								whitchCase.thiefPath[count] = 9;
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
					printf("Escolha o %i° lugar:\n", count + 1);
					printf("  1- Espírito Santo\n");
					printf("  2- São Paulo\n");
					printf("  3- Paraná\n");
					printf("Resposta: ");
					scanf("%i", &escolhaNum);
					if (escolhaNum >= 1 && escolhaNum <= 3) {
						switch (escolhaNum) {
							case 1:
								whitchCase.thiefPath[count] = 3;
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
		}
	} while (count < whitchCase.howManyPlaces); //Loop das escolhas dos lugares

	do {
		system("cls");
		printf("Ordem dos lugares escolhidos:\n");
		for (count = 0; count < whitchCase.howManyPlaces; count++) {
			if (count < 9){
			switch (whitchCase.thiefPath[count]) {
				case RS:
					printf("  %i- Rio Grande do Sul\n", count + 1);
					break;
				case MS:
					printf("  %i- Mato Grosso do Sul\n", count + 1);
					break;
				case GO:
					printf("  %i- Goiás\n", count + 1);
					break;
				case ES:
					printf("  %i- Espírito Santo\n", count + 1);
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
					printf("  %i- São Paulo\n", count + 1);
					break;
				case PR:
					printf("  %i- Paraná\n", count + 1);
					break;
				case RJ:
					printf("  %i- Rio de Janeiro\n", count + 1);
					break;
				}
			}
			else {
				switch (whitchCase.thiefPath[count]) {
					case RS:
						printf(" %i- Rio Grande do Sul\n", count + 1);
						break;
					case MS:
						printf(" %i- Mato Grosso do Sul\n", count + 1);
						break;
					case GO:
						printf(" %i- Goiás\n", count + 1);
						break;
					case ES:
						printf(" %i- Espírito Santo\n", count + 1);
						break;
					case MT:
						printf(" %i- Mato Grosso\n", count + 1);
						break;
					case SC:
						printf(" %i- Santa Catarina\n", count + 1);
						break;
					case MG:
						printf(" %i- Minas Gerais\n", count + 1);
						break;
					case SP:
						printf(" %i- São Paulo\n", count + 1);
						break;
					case PR:
						printf(" %i- Paraná\n", count + 1);
						break;
					case RJ:
						printf(" %i- Rio de Janeiro\n", count + 1);
						break;
				}
			}
		}
		printf("\nGostaria de alterar alguma informação? (Sim/Não)\nResposta: ");
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
					printf("Escolha a informação a ser alterada:\n");
					for (count = 0; count < whitchCase.howManyPlaces; count++) {
						if (count < 9) {
							switch (whitchCase.thiefPath[count]) {
								case RS:
									printf("  %i- Rio Grande do Sul\n", count + 1);
									break;
								case MS:
									printf("  %i- Mato Grosso do Sul\n", count + 1);
									break;
								case GO:
									printf("  %i- Goiás\n", count + 1);
									break;
								case ES:
									printf("  %i- Espírito Santo\n", count + 1);
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
									printf("  %i- São Paulo\n", count + 1);
									break;
								case PR:
									printf("  %i- Paraná\n", count + 1);
									break;
								case RJ:
									printf("  %i- Rio de Janeiro\n", count + 1);
									break;
							}
						}
						else {
							switch (whitchCase.thiefPath[count]) {
								case RS:
									printf(" %i- Rio Grande do Sul\n", count + 1);
									break;
								case MS:
									printf(" %i- Mato Grosso do Sul\n", count + 1);
									break;
								case GO:
									printf(" %i- Goiás\n", count + 1);
									break;
								case ES:
									printf(" %i- Espírito Santo\n", count + 1);
									break;
								case MT:
									printf(" %i- Mato Grosso\n", count + 1);
									break;
								case SC:
									printf(" %i- Santa Catarina\n", count + 1);
									break;
								case MG:
									printf(" %i- Minas Gerais\n", count + 1);
									break;
								case SP:
									printf(" %i- São Paulo\n", count + 1);
									break;
								case PR:
									printf(" %i- Paraná\n", count + 1);
									break;
								case RJ:
									printf(" %i- Rio de Janeiro\n", count + 1);
									break;
							}
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
									printf("Criando caminho percorrido pelo ladrão\n");
									printf("Escolha o local inicial do caso:\n");
									printf("  1- Rio Grande do Sul\n");
									printf("  2- Mato Grosso do Sul\n");
									printf("  3- Goiás\n");
									printf("  4- Espírito Santo\n");
									printf("  5- Mato Grosso\n");
									printf("  6- Santa Catarina\n");
									printf("  7- Minas Gerais\n");
									printf("  8- São Paulo\n");
									printf("  9- Paraná\n");
									printf(" 10- Rio de Janeiro\n");
									printf("Resposta: ");
									scanf("%i", &escolhaNum);
									if (escolhaNum >= 1 && escolhaNum <= 10) {
										flag = 1;
										whitchCase.thiefPath[count] = escolhaNum - 1;
									}
								} while (flag == 0);
							} else {
								switch (whitchCase.thiefPath[count - 1]) {
									case RS:
										flag = 0;
										do {
											system("cls");
											printf("Escolha anterior: Rio Grande do Sul\n");
											printf("Escolha o %i° lugar:\n", count + 1);
											printf("  1- Goiás\n");
											printf("  2- Mato Grosso do Sul\n");
											printf("  3- Espírito Santo\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 2;
														break;
													case 2:
														whitchCase.thiefPath[count] = 1;
														break;
													case 3:
														whitchCase.thiefPath[count] = 3;
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
											printf("Escolha o %i° lugar:\n", count + 1);
											printf("  1- Rio Grande do Sul\n");
											printf("  2- Mato Grosso\n");
											printf("  3- Santa Catarina\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 0;
														break;
													case 2:
														whitchCase.thiefPath[count] = 4;
														break;
													case 3:
														whitchCase.thiefPath[count] = 5;
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
											printf("Escolha anterior: Goiás\n");
											printf("Escolha o %i° lugar:\n", count + 1);
											printf("  1- Rio Grande do Sul\n");
											printf("  2- Minas Gerais\n");
											printf("  3- São Paulo\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 0;
														break;
													case 2:
														whitchCase.thiefPath[count] = 6;
														break;
													case 3:
														whitchCase.thiefPath[count] = 7;
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
											printf("Escolha anterior: Espírito Santo\n");
											printf("Escolha o %i° lugar:\n", count + 1);
											printf("  1- Rio Grande do Sul\n");
											printf("  2- Paraná\n");
											printf("  3- Rio de Janeiro\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 0;
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
									case MT:
										flag = 0;
										do {
											system("cls");
											printf("Escolha anterior: Mato Grosso\n");
											printf("Escolha o %i° lugar:\n", count + 1);
											printf("  1- Mato Grosso do Sul\n");
											printf("  2- São Paulo\n");
											printf("  3- Minas Gerais\n");
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
														whitchCase.thiefPath[count] = 6;
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
											printf("Escolha o %i° lugar:\n", count + 1);
											printf("  1- Mato Grosso do Sul\n");
											printf("  2- Paraná\n");
											printf("  3- Minas Gerais\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 1;
														break;
													case 2:
														whitchCase.thiefPath[count] = 8;
														break;
													case 3:
														whitchCase.thiefPath[count] = 6;
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
											printf("Escolha o %i° lugar:\n", count + 1);
											printf("  1- Goiás\n");
											printf("  2- Mato Grosso\n");
											printf("  3- Santa Catarina\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 2;
														break;
													case 2:
														whitchCase.thiefPath[count] = 4;
														break;
													case 3:
														whitchCase.thiefPath[count] = 5;
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
											printf("Escolha anterior: São Paulo\n");
											printf("Escolha o %i° lugar:\n", count + 1);
											printf("  1- Goiás\n");
											printf("  2- Mato Grosso\n");
											printf("  3- Rio de Janeiro\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 2;
														break;
													case 2:
														whitchCase.thiefPath[count] = 4;
														break;
													case 3:
														whitchCase.thiefPath[count] = 9;
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
											printf("Escolha anterior: Paraná\n");
											printf("Escolha o %i° lugar:\n", count + 1);
											printf("  1- Espírito Santo\n");
											printf("  2- Santa Catarina\n");
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
														whitchCase.thiefPath[count] = 9;
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
											printf("Escolha o %i° lugar:\n", count + 1);
											printf("  1- Espírito Santo\n");
											printf("  2- São Paulo\n");
											printf("  3- Paraná\n");
											printf("Resposta: ");
											scanf("%i", &escolhaNum);
											if (escolhaNum >= 1 && escolhaNum <= 3) {
												switch (escolhaNum) {
													case 1:
														whitchCase.thiefPath[count] = 3;
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
	} while (modificationFlag == 0);	  //Loop de modificação

	fprintf(newCase, "\n%i*\n", whitchCase.howManyPlaces);				//colocar no arquivo os dados recolhidos
	for (count = 0; count < whitchCase.howManyPlaces; count++) {
		if (count == whitchCase.howManyPlaces - 1) {
			fprintf(newCase, "%i*\n", whitchCase.thiefPath[count]);
		} else {
			fprintf(newCase, "%i-", whitchCase.thiefPath[count]);
		}
	}

	printf("\nCaminho criado com sucesso!\nAguarde...");
	Sleep(1500);

	modificationFlag = 0;	//Selecionar em que lugar vai estar o esconderijo no ultimo estado selecionado
	do {
		flag = 0;
		do {
			system("cls");
			switch (whitchCase.thiefPath[whitchCase.howManyPlaces - 1]) {
				case RS:
					printf("O último estado em que o ladrão vai passar é Rio Grande do Sul.\n");
					break;
				case MS:
					printf("O último estado em que o ladrão vai passar é Mato Grosso do Sul.\n");
					break;
				case GO:
					printf("O último estado em que o ladrão vai passar é Goiás.\n");
					break;
				case ES:
					printf("O último estado em que o ladrão vai passar é Espírito Santo.\n");
					break;
				case MT:
					printf("O último estado em que o ladrão vai passar é Mato Grosso.\n");
					break;
				case SC:
					printf("O último estado em que o ladrão vai passar é Santa Catarina.\n");
					break;
				case MG:
					printf("O último estado em que o ladrão vai passar é Minas Gerais.\n");
					break;
				case SP:
					printf("O último estado em que o ladrão vai passar é São Paulo.\n");
					break;
				case PR:
					printf("O último estado em que o ladrão vai passar é Paraná.\n");
					break;
				case RJ:
					printf("O último estado em que o ladrão vai passar é Rio de Janeiro.\n");
					break;
			}
			printf("Escolha a localização do esconderijo:\n");
			printf("  1- Praça\n");
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
			printf("Localização do esconderijo: \n");
			switch (whitchCase.thiefPath[whitchCase.howManyPlaces - 1]) {
				case RS:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Rio Grande do Sul --> Praça\n");
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
							printf("  Mato Grosso do Sul --> Praça\n");
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
							printf("  Goiás --> Praça\n");
							break;
						case 2:
							printf("  Goiás --> Hotel\n");
							break;
						case 3:
							printf("  Goiás --> Banco\n");
							break;
					}
					break;
				case ES:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Espírito Santo --> Praça\n");
							break;
						case 2:
							printf("  Espírito Santo --> Hotel\n");
							break;
						case 3:
							printf("  Espírito Santo --> Banco\n");
							break;
					}
					break;
				case MT:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Mato Grosso --> Praça\n");
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
							printf("  Santa Catarina --> Praça\n");
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
							printf("  Minas Gerais --> Praça\n");
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
							printf("  São Paulo --> Praça\n");
							break;
						case 2:
							printf("  São Paulo --> Hotel\n");
							break;
						case 3:
							printf("  São Paulo --> Banco\n");
							break;
					}
					break;
				case PR:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Paraná --> Praça\n");
							break;
						case 2:
							printf("  Paraná --> Hotel\n");
							break;
						case 3:
							printf("  Paraná --> Banco\n");
							break;
					}
					break;
				case RJ:
					switch (whitchCase.hideout) {
						case 1:
							printf("  Rio de Janeiro --> Praça\n");
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
			printf("\nGostaria de alterar a localização final? (Sim/Não)\nResposta: ");
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

	} while (modificationFlag == 0);	  //Loop de modificação do lugar selecionado
	fprintf(newCase, "%i*\n", whitchCase.hideout);

	printf("\nEsconderijo criado com sucesso!\nAguarde...");
	Sleep(1500);
	system("cls");

	//Ir para Receber a hitória do caso e as dicas em cada lugar
	TipsCreation(whitchCase.thiefPath, whitchCase.howManyPlaces, whitchCase);
}

void TipsCreation(char path[], int howManyPlaces, typeCase caseToCreate) {

	int flag = 0, i, j, k, modificationFlag = 0, escolhaNum;
	char escolha[10];

	//------------------------------------------------Receber História---------------------------------------------------//
	flag = 0;
	do {
		system("cls");
		printf("Criando o Caso\n");
		printf("Introduza uma história inicial que será apresentada ao jogador:\n  ");
		getchar();
		scanf("%[^\n]", &caseToCreate.history);		//Recebe a história
		if ((caseToCreate.history[0] >= 65 && caseToCreate.history[0] <= 90) ||			//verifica se começa com uma letra
			(caseToCreate.history[0] >= 97 && caseToCreate.history[0] <= 122)) {
			flag = 1;			//Se sim continua o código
		} else {
			system("cls");		//senão pede uma história novamente
		}
	} while (flag == 0);		//Loop para receber uma história inicial
	printf("\nAguarde...");
	Sleep(1500);
  
	do {
		getchar();
		system("cls");
		printf("História Criada:\n\n  %s\n", caseToCreate.history);
		printf("\nGostaria de reescrever? (Sim/Não)\nResposta: ");
		flag = 0;
		do {
			scanf("%s", &escolha);	//Recebe resposta
			if (escolha[0] != 'N' && escolha[0] != 'S' && escolha[0] != 'n' && escolha[0] != 's') {	//verifica se é sim ou nao
				for (i = 0; i < 110; i++) {//tela 120
					printf("\b \b");		//Se não for nenhuma das opções volta o ponteiro e pergunta novamente
				}
			} else {
				flag = 1;			//se for s ou n continua
			}
		} while (flag == 0);		//Loop de resposta válida

		switch (escolha[0]) {		//Switch da escolha do usuario
			case 's':
			case'S':		//se a escolha foi sim então pede para o usuario introduzir uma história nova
				flag = 0;
				do {
					system("cls");
					printf("Criando o Caso\n");
					printf("Introduza uma história inicial que será apresentada ao jogador:\n  ");		//Receber uma historia inicial
					getchar();
					scanf("%[^\n]", &caseToCreate.history); //Recebe a história
					if ((caseToCreate.history[0] >= 65 && caseToCreate.history[0] <= 90) ||
						(caseToCreate.history[0] >= 97 && caseToCreate.history[0] <= 122)) {
						flag = 1;	//se estiver dentro dos padrões continua
					} else {
						system("cls");	//se não pede novamente
					}
				} while (flag == 0);		//Loop de verificação da história
				printf("\nAguarde...");
				Sleep(1500);
				//Depois que sair do switch vai perguntar se quer modificar a história
				break;
			case 'n':	//se a escolha for não então continua o código
			case 'N':
				modificationFlag = 1;
				break;
		}
	} while (modificationFlag == 0);	//Loop de modificação da história criada

	fprintf(newCase, "%s*\n", caseToCreate.history);											//Colocar a história em um arquivo

	printf("\nHistória criada com Sucesso!\nAguarde...");
	Sleep(1500);																		//Esperar resposta do usuario


	//-----------------------------------------------Receber Dicas ----------------------------------------------------//
	for (i = 0; i < howManyPlaces - 1; i++) {
		for (j = 1; j <= 3; j++) {
			flag = 0;
			do {
				system("cls");
				printf("Ciando Dicas\n");
				switch (caseToCreate.thiefPath[i]) {
					case RS:
						printf("O %i° local escolhido foi Rio Grande do Sul\n", i + 1);
						switch (j) {
							case 1:
								printf("Insira uma dica para ser descoberta na Praça:\n  ");
								break;
							case 2:
								printf("Insira uma dica para ser descoberta no Hotel:\n  ");
								break;
							case 3:
								printf("Insira uma dica para ser descoberta no Banco:\n  ");
								break;
						}
						break;
					case MS:
						printf("O %i° local escolhido foi Mato Grosso do Sul\n", i + 1);
						switch (j) {
							case 1:
								printf("Insira uma dica para ser descoberta na Praça:\n  ");
								break;
							case 2:
								printf("Insira uma dica para ser descoberta no Hotel:\n  ");
								break;
							case 3:
								printf("Insira uma dica para ser descoberta no Banco:\n  ");
								break;
						}
						break;
					case GO:
						printf("O %i° local escolhido foi Goiás\n", i + 1);
						switch (j) {
							case 1:
								printf("Insira uma dica para ser descoberta na Praça:\n  ");
								break;
							case 2:
								printf("Insira uma dica para ser descoberta no Hotel:\n  ");
								break;
							case 3:
								printf("Insira uma dica para ser descoberta no Banco:\n  ");
								break;
						}
						break;
					case ES:
						printf("O %i° local escolhido foi Espírito Santo\n", i + 1);
						switch (j) {
							case 1:
								printf("Insira uma dica para ser descoberta na Praça:\n  ");
								break;
							case 2:
								printf("Insira uma dica para ser descoberta no Hotel:\n  ");
								break;
							case 3:
								printf("Insira uma dica para ser descoberta no Banco:\n  ");
								break;
						}
						break;
					case MT:
						printf("O %i° local escolhido foi Mato Grosso\n", i + 1);
						switch (j) {
							case 1:
								printf("Insira uma dica para ser descoberta na Praça:\n  ");
								break;
							case 2:
								printf("Insira uma dica para ser descoberta no Hotel:\n  ");
								break;
							case 3:
								printf("Insira uma dica para ser descoberta no Banco:\n  ");
								break;
						}
						break;
					case SC:
						printf("O %i° local escolhido foi Santa Catarina\n", i + 1);
						switch (j) {
							case 1:
								printf("Insira uma dica para ser descoberta na Praça:\n  ");
								break;
							case 2:
								printf("Insira uma dica para ser descoberta no Hotel:\n  ");
								break;
							case 3:
								printf("Insira uma dica para ser descoberta no Banco:\n  ");
								break;
						}
						break;
					case MG:
						printf("O %i° local escolhido foi Minas Gerais\n", i + 1);
						switch (j) {
							case 1:
								printf("Insira uma dica para ser descoberta na Praça:\n  ");
								break;
							case 2:
								printf("Insira uma dica para ser descoberta no Hotel:\n  ");
								break;
							case 3:
								printf("Insira uma dica para ser descoberta no Banco:\n  ");
								break;
						}
						break;
					case SP:
						printf("O %i° local escolhido foi São Paulo\n", i + 1);
						switch (j) {
							case 1:
								printf("Insira uma dica para ser descoberta na Praça:\n  ");
								break;
							case 2:
								printf("Insira uma dica para ser descoberta no Hotel:\n  ");
								break;
							case 3:
								printf("Insira uma dica para ser descoberta no Banco:\n  ");
								break;
						}
						break;
					case PR:
						printf("O %i° local escolhido foi Paraná\n", i + 1);
						switch (j) {
							case 1:
								printf("Insira uma dica para ser descoberta na Praça:\n  ");
								break;
							case 2:
								printf("Insira uma dica para ser descoberta no Hotel:\n  ");
								break;
							case 3:
								printf("Insira uma dica para ser descoberta no Banco:\n  ");
								break;
						}
						break;
					case RJ:
						printf("O %i° local escolhido foi Rio de Janeiro\n", i + 1);
						switch (j) {
							case 1:
								printf("Insira uma dica para ser descoberta na Praça:\n  ");
								break;
							case 2:
								printf("Insira uma dica para ser descoberta no Hotel:\n  ");
								break;
							case 3:
								printf("Insira uma dica para ser descoberta no Banco:\n  ");
								break;
						}
						break;
				}
				getchar();
				scanf("%[^\n]", &caseToCreate.tips[j - 1][i]);
				if ((caseToCreate.tips[j-1][i][0] >= 65 && caseToCreate.tips[j-1][i][0] <= 90) ||	//verifica se começa com uma letra
					(caseToCreate.tips[j-1][i][0] >= 97 && caseToCreate.tips[j-1][i][0] <= 122)) {
					flag = 1;			//Se sim continua o código
				}
			} while (flag == 0);
		}

		system("cls");
		switch (caseToCreate.thiefPath[i]) {
			case RS:
				printf("As dicas para a Praça, Hotel e Banco, respectivamente, do Rio Grande do Sul foram:\n");
				break;
			case MS:
				printf("As dicas para a Praça, Hotel e Banco, respectivamente, do Mato Grosso do Sul foram:\n");
				break;
			case GO:
				printf("As dicas para a Praça, Hotel e Banco, respectivamente, de Goiás foram:\n");
				break;
			case ES:
				printf("As dicas para a Praça, Hotel e Banco, respectivamente, do Espírito Santo foram:\n");
				break;
			case MT:
				printf("As dicas para a Praça, Hotel e Banco, respectivamente, do Mato Grosso foram:\n");
				break;
			case SC:
				printf("As dicas para a Praça, Hotel e Banco, respectivamente, de Santa Catarina foram:\n");
				break;
			case MG:
				printf("As dicas para a Praça, Hotel e Banco, respectivamente, de Minas Gerais foram:\n");
				break;
			case SP:
				printf("As dicas para a Praça, Hotel e Banco, respectivamente, de São Paulo foram:\n");
				break;
			case PR:
				printf("As dicas para a Praça, Hotel e Banco, respectivamente, do Paraná foram:\n");
				break;
			case RJ:
				printf("As dicas para a Praça, Hotel e Banco, respectivamente, do Rio de Janeiro foram:\n");
				break;
		}
		for (j = 1; j <= 3; j++) {
			printf("  %i- \"%s\"\n\n", j, caseToCreate.tips[j - 1][i]);
		}
		printf("Gostria de reescrever alguma dica? (Sim/Não)\nRsposta: ");
		flag = 0;
		do {
			scanf("%s", &escolha);
			if (escolha[0] != 'N' && escolha[0] != 'S' && escolha[0] != 'n' && escolha[0] != 's') {	//verifica se é sim ou nao
				for (k = 0; k < 110; k++) {//tela 120
					printf("\b \b");		//Se não for nenhuma das opções volta o ponteiro e pergunta novamente
				}
			} else {
				flag = 1;			//se for s ou n continua
			}
		} while (flag == 0);
		switch (escolha[0]) {		//Switch da escolha do usuario
			case 's':
			case'S':		//se a escolha foi sim então pede para o usuario introduzir uma dica nova
				modificationFlag = 0;
				do {
					system("cls");
					printf("Escolha a dica que será modificada\n");
					for (j = 1; j <= 3; j++) {
						printf("  %i- \"%s\"\n\n", j, caseToCreate.tips[j - 1][i]);
					}
					printf("  4- Confirmar modificações.\n\n");
					printf("Resposta: ");
					do {
						scanf("%i", &escolhaNum);
						if (escolhaNum < 1 || escolhaNum > 4) {
							for (k = 0; k < 110; k++) {//tela 120
								printf("\b \b");		//Se não for nenhuma das opções volta o ponteiro e pergunta novamente
							}
						}
					} while (escolhaNum < 1 || escolhaNum > 4);
					switch (escolhaNum) {
						case 4:
							modificationFlag = 1;
							break;
						default:
							flag = 0;
							do {
								system("cls");
								printf("Ciando Dicas\n");
								switch (caseToCreate.thiefPath[i]) {
									case RS:
										printf("O %i° local escolhido foi Rio Grande do Sul\n", i + 1);
										switch (escolhaNum) {
											case 1:
												printf("Insira uma dica para ser descoberta na Praça:\n  ");
												break;
											case 2:
												printf("Insira uma dica para ser descoberta no Hotel:\n  ");
												break;
											case 3:
												printf("Insira uma dica para ser descoberta no Banco:\n  ");
												break;
										}
										break;
									case MS:
										printf("O %i° local escolhido foi Mato Grosso do Sul\n", i + 1);
										switch (escolhaNum) {
											case 1:
												printf("Insira uma dica para ser descoberta na Praça:\n  ");
												break;
											case 2:
												printf("Insira uma dica para ser descoberta no Hotel:\n  ");
												break;
											case 3:
												printf("Insira uma dica para ser descoberta no Banco:\n  ");
												break;
										}
										break;
									case GO:
										printf("O %i° local escolhido foi Goiás\n", i + 1);
										switch (escolhaNum) {
											case 1:
												printf("Insira uma dica para ser descoberta na Praça:\n  ");
												break;
											case 2:
												printf("Insira uma dica para ser descoberta no Hotel:\n  ");
												break;
											case 3:
												printf("Insira uma dica para ser descoberta no Banco:\n  ");
												break;
										}
										break;
									case ES:
										printf("O %i° local escolhido foi Espírito Santo\n", i + 1);
										switch (escolhaNum) {
											case 1:
												printf("Insira uma dica para ser descoberta na Praça:\n  ");
												break;
											case 2:
												printf("Insira uma dica para ser descoberta no Hotel:\n  ");
												break;
											case 3:
												printf("Insira uma dica para ser descoberta no Banco:\n  ");
												break;
										}
										break;
									case MT:
										printf("O %i° local escolhido foi Mato Grosso\n", i + 1);
										switch (escolhaNum) {
											case 1:
												printf("Insira uma dica para ser descoberta na Praça:\n  ");
												break;
											case 2:
												printf("Insira uma dica para ser descoberta no Hotel:\n  ");
												break;
											case 3:
												printf("Insira uma dica para ser descoberta no Banco:\n  ");
												break;
										}
										break;
									case SC:
										printf("O %i° local escolhido foi Santa Catarina\n", i + 1);
										switch (escolhaNum) {
											case 1:
												printf("Insira uma dica para ser descoberta na Praça:\n  ");
												break;
											case 2:
												printf("Insira uma dica para ser descoberta no Hotel:\n  ");
												break;
											case 3:
												printf("Insira uma dica para ser descoberta no Banco:\n  ");
												break;
										}
										break;
									case MG:
										printf("O %i° local escolhido foi Minas Gerais\n", i + 1);
										switch (escolhaNum) {
											case 1:
												printf("Insira uma dica para ser descoberta na Praça:\n  ");
												break;
											case 2:
												printf("Insira uma dica para ser descoberta no Hotel:\n  ");
												break;
											case 3:
												printf("Insira uma dica para ser descoberta no Banco:\n  ");
												break;
										}
										break;
									case SP:
										printf("O %i° local escolhido foi São Paulo\n", i + 1);
										switch (escolhaNum) {
											case 1:
												printf("Insira uma dica para ser descoberta na Praça:\n  ");
												break;
											case 2:
												printf("Insira uma dica para ser descoberta no Hotel:\n  ");
												break;
											case 3:
												printf("Insira uma dica para ser descoberta no Banco:\n  ");
												break;
										}
										break;
									case PR:
										printf("O %i° local escolhido foi Paraná\n", i + 1);
										switch (escolhaNum) {
											case 1:
												printf("Insira uma dica para ser descoberta na Praça:\n  ");
												break;
											case 2:
												printf("Insira uma dica para ser descoberta no Hotel:\n  ");
												break;
											case 3:
												printf("Insira uma dica para ser descoberta no Banco:\n  ");
												break;
										}
										break;
									case RJ:
										printf("O %i° local escolhido foi Rio de Janeiro\n", i + 1);
										switch (escolhaNum) {
											case 1:
												printf("Insira uma dica para ser descoberta na Praça:\n  ");
												break;
											case 2:
												printf("Insira uma dica para ser descoberta no Hotel:\n  ");
												break;
											case 3:
												printf("Insira uma dica para ser descoberta no Banco:\n  ");
												break;
										}
										break;
								}
								getchar();
								scanf("%[^\n]", &caseToCreate.tips[escolhaNum - 1][i]);
								if ((caseToCreate.tips[escolhaNum-1][i][0] >= 65 && caseToCreate.tips[escolhaNum - 1][i][0] <= 90) ||	//verifica se começa com uma letra
									(caseToCreate.tips[escolhaNum - 1][i][0] >= 97 && caseToCreate.tips[escolhaNum - 1][i][0] <= 122)) {
									flag = 1;			//Se sim continua o código
								}
							} while (flag == 0);
							break;
					}
				} while (modificationFlag == 0);
				break;
			case 'n':	//se a escolha for não então continua o código
			case 'N':
				break;
		}
	}
	for (i = 0; i < howManyPlaces - 1; i++) {
		for (j = 0; j < 3; j++) {
			fprintf(newCase, "%s*\n", caseToCreate.tips[j][i]);
		}
		
	}
}

