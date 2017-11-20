#include "Funcoes.h"

FILE *newCase;	//Variavel para o arquivo do caso novo
FILE *caseFile;

void CaseCreation() {
	typeCase caseToCreate;
	int flag = 0, modificationFlag = 0, difficulty = 1;

	//------------------------------------------------Receber T�tulo do Caso---------------------------------------------------//
	do {
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                        CRIAR CASO - T�TULO                         |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" T�tulo do Caso: ");
			getchar();
			scanf("%[^\n]", &caseToCreate.caseTitle);										// Receber o titulo do caso
			if ((caseToCreate.caseTitle[0] >= 65 && caseToCreate.caseTitle[0] <= 90) ||		// Verifica de est� dentro do padr�es
				(caseToCreate.caseTitle[0] >= 97 && caseToCreate.caseTitle[0] <= 122)) {	// Padr�es: (Com�ar com Letra)
				flag = 1;	//se estiver modifica a flag do loop e continua o c�digo
			}
			else {
				system("cls"); //sen�o limpa a tela pede denovo o t�tulo
			}
		} while (flag == 0); //Esse loop � para caso o nome do arquivo seja invalido (Ex: 0ARQ, 'po)99,  opQ)

		strcpy(caseToCreate.fileName, caseToCreate.caseTitle);		//adicionar o nome na variavel do nome do arquivo
		strcat(caseToCreate.fileName, caseToCreate.extension);		//adicionar a extens�o no nome do arquivo

		newCase = fopen(caseToCreate.fileName, "r");				//abrir o arquivo em forma de leitura
		flag = 0;
		if (newCase == NULL) {			// Verifica se o arquivo existe
			flag = 1;
			newCase = fopen(caseToCreate.fileName, "w");		//Se n�o existir cria um arquivo
			fprintf(newCase, "%s*\n", caseToCreate.caseTitle);
		}
		else {
			printf("\n Caso existente! Tente outro Nome. Aguarde...");	//sen�o avisa que o arquivo existe e pede outro nome
			Sleep(2000);
			fclose(newCase);
		}
	} while (flag == 0); //Esse loop � para caso o nome do caso ja tenha sido usado!

	printf("\n T�tulo criado com Sucesso! Aguarde...");
	Sleep(1500);

	//------------------------------------------------Criar o Ladr�o---------------------------------------------------//
	ThiefCreation(caseToCreate);						//Fun��o para criar o ladr�o
	printf("\n Ladr�o criado com Sucesso! Aguarde...");
	Sleep(1500);
	system("cls");

	//------------------------------------------------Criar Caminho Percorrido---------------------------------------------------//
	difficulty = ThiefPathCreation(caseToCreate);				//Fun��o para criar o caminho percorrido pelo ladr�o

	//system("cls");
	printf("\n Caso criado com sucesso! Aguarde...");
	Sleep(1500);
	fclose(newCase);

	ModificarArqCasos(caseToCreate.caseTitle, difficulty);
}

void ThiefCreation(typeCase whichCase) {
	int flag = 0, i, modificationFlag = 0;
	char escolha[10];
	do {
		system("cls");
		//printf("Criando o ladr�o\n");
		printf("----------------------------------------------------------------------\n");
		printf("|                        CRIAR CASO - LADR�O                         |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Nome: ");
		getchar();
		scanf("%[^\n]", whichCase.thief.charName);												//Adicionar nome do ladrao
		if ((whichCase.thief.charName[0] >= 65 && whichCase.thief.charName[0] <= 90) ||
			(whichCase.thief.charName[0] >= 97 && whichCase.thief.charName[0] <= 122)) {
			flag = 1;	//Se nome for v�lido sai do loop
		}
	} while (flag == 0);	//Loop de verifica��o do nome

	flag = 0;
	getchar();
	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                        CRIAR CASO - LADR�O                         |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Sexo:\n\n  1- Feminino\n  2- Masculino\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Resposta: ");
		scanf("%c", &whichCase.thief.sexo);
		if (whichCase.thief.sexo == '1' || whichCase.thief.sexo == '2') {
			flag = 1;
			whichCase.thief.sexo -= 48;
		}
	} while (flag == 0);	//Loop de verifica��o do sexo

	flag = 0;
	getchar();
	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                        CRIAR CASO - LADR�O                         |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Hobby:\n\n  1- Futebol\n  2- Samba\n  3- Praia\n  4- Nata��o\n  5- Luta\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Resposta: ");
		scanf("%c", &whichCase.thief.hobby);
		if (whichCase.thief.hobby >= '1' && whichCase.thief.hobby <= '5') {
			flag = 1;
			whichCase.thief.hobby -= 48;
		}
	} while (flag == 0);	//Loop de verifica��o do hobby

	flag = 0;
	getchar();
	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                        CRIAR CASO - LADR�O                         |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Cabelo:\n\n  1- Preto\n  2- Loiro\n  3- Ruivo\n  4- Castanho\n  5- Gris�lho\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Resposta: ");
		scanf("%c", &whichCase.thief.cabelo);
		if (whichCase.thief.cabelo >= '1' && whichCase.thief.cabelo <= '5') {
			flag = 1;
			whichCase.thief.cabelo -= 48;
		}
	} while (flag == 0);	 //Loop de verifica��o do cabelo


	flag = 0;
	getchar();
	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                        CRIAR CASO - LADR�O                         |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Caracteristica:\n\n  1- Anel\n  2- Pulseira\n  3- Colar\n  4- Bon�\n  5- Tatuagem\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Resposta: ");
		scanf("%c", &whichCase.thief.caracteristica);
		if (whichCase.thief.caracteristica >= '1' && whichCase.thief.caracteristica <= '5') {
			flag = 1;
			whichCase.thief.caracteristica -= 48;
		}
	} while (flag == 0);	  //Loop de verifica��o da caracter�stica

	flag = 0;
	getchar();
	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                        CRIAR CASO - LADR�O                         |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Veiculo:\n\n  1- Carro\n  2- Moto\n  3- Helic�ptero\n  4- Bicicleta\n  5- Jatinho\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Resposta: ");
		scanf("%c", &whichCase.thief.veiculo);
		if (whichCase.thief.veiculo >= '1' && whichCase.thief.veiculo <= '5') {
			flag = 1;
			whichCase.thief.veiculo -= 48;
		}
	} while (flag == 0);	  //Loop de verifica��o do ve�culo
	getchar();
	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                        CRIAR CASO - LADR�O                         |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Detalhes do Ladr�o:\n\n");								//Mostrar as escolhas feitas para cada detalhe
		printf(" Nome:               %s\n", whichCase.thief.charName);
		switch (whichCase.thief.sexo) {
			case 1:
				printf(" Sexo:               Feminino\n");
				break;
			case 2:
				printf(" Sexo:               Masculino\n");
				break;
		}
		switch (whichCase.thief.hobby) {
			case 1:
				printf(" Hobby:              Futebol\n");
				break;
			case 2:
				printf(" Hobby:              Samba\n");
				break;
			case 3:
				printf(" Hobby:              Praia\n");
				break;
			case 4:
				printf(" Hobby:              Nata��o\n");
				break;
			case 5:
				printf(" Hobby:              Luta\n");
				break;
		}
		switch (whichCase.thief.cabelo) {
			case 1:
				printf(" Cabelo:             Preto\n");
				break;
			case 2:
				printf(" Cabelo:             Loiro\n");
				break;
			case 3:
				printf(" Cabelo:             Ruivo\n");
				break;
			case 4:
				printf(" Cabelo:             Castanho\n");
				break;
			case 5:
				printf(" Cabelo:             Gris�lho\n");
				break;
		}
		switch (whichCase.thief.caracteristica) {
			case 1:
				printf(" Caracter�stica:     Anel\n");
				break;
			case 2:
				printf(" Caracter�stica:     Pulseira\n");
				break;
			case 3:
				printf(" Caracter�stica:     Colar\n");
				break;
			case 4:
				printf(" Caracter�stica:     Bon�\n");
				break;
			case 5:
				printf(" Caracter�stica:     Tatuagem\n");
				break;
		}
		switch (whichCase.thief.veiculo) {
			case 1:
				printf(" Ve�culo:            Carro\n");
				break;
			case 2:
				printf(" Ve�culo:            Moto\n");
				break;
			case 3:
				printf(" Ve�culo:            Helic�ptero\n");
				break;
			case 4:
				printf(" Ve�culo:            Bicicleta\n");
				break;
			case 5:
				printf(" Ve�culo:            Jatinho\n");
				break;
		}

		flag = 0;
		printf("----------------------------------------------------------------------\n");
		printf(" Gostaria de alterar alguma informa��o? (Sim/N�o)\n"); 	//Modifica��o de algum detalhe
		printf(" Resposta: ");

		scanf("%s", &escolha);
		if (escolha[0] == 'N' || escolha[0] == 'S' || escolha[0] == 'n' || escolha[0] == 's') {
			flag = 1;
		}
	} while (flag == 0);	  //Loop de verifica��o de resposta v�lida

	switch (escolha[0]) {		 //Switch da resposta
	case 's':
	case 'S':	//Caso a resposta seja sim mostrar op��es de mudan�a
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                        CRIAR CASO - LADR�O                         |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Escolha uma informa��o para ser alterada:\n\n");
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

			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			getchar();
			scanf("%c", &escolha[0]);
			if (escolha[0] >= '1' && escolha[0] <= '7') {	//Switch da escolha do que mudar
				switch (escolha[0]) {
				case '1':
					flag = 0;
					do {
						system("cls");
						printf("----------------------------------------------------------------------\n");
						printf("|                        CRIAR CASO - LADR�O                         |\n");
						printf("----------------------------------------------------------------------\n");
						printf(" Modificando o Nome\n\n");
						printf(" Nome: %s\n", whichCase.thief.charName);
						printf(" Novo Nome: ");
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
						printf("----------------------------------------------------------------------\n");
						printf("|                        CRIAR CASO - LADR�O                         |\n");
						printf("----------------------------------------------------------------------\n");
						printf(" Modificando o Sexo\n\n");
						switch (whichCase.thief.sexo) {
						case 1:
							printf(" Sexo: Feminino\n");
							break;
						case 2:
							printf(" Sexo: Masculino\n");
							break;
						}
						printf(" Novo Sexo:\n  1- Feminino\n  2- Masculino\n");
						printf("----------------------------------------------------------------------\n");
						printf(" Resposta: ");
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
						printf("----------------------------------------------------------------------\n");
						printf("|                        CRIAR CASO - LADR�O                         |\n");
						printf("----------------------------------------------------------------------\n");
						printf(" Modificando o Hobby\n\n");
						switch (whichCase.thief.hobby) {
						case 1:
							printf(" Hobby: Futebol\n");
							break;
						case 2:
							printf(" Hobby: Samba\n");
							break;
						case 3:
							printf(" Hobby: Praia\n");
							break;
						case 4:
							printf(" Hobby: Nata��o\n");
							break;
						case 5:
							printf(" Hobby: Luta\n");
							break;
						}
						printf(" Novo Hobby:\n  1- Futebol\n  2- Samba\n  3- Praia\n  4- Nata��o\n  5- Luta\n");
						printf("----------------------------------------------------------------------\n");
						printf(" Resposta: ");
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
						printf("----------------------------------------------------------------------\n");
						printf("|                        CRIAR CASO - LADR�O                         |\n");
						printf("----------------------------------------------------------------------\n");
						printf(" Modificando o Cabelo\n\n");
						switch (whichCase.thief.cabelo) {
						case 1:
							printf(" Cabelo: Preto\n");
							break;
						case 2:
							printf(" Cabelo: Loiro\n");
							break;
						case 3:
							printf(" Cabelo: Ruivo\n");
							break;
						case 4:
							printf(" Cabelo: Castanho\n");
							break;
						case 5:
							printf(" Cabelo: Gris�lho\n");
							break;
						}
						printf("Novo Cabelo:\n  1- Preto\n  2- Loiro\n  3- Ruivo\n  4- Castanho\n  5- Gris�lho\n");
						printf("----------------------------------------------------------------------\n");
						printf(" Resposta: ");
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
						printf("----------------------------------------------------------------------\n");
						printf("|                        CRIAR CASO - LADR�O                         |\n");
						printf("----------------------------------------------------------------------\n");
						printf(" Modificando a Caracter�stica\n\n");
						switch (whichCase.thief.caracteristica) {
						case 1:
							printf(" Caracter�stica: Anel\n");
							break;
						case 2:
							printf(" Caracter�stica: Pulseira\n");
							break;
						case 3:
							printf(" Caracter�stica: Colar\n");
							break;
						case 4:
							printf(" Caracter�stica: Bon�\n");
							break;
						case 5:
							printf(" Caracter�stica: Tatuagem\n");
							break;
						}
						printf(" Nova Caracteristica:\n  1- Anel\n  2- Pulseira\n  3- Colar\n  4- Bon�\n  5- Tatuagem\n");
						printf("----------------------------------------------------------------------\n");
						printf(" Resposta: ");
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
						printf("----------------------------------------------------------------------\n");
						printf("|                        CRIAR CASO - LADR�O                         |\n");
						printf("----------------------------------------------------------------------\n");
						printf(" Modificando o Ve�culo\n\n");
						switch (whichCase.thief.veiculo) {
						case 1:
							printf(" Ve�culo: Carro\n");
							break;
						case 2:
							printf(" Ve�culo: Moto\n");
							break;
						case 3:
							printf(" Ve�culo: Helic�ptero\n");
							break;
						case 4:
							printf(" Ve�culo: Bicicleta\n");
							break;
						case 5:
							printf(" Ve�culo: Jatinho\n");
							break;
						}
						printf(" Novo Veiculo:\n  1- Carro\n  2- Moto\n  3- Helic�ptero\n  4- Bicicleta\n  5- Jatinho\n");
						printf("----------------------------------------------------------------------\n");
						printf(" Resposta: ");
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
		} while (modificationFlag == 0);	//Loop enquanto o usu�rio quiser modificar algo
		printf("\n Dados Alterados com Sucesso! Aguarde...");
		Sleep(1500);
	case 'n':
	case 'N':	//caso a resposta seja n�o salvar informa��es no arquivo
		fprintf(newCase, "%s-%i-%i-%i-%i-%i*", whichCase.thief.charName, whichCase.thief.sexo,
			whichCase.thief.hobby, whichCase.thief.cabelo, whichCase.thief.caracteristica, whichCase.thief.veiculo);
		break;
	}

}

int ThiefPathCreation(typeCase whitchCase) {
	int escolhaNum, flag = 0, count = 0, i, dificuldade;
	int maxPlaces = 10, modificationFlag = 0;
	char escolha[5];

	flag = 0;				//Escolher a quantidade de lugares que o lad�o ir� passar
	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                       CRIAR CASO - CAMINHO                         |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Escolha quantos lugares o ladr�o ir� passar (4 - %i)\n", maxPlaces);
		printf("----------------------------------------------------------------------\n");
		printf(" Resposta: ");
		scanf("%i", &whitchCase.howManyPlaces);
		if (whitchCase.howManyPlaces >= 4 && whitchCase.howManyPlaces <= maxPlaces) {
			flag = 1;
		}
	} while (flag == 0);

	if (whitchCase.howManyPlaces >= 4 && whitchCase.howManyPlaces <= 6) {
		dificuldade = 1;
	} else if (whitchCase.howManyPlaces >= 7 && whitchCase.howManyPlaces <= 8) {
		dificuldade = 2;
	} else if (whitchCase.howManyPlaces >= 9 && whitchCase.howManyPlaces <= 10) {
		dificuldade = 3;
	}

	flag = 0;				//Mostrar os poss�veis lugares para iniciar o caso
	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                       CRIAR CASO - CAMINHO                         |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Escolha o local inicial do caso:\n\n");
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
		printf("----------------------------------------------------------------------\n");
		printf(" Resposta: ");
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
				printf("----------------------------------------------------------------------\n");
				printf("|                       CRIAR CASO - CAMINHO                         |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Escolha anterior: Rio Grande do Sul\n");
				printf(" Escolha o %i� lugar:\n\n", count + 1);
				printf("  1- Goi�s\n");
				printf("  2- Mato Grosso do Sul\n");
				printf("  3- Esp�rito Santo\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Resposta: ");
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
					for (i = 0; i < count; i++) {
						if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
							printf("\n Esse lugar j� foi adicionado!");
							Sleep(750);
							i = 500;
						}
					}
					if (i != 501) {
						flag = 1;
						count++;
					}
				}
			} while (flag == 0);
			break;
		case MS:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                       CRIAR CASO - CAMINHO                         |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Escolha anterior: Mato Grosso do Sul\n");
				printf(" Escolha o %i� lugar:\n\n", count + 1);
				printf("  1- Rio Grande do Sul\n");
				printf("  2- Mato Grosso\n");
				printf("  3- Santa Catarina\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Resposta: ");
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
					for (i = 0; i < count; i++) {
						if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
							printf("\n Esse lugar j� foi adicionado!");
							Sleep(750);
							i = 500;
						}
					}
					if (i != 501) {
						flag = 1;
						count++;
					}
				}
			} while (flag == 0);
			break;
		case GO:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                       CRIAR CASO - CAMINHO                         |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Escolha anterior: Goi�s\n");
				printf(" Escolha o %i� lugar:\n\n", count + 1);
				printf("  1- Rio Grande do Sul\n");
				printf("  2- Minas Gerais\n");
				printf("  3- S�o Paulo\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Resposta: ");
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
					for (i = 0; i < count; i++) {
						if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
							printf("\n Esse lugar j� foi adicionado!");
							Sleep(750);
							i = 500;
						}
					}
					if (i != 501) {
						flag = 1;
						count++;
					}
				}
			} while (flag == 0);
			break;
		case ES:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                       CRIAR CASO - CAMINHO                         |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Escolha anterior: Esp�rito Santo\n");
				printf(" Escolha o %i� lugar:\n\n", count + 1);
				printf("  1- Rio Grande do Sul\n");
				printf("  2- Paran�\n");
				printf("  3- Rio de Janeiro\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Resposta: ");
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
					for (i = 0; i < count; i++) {
						if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
							printf("\n Esse lugar j� foi adicionado!");
							Sleep(750);
							i = 500;
						}
					}
					if (i != 501) {
						flag = 1;
						count++;
					}
				}
			} while (flag == 0);
			break;
		case MT:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                       CRIAR CASO - CAMINHO                         |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Escolha anterior: Mato Grosso\n");
				printf(" Escolha o %i� lugar:\n\n", count + 1);
				printf("  1- Mato Grosso do Sul\n");
				printf("  2- S�o Paulo\n");
				printf("  3- Minas Gerais\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Resposta: ");
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
					for (i = 0; i < count; i++) {
						if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
							printf("\n Esse lugar j� foi adicionado!");
							Sleep(750);
							i = 500;
						}
					}
					if (i != 501) {
						flag = 1;
						count++;
					}
				}
			} while (flag == 0);
			break;
		case SC:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                       CRIAR CASO - CAMINHO                         |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Escolha anterior: Santa Catarina\n");
				printf(" Escolha o %i� lugar:\n\n", count + 1);
				printf("  1- Mato Grosso do Sul\n");
				printf("  2- Paran�\n");
				printf("  3- Minas Gerais\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Resposta: ");
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
					for (i = 0; i < count; i++) {
						if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
							printf("\n Esse lugar j� foi adicionado!");
							Sleep(750);
							i = 500;
						}
					}
					if (i != 501) {
						flag = 1;
						count++;
					}
				}
			} while (flag == 0);
			break;
		case MG:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                       CRIAR CASO - CAMINHO                         |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Escolha anterior: Minas Gerais\n");
				printf(" Escolha o %i� lugar:\n\n", count + 1);
				printf("  1- Goi�s\n");
				printf("  2- Mato Grosso\n");
				printf("  3- Santa Catarina\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Resposta: ");
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
					for (i = 0; i < count; i++) {
						if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
							printf("\n Esse lugar j� foi adicionado!");
							Sleep(750);
							i = 500;
						}
					}
					if (i != 501) {
						flag = 1;
						count++;
					}
				}
			} while (flag == 0);
			break;
		case SP:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                       CRIAR CASO - CAMINHO                         |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Escolha anterior: S�o Paulo\n");
				printf(" Escolha o %i� lugar:\n\n", count + 1);
				printf("  1- Goi�s\n");
				printf("  2- Mato Grosso\n");
				printf("  3- Rio de Janeiro\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Resposta: ");
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
					for (i = 0; i < count; i++) {
						if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
							printf("\n Esse lugar j� foi adicionado!");
							Sleep(750);
							i = 500;
						}
					}
					if (i != 501) {
						flag = 1;
						count++;
					}
				}
			} while (flag == 0);
			break;
		case PR:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                       CRIAR CASO - CAMINHO                         |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Escolha anterior: Paran�\n");
				printf(" Escolha o %i� lugar:\n\n", count + 1);
				printf("  1- Esp�rito Santo\n");
				printf("  2- Santa Catarina\n");
				printf("  3- Rio de Janeiro\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Resposta: ");
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
					for (i = 0; i < count; i++) {
						if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
							printf("\n Esse lugar j� foi adicionado!");
							Sleep(750);
							i = 500;
						}
					}
					if (i != 501) {
						flag = 1;
						count++;
					}
				}
			} while (flag == 0);
			break;
		case RJ:
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                       CRIAR CASO - CAMINHO                         |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Escolha anterior: Rio de Janeiro\n");
				printf(" Escolha o %i� lugar:\n\n", count + 1);
				printf("  1- Esp�rito Santo\n");
				printf("  2- S�o Paulo\n");
				printf("  3- Paran�\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Resposta: ");
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
					for (i = 0; i < count; i++) {
						if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
							printf("\n Esse lugar j� foi adicionado!");
							Sleep(750);
							i = 500;
						}
					}
					if (i != 501) {
						flag = 1;
						count++;
					}
				}
			} while (flag == 0);
			break;
		}
	} while (count < whitchCase.howManyPlaces); //Loop das escolhas dos lugares

	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                       CRIAR CASO - CAMINHO                         |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Ordem dos lugares escolhidos:\n\n");
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
			else {
				switch (whitchCase.thiefPath[count]) {
				case RS:
					printf(" %i- Rio Grande do Sul\n", count + 1);
					break;
				case MS:
					printf(" %i- Mato Grosso do Sul\n", count + 1);
					break;
				case GO:
					printf(" %i- Goi�s\n", count + 1);
					break;
				case ES:
					printf(" %i- Esp�rito Santo\n", count + 1);
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
					printf(" %i- S�o Paulo\n", count + 1);
					break;
				case PR:
					printf(" %i- Paran�\n", count + 1);
					break;
				case RJ:
					printf(" %i- Rio de Janeiro\n", count + 1);
					break;
				}
			}
		}
		printf("----------------------------------------------------------------------\n");
		printf(" Gostaria de alterar alguma informa��o? (Sim/N�o)\n");
		printf(" Resposta: ");
		scanf("%s", &escolha);
		if (escolha[0] == 'n' || escolha[0] == 'N' || escolha[0] == 's' || escolha[0] == 'S') {
			switch (escolha[0]) {
			case 's':
			case 'S':
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                       CRIAR CASO - CAMINHO                         |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Escolha a informa��o a ser alterada:\n\n");
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
					else {
						switch (whitchCase.thiefPath[count]) {
						case RS:
							printf(" %i- Rio Grande do Sul\n", count + 1);
							break;
						case MS:
							printf(" %i- Mato Grosso do Sul\n", count + 1);
							break;
						case GO:
							printf(" %i- Goi�s\n", count + 1);
							break;
						case ES:
							printf(" %i- Esp�rito Santo\n", count + 1);
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
							printf(" %i- S�o Paulo\n", count + 1);
							break;
						case PR:
							printf(" %i- Paran�\n", count + 1);
							break;
						case RJ:
							printf(" %i- Rio de Janeiro\n", count + 1);
							break;
						}
					}
				}
				printf("----------------------------------------------------------------------\n");
				printf(" Resposta: ");
				scanf("%i", &escolhaNum);
				if (escolhaNum >= 1 && escolhaNum <= whitchCase.howManyPlaces) {
					for (count = escolhaNum - 1; count < whitchCase.howManyPlaces; count++) {
						system("cls");
						if (count == 0) {
							flag = 0;
							do {
								system("cls");
								printf("----------------------------------------------------------------------\n");
								printf("|                       CRIAR CASO - CAMINHO                         |\n");
								printf("----------------------------------------------------------------------\n");
								printf(" Escolha o local inicial do caso:\n\n");
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
								printf("----------------------------------------------------------------------\n");
								printf(" Resposta: ");
								scanf("%i", &escolhaNum);
								if (escolhaNum >= 1 && escolhaNum <= 10) {
									flag = 1;
									whitchCase.thiefPath[count] = escolhaNum - 1;
								}
							} while (flag == 0);
						}
						else {
							switch (whitchCase.thiefPath[count - 1]) {
							case RS:
								flag = 0;
								do {
									system("cls");
									printf("----------------------------------------------------------------------\n");
									printf("|                       CRIAR CASO - CAMINHO                         |\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Escolha anterior: Rio Grande do Sul\n");
									printf(" Escolha o %i� lugar:\n\n", count + 1);
									printf("  1- Goi�s\n");
									printf("  2- Mato Grosso do Sul\n");
									printf("  3- Esp�rito Santo\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Resposta: ");
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
										for (i = 0; i < count; i++) {
											if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
												printf("\n Esse lugar j� foi adicionado!");
												Sleep(750);
												i = 500;
											}
										}
										if (i != 501) {
											flag = 1;
										}
									}
								} while (flag == 0);
								break;
							case MS:
								flag = 0;
								do {
									system("cls");
									printf("----------------------------------------------------------------------\n");
									printf("|                       CRIAR CASO - CAMINHO                         |\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Escolha anterior: Mato Grosso do Sul\n");
									printf(" Escolha o %i� lugar:\n\n", count + 1);
									printf("  1- Rio Grande do Sul\n");
									printf("  2- Mato Grosso\n");
									printf("  3- Santa Catarina\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Resposta: ");
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
										for (i = 0; i < count; i++) {
											if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
												printf("\n Esse lugar j� foi adicionado!");
												Sleep(750);
												i = 500;
											}
										}
										if (i != 501) {
											flag = 1;
										}
									}
								} while (flag == 0);
								break;
							case GO:
								flag = 0;
								do {
									system("cls");
									printf("----------------------------------------------------------------------\n");
									printf("|                       CRIAR CASO - CAMINHO                         |\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Escolha anterior: Goi�s\n");
									printf(" Escolha o %i� lugar:\n\n", count + 1);
									printf("  1- Rio Grande do Sul\n");
									printf("  2- Minas Gerais\n");
									printf("  3- S�o Paulo\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Resposta: ");
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
										for (i = 0; i < count; i++) {
											if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
												printf("\n Esse lugar j� foi adicionado!");
												Sleep(750);
												i = 500;
											}
										}
										if (i != 501) {
											flag = 1;
										}
									}
								} while (flag == 0);
								break;
							case ES:
								flag = 0;
								do {
									system("cls");
									printf("----------------------------------------------------------------------\n");
									printf("|                       CRIAR CASO - CAMINHO                         |\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Escolha anterior: Esp�rito Santo\n");
									printf(" Escolha o %i� lugar:\n\n", count + 1);
									printf("  1- Rio Grande do Sul\n");
									printf("  2- Paran�\n");
									printf("  3- Rio de Janeiro\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Resposta: ");
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
										for (i = 0; i < count; i++) {
											if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
												printf("\n Esse lugar j� foi adicionado!");
												Sleep(750);
												i = 500;
											}
										}
										if (i != 501) {
											flag = 1;
										}
									}
								} while (flag == 0);
								break;
							case MT:
								flag = 0;
								do {
									system("cls");
									printf("----------------------------------------------------------------------\n");
									printf("|                       CRIAR CASO - CAMINHO                         |\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Escolha anterior: Mato Grosso\n");
									printf(" Escolha o %i� lugar:\n\n", count + 1);
									printf("  1- Mato Grosso do Sul\n");
									printf("  2- S�o Paulo\n");
									printf("  3- Minas Gerais\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Resposta: ");
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
										for (i = 0; i < count; i++) {
											if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
												printf("\n Esse lugar j� foi adicionado!");
												Sleep(750);
												i = 500;
											}
										}
										if (i != 501) {
											flag = 1;
										}
									}
								} while (flag == 0);
								break;
							case SC:
								flag = 0;
								do {
									system("cls");
									printf("----------------------------------------------------------------------\n");
									printf("|                       CRIAR CASO - CAMINHO                         |\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Escolha anterior: Santa Catarina\n");
									printf(" Escolha o %i� lugar:\n", count + 1);
									printf("  1- Mato Grosso do Sul\n");
									printf("  2- Paran�\n");
									printf("  3- Minas Gerais\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Resposta: ");
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
										for (i = 0; i < count; i++) {
											if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
												printf("\n Esse lugar j� foi adicionado!");
												Sleep(750);
												i = 500;
											}
										}
										if (i != 501) {
											flag = 1;
										}
									}
								} while (flag == 0);
								break;
							case MG:
								flag = 0;
								do {
									system("cls");
									printf("----------------------------------------------------------------------\n");
									printf("|                       CRIAR CASO - CAMINHO                         |\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Escolha anterior: Minas Gerais\n");
									printf(" Escolha o %i� lugar:\n\n", count + 1);
									printf("  1- Goi�s\n");
									printf("  2- Mato Grosso\n");
									printf("  3- Santa Catarina\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Resposta: ");
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
										for (i = 0; i < count; i++) {
											if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
												printf("\n Esse lugar j� foi adicionado!");
												Sleep(750);
												i = 500;
											}
										}
										if (i != 501) {
											flag = 1;
										}
									}
								} while (flag == 0);
								break;
							case SP:
								flag = 0;
								do {
									system("cls");
									printf("----------------------------------------------------------------------\n");
									printf("|                       CRIAR CASO - CAMINHO                         |\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Escolha anterior: S�o Paulo\n");
									printf(" Escolha o %i� lugar:\n\n", count + 1);
									printf("  1- Goi�s\n");
									printf("  2- Mato Grosso\n");
									printf("  3- Rio de Janeiro\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Resposta: ");
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
										for (i = 0; i < count; i++) {
											if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
												printf("\n Esse lugar j� foi adicionado!");
												Sleep(750);
												i = 500;
											}
										}
										if (i != 501) {
											flag = 1;
										}
									}
								} while (flag == 0);
								break;
							case PR:
								flag = 0;
								do {
									system("cls");
									printf("----------------------------------------------------------------------\n");
									printf("|                       CRIAR CASO - CAMINHO                         |\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Escolha anterior: Paran�\n");
									printf(" Escolha o %i� lugar:\n\n", count + 1);
									printf("  1- Esp�rito Santo\n");
									printf("  2- Santa Catarina\n");
									printf("  3- Rio de Janeiro\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Resposta: ");
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
										for (i = 0; i < count; i++) {
											if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
												printf("\n Esse lugar j� foi adicionado!");
												Sleep(750);
												i = 500;
											}
										}
										if (i != 501) {
											flag = 1;
										}
									}
								} while (flag == 0);
								break;
							case RJ:
								flag = 0;
								do {
									system("cls");
									printf("----------------------------------------------------------------------\n");
									printf("|                       CRIAR CASO - CAMINHO                         |\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Escolha anterior: Rio de Janeiro\n");
									printf(" Escolha o %i� lugar:\n\n", count + 1);
									printf("  1- Esp�rito Santo\n");
									printf("  2- S�o Paulo\n");
									printf("  3- Paran�\n");
									printf("----------------------------------------------------------------------\n");
									printf(" Resposta: ");
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
										for (i = 0; i < count; i++) {
											if (whitchCase.thiefPath[i] == whitchCase.thiefPath[count]) {
												printf("\n Esse lugar j� foi adicionado!");
												Sleep(750);
												i = 500;
											}
										}
										if (i != 501) {
											flag = 1;
										}
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
	} while (modificationFlag == 0);	  //Loop de modifica��o

	fprintf(newCase, "\n%i*\n", whitchCase.howManyPlaces);				//colocar no arquivo os dados recolhidos
	for (count = 0; count < whitchCase.howManyPlaces; count++) {
		if (count == whitchCase.howManyPlaces - 1) {
			fprintf(newCase, "%i*\n", whitchCase.thiefPath[count]);
		}
		else {
			fprintf(newCase, "%i-", whitchCase.thiefPath[count]);
		}
	}

	printf("\n Caminho criado com sucesso! Aguarde...");
	Sleep(1500);

	modificationFlag = 0;	//Selecionar em que lugar vai estar o esconderijo no ultimo estado selecionado
	do {
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                    CRIAR CASO - ESCONDERIJO                        |\n");
			printf("----------------------------------------------------------------------\n");
			switch (whitchCase.thiefPath[whitchCase.howManyPlaces - 1]) {
			case RS:
				printf(" O �ltimo estado em que o ladr�o vai passar � Rio Grande do Sul.\n");
				break;
			case MS:
				printf(" O �ltimo estado em que o ladr�o vai passar � Mato Grosso do Sul.\n");
				break;
			case GO:
				printf(" O �ltimo estado em que o ladr�o vai passar � Goi�s.\n");
				break;
			case ES:
				printf(" O �ltimo estado em que o ladr�o vai passar � Esp�rito Santo.\n");
				break;
			case MT:
				printf(" O �ltimo estado em que o ladr�o vai passar � Mato Grosso.\n");
				break;
			case SC:
				printf(" O �ltimo estado em que o ladr�o vai passar � Santa Catarina.\n");
				break;
			case MG:
				printf(" O �ltimo estado em que o ladr�o vai passar � Minas Gerais.\n");
				break;
			case SP:
				printf(" O �ltimo estado em que o ladr�o vai passar � S�o Paulo.\n");
				break;
			case PR:
				printf(" O �ltimo estado em que o ladr�o vai passar � Paran�.\n");
				break;
			case RJ:
				printf(" O �ltimo estado em que o ladr�o vai passar � Rio de Janeiro.\n");
				break;
			}
			printf("\n Escolha a localiza��o do esconderijo:\n\n");
			printf("  1- Pra�a\n");
			printf("  2- Hotel\n");
			printf("  3- Banco\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Resposta: ");
			scanf("%i", &escolhaNum);
			if (escolhaNum >= 1 && escolhaNum <= 3) {
				flag = 1;
				whitchCase.hideout = escolhaNum;
			}
		} while (flag == 0);
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                   CRIAR CASO - ESCONDERIJO                         |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Localiza��o do esconderijo: \n\n");
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
			printf("----------------------------------------------------------------------\n");
			printf(" Gostaria de alterar a localiza��o final? (Sim/N�o)\n");
			printf(" Resposta: ");
			scanf("%s", &escolha);
			if (escolha[0] == 'n' || escolha[0] == 'N' || escolha[0] == 's' || escolha[0] == 'S') {
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

	} while (modificationFlag == 0);	  //Loop de modifica��o do lugar selecionado
	fprintf(newCase, "%i*\n", whitchCase.hideout);

	//--------------------------------------------Adicionar Tempo do Jogo no Arquivo-----------------------------------------------//
	if (dificuldade == 1) {
		whitchCase.caseTime = whitchCase.howManyPlaces * 17;
	} else if (dificuldade == 2) {
		whitchCase.caseTime = whitchCase.howManyPlaces * 15;
	}if (dificuldade == 3) {
		whitchCase.caseTime = whitchCase.howManyPlaces * 12;
	}
	
	fprintf(newCase, "%i*\n", whitchCase.caseTime);

	printf("\n Esconderijo criado com sucesso! Aguarde...");
	Sleep(1500);
	system("cls");

	//Ir para Receber a hit�ria do caso e as dicas em cada lugar
	TipsCreation(whitchCase.thiefPath, whitchCase.howManyPlaces, whitchCase);


	return dificuldade;
}

void TipsCreation(char path[], int howManyPlaces, typeCase caseToCreate) {

	int flag = 0, i, j, k, modificationFlag = 0, escolhaNum;
	char escolha[10];

	//------------------------------------------------Receber Hist�ria---------------------------------------------------//
	flag = 0;
	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                      CRIAR CASO - HIST�RIA                         |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Introduza uma hist�ria inicial que ser� apresentada ao jogador:\n (Utilize '|' para pular linha)\n\n  ");
		getchar();
		scanf("%[^\n]", &caseToCreate.history);		//Recebe a hist�ria
		if ((caseToCreate.history[0] >= 65 && caseToCreate.history[0] <= 90) ||			//verifica se come�a com uma letra
			(caseToCreate.history[0] >= 97 && caseToCreate.history[0] <= 122)) {
			flag = 1;			//Se sim continua o c�digo
		}
	} while (flag == 0);		//Loop para receber uma hist�ria inicial
	printf("\n Aguarde...");
	Sleep(1500);

	do {
		do {
			getchar();
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                      CRIAR CASO - HIST�RIA                         |\n");
			printf("----------------------------------------------------------------------\n");
			printf(" Hist�ria Criada:\n\n  ");
			char caracter;
			int i = 0;
			do {
				caracter = caseToCreate.history[i];
				if (caracter != '\0') {
					if (caracter != '|') {
						printf("%c", caracter);
					} else {
						printf("\n");
					}
					i++;
				}
			} while (caracter != '\0');
			printf("\n----------------------------------------------------------------------\n");
			printf(" Gostaria de reescrever? (Sim/N�o)\n");
			printf(" Resposta: ");
			flag = 0;

			scanf("%s", &escolha);	//Recebe resposta
			if (escolha[0] == 'N' || escolha[0] == 'S' || escolha[0] == 'n' || escolha[0] == 's') {
				flag = 1;			//se for s ou n continua
			}
		} while (flag == 0);		//Loop de resposta v�lida

		switch (escolha[0]) {		//Switch da escolha do usuario
		case 's':
		case'S':		//se a escolha foi sim ent�o pede para o usuario introduzir uma hist�ria nova
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                      CRIAR CASO - HIST�RIA                         |\n");
				printf("----------------------------------------------------------------------\n");
				printf(" Introduza uma hist�ria inicial que ser� apresentada ao jogador:\n (Utilize '|' para pular linha)\n\n  ");		//Receber uma historia inicial
				getchar();
				scanf("%[^\n]", &caseToCreate.history); //Recebe a hist�ria
				if ((caseToCreate.history[0] >= 65 && caseToCreate.history[0] <= 90) ||
					(caseToCreate.history[0] >= 97 && caseToCreate.history[0] <= 122)) {
					flag = 1;	//se estiver dentro dos padr�es continua
				}
			} while (flag == 0);		//Loop de verifica��o da hist�ria
			printf("\n Aguarde...");
			Sleep(1500);
			//Depois que sair do switch vai perguntar se quer modificar a hist�ria
			break;
		case 'n':	//se a escolha for n�o ent�o continua o c�digo
		case 'N':
			modificationFlag = 1;
			break;
		}
	} while (modificationFlag == 0);	//Loop de modifica��o da hist�ria criada

	fprintf(newCase, "%s*\n", caseToCreate.history);											//Colocar a hist�ria em um arquivo

	printf("\n Hist�ria criada com Sucesso! Aguarde...");
	Sleep(1500);																		//Esperar resposta do usuario


																						//-----------------------------------------------Receber Dicas ----------------------------------------------------//
	for (i = 0; i < howManyPlaces - 1; i++) {
		for (j = 1; j <= 3; j++) {
			flag = 0;
			do {
				system("cls");
				printf("----------------------------------------------------------------------\n");
				printf("|                        CRIAR CASO - DICAS                          |\n");
				printf("----------------------------------------------------------------------\n");
				switch (caseToCreate.thiefPath[i]) {
				case RS:
					printf(" O %i� local escolhido foi Rio Grande do Sul\n", i + 1);
					printf(" O pr�ximo local ser�: ");
					switch (caseToCreate.thiefPath[i+1]) {
						case RS:
							printf("Rio Grande do Sul\n");
							break;
						case MS:
							printf("Mato Grosso do Sul\n");
							break;
						case GO:
							printf("Goi�s\n");
							break;
						case ES:
							printf("Esp�rito Santo\n");
							break;
						case MT:
							printf("Mato Grosso\n");
							break;
						case SC:
							printf("Santa Catarina\n");
							break;
						case MG:
							printf("Minas Gerais\n");
							break;
						case SP:
							printf("S�o Paulo\n");
							break;
						case PR:
							printf("Paran�\n");
							break;
						case RJ:
							printf("Rio de Janeiro\n");
							break;
					}
					printf("----------------------------------------------------------------------\n\n");
					switch (j) {
					case 1:
						printf(" Insira uma dica para ser descoberta na Pra�a:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 2:
						printf(" Insira uma dica para ser descoberta no Hotel:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 3:
						printf(" Insira uma dica para ser descoberta no Banco:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					}
					break;
				case MS:
					printf(" O %i� local escolhido foi Mato Grosso do Sul\n", i + 1);
					printf(" O pr�ximo local ser�: ");
					switch (caseToCreate.thiefPath[i + 1]) {
						case RS:
							printf("Rio Grande do Sul\n");
							break;
						case MS:
							printf("Mato Grosso do Sul\n");
							break;
						case GO:
							printf("Goi�s\n");
							break;
						case ES:
							printf("Esp�rito Santo\n");
							break;
						case MT:
							printf("Mato Grosso\n");
							break;
						case SC:
							printf("Santa Catarina\n");
							break;
						case MG:
							printf("Minas Gerais\n");
							break;
						case SP:
							printf("S�o Paulo\n");
							break;
						case PR:
							printf("Paran�\n");
							break;
						case RJ:
							printf("Rio de Janeiro\n");
							break;
					}
					printf("----------------------------------------------------------------------\n\n");
					switch (j) {
					case 1:
						printf(" Insira uma dica para ser descoberta na Pra�a:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 2:
						printf(" Insira uma dica para ser descoberta no Hotel:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 3:
						printf(" Insira uma dica para ser descoberta no Banco:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					}
					break;
				case GO:
					printf(" O %i� local escolhido foi Goi�s\n", i + 1);
					printf(" O pr�ximo local ser�: ");
					switch (caseToCreate.thiefPath[i + 1]) {
						case RS:
							printf("Rio Grande do Sul\n");
							break;
						case MS:
							printf("Mato Grosso do Sul\n");
							break;
						case GO:
							printf("Goi�s\n");
							break;
						case ES:
							printf("Esp�rito Santo\n");
							break;
						case MT:
							printf("Mato Grosso\n");
							break;
						case SC:
							printf("Santa Catarina\n");
							break;
						case MG:
							printf("Minas Gerais\n");
							break;
						case SP:
							printf("S�o Paulo\n");
							break;
						case PR:
							printf("Paran�\n");
							break;
						case RJ:
							printf("Rio de Janeiro\n");
							break;
					}
					printf("----------------------------------------------------------------------\n\n");
					switch (j) {
					case 1:
						printf(" Insira uma dica para ser descoberta na Pra�a:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 2:
						printf(" Insira uma dica para ser descoberta no Hotel:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 3:
						printf(" Insira uma dica para ser descoberta no Banco:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					}
					break;
				case ES:
					printf(" O %i� local escolhido foi Esp�rito Santo\n", i + 1);
					printf(" O pr�ximo local ser�: ");
					switch (caseToCreate.thiefPath[i + 1]) {
						case RS:
							printf("Rio Grande do Sul\n");
							break;
						case MS:
							printf("Mato Grosso do Sul\n");
							break;
						case GO:
							printf("Goi�s\n");
							break;
						case ES:
							printf("Esp�rito Santo\n");
							break;
						case MT:
							printf("Mato Grosso\n");
							break;
						case SC:
							printf("Santa Catarina\n");
							break;
						case MG:
							printf("Minas Gerais\n");
							break;
						case SP:
							printf("S�o Paulo\n");
							break;
						case PR:
							printf("Paran�\n");
							break;
						case RJ:
							printf("Rio de Janeiro\n");
							break;
					}
					printf("----------------------------------------------------------------------\n\n");
					switch (j) {
					case 1:
						printf(" Insira uma dica para ser descoberta na Pra�a:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 2:
						printf(" Insira uma dica para ser descoberta no Hotel:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 3:
						printf(" Insira uma dica para ser descoberta no Banco:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					}
					break;
				case MT:
					printf(" O %i� local escolhido foi Mato Grosso\n", i + 1);
					printf(" O pr�ximo local ser�: ");
					switch (caseToCreate.thiefPath[i + 1]) {
						case RS:
							printf("Rio Grande do Sul\n");
							break;
						case MS:
							printf("Mato Grosso do Sul\n");
							break;
						case GO:
							printf("Goi�s\n");
							break;
						case ES:
							printf("Esp�rito Santo\n");
							break;
						case MT:
							printf("Mato Grosso\n");
							break;
						case SC:
							printf("Santa Catarina\n");
							break;
						case MG:
							printf("Minas Gerais\n");
							break;
						case SP:
							printf("S�o Paulo\n");
							break;
						case PR:
							printf("Paran�\n");
							break;
						case RJ:
							printf("Rio de Janeiro\n");
							break;
					}
					printf("----------------------------------------------------------------------\n\n");
					switch (j) {
					case 1:
						printf(" Insira uma dica para ser descoberta na Pra�a:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 2:
						printf(" Insira uma dica para ser descoberta no Hotel:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 3:
						printf(" Insira uma dica para ser descoberta no Banco:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					}
					break;
				case SC:
					printf(" O %i� local escolhido foi Santa Catarina\n", i + 1);
					printf(" O pr�ximo local ser�: ");
					switch (caseToCreate.thiefPath[i + 1]) {
						case RS:
							printf("Rio Grande do Sul\n");
							break;
						case MS:
							printf("Mato Grosso do Sul\n");
							break;
						case GO:
							printf("Goi�s\n");
							break;
						case ES:
							printf("Esp�rito Santo\n");
							break;
						case MT:
							printf("Mato Grosso\n");
							break;
						case SC:
							printf("Santa Catarina\n");
							break;
						case MG:
							printf("Minas Gerais\n");
							break;
						case SP:
							printf("S�o Paulo\n");
							break;
						case PR:
							printf("Paran�\n");
							break;
						case RJ:
							printf("Rio de Janeiro\n");
							break;
					}
					printf("----------------------------------------------------------------------\n\n");
					switch (j) {
					case 1:
						printf(" Insira uma dica para ser descoberta na Pra�a:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 2:
						printf(" Insira uma dica para ser descoberta no Hotel:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 3:
						printf(" Insira uma dica para ser descoberta no Banco:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					}
					break;
				case MG:
					printf(" O %i� local escolhido foi Minas Gerais\n", i + 1);
					printf(" O pr�ximo local ser�: ");
					switch (caseToCreate.thiefPath[i + 1]) {
						case RS:
							printf("Rio Grande do Sul\n");
							break;
						case MS:
							printf("Mato Grosso do Sul\n");
							break;
						case GO:
							printf("Goi�s\n");
							break;
						case ES:
							printf("Esp�rito Santo\n");
							break;
						case MT:
							printf("Mato Grosso\n");
							break;
						case SC:
							printf("Santa Catarina\n");
							break;
						case MG:
							printf("Minas Gerais\n");
							break;
						case SP:
							printf("S�o Paulo\n");
							break;
						case PR:
							printf("Paran�\n");
							break;
						case RJ:
							printf("Rio de Janeiro\n");
							break;
					}
					printf("----------------------------------------------------------------------\n\n");
					switch (j) {
					case 1:
						printf(" Insira uma dica para ser descoberta na Pra�a:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 2:
						printf(" Insira uma dica para ser descoberta no Hotel:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 3:
						printf(" Insira uma dica para ser descoberta no Banco:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					}
					break;
				case SP:
					printf(" O %i� local escolhido foi S�o Paulo\n", i + 1);
					printf(" O pr�ximo local ser�: ");
					switch (caseToCreate.thiefPath[i + 1]) {
						case RS:
							printf("Rio Grande do Sul\n");
							break;
						case MS:
							printf("Mato Grosso do Sul\n");
							break;
						case GO:
							printf("Goi�s\n");
							break;
						case ES:
							printf("Esp�rito Santo\n");
							break;
						case MT:
							printf("Mato Grosso\n");
							break;
						case SC:
							printf("Santa Catarina\n");
							break;
						case MG:
							printf("Minas Gerais\n");
							break;
						case SP:
							printf("S�o Paulo\n");
							break;
						case PR:
							printf("Paran�\n");
							break;
						case RJ:
							printf("Rio de Janeiro\n");
							break;
					}
					printf("----------------------------------------------------------------------\n\n");
					switch (j) {
					case 1:
						printf(" Insira uma dica para ser descoberta na Pra�a:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 2:
						printf(" Insira uma dica para ser descoberta no Hotel:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 3:
						printf(" Insira uma dica para ser descoberta no Banco:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					}
					break;
				case PR:
					printf(" O %i� local escolhido foi Paran�\n", i + 1);
					printf(" O pr�ximo local ser�: ");
					switch (caseToCreate.thiefPath[i + 1]) {
						case RS:
							printf("Rio Grande do Sul\n");
							break;
						case MS:
							printf("Mato Grosso do Sul\n");
							break;
						case GO:
							printf("Goi�s\n");
							break;
						case ES:
							printf("Esp�rito Santo\n");
							break;
						case MT:
							printf("Mato Grosso\n");
							break;
						case SC:
							printf("Santa Catarina\n");
							break;
						case MG:
							printf("Minas Gerais\n");
							break;
						case SP:
							printf("S�o Paulo\n");
							break;
						case PR:
							printf("Paran�\n");
							break;
						case RJ:
							printf("Rio de Janeiro\n");
							break;
					}
					printf("----------------------------------------------------------------------\n\n");
					switch (j) {
					case 1:
						printf(" Insira uma dica para ser descoberta na Pra�a:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 2:
						printf(" Insira uma dica para ser descoberta no Hotel:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 3:
						printf(" Insira uma dica para ser descoberta no Banco:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					}
					break;
				case RJ:
					printf(" O %i� local escolhido foi Rio de Janeiro\n", i + 1);
					printf(" O pr�ximo local ser�: ");
					switch (caseToCreate.thiefPath[i + 1]) {
						case RS:
							printf("Rio Grande do Sul\n");
							break;
						case MS:
							printf("Mato Grosso do Sul\n");
							break;
						case GO:
							printf("Goi�s\n");
							break;
						case ES:
							printf("Esp�rito Santo\n");
							break;
						case MT:
							printf("Mato Grosso\n");
							break;
						case SC:
							printf("Santa Catarina\n");
							break;
						case MG:
							printf("Minas Gerais\n");
							break;
						case SP:
							printf("S�o Paulo\n");
							break;
						case PR:
							printf("Paran�\n");
							break;
						case RJ:
							printf("Rio de Janeiro\n");
							break;
					}
					printf("----------------------------------------------------------------------\n\n");
					switch (j) {
					case 1:
						printf(" Insira uma dica para ser descoberta na Pra�a:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 2:
						printf(" Insira uma dica para ser descoberta no Hotel:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					case 3:
						printf(" Insira uma dica para ser descoberta no Banco:\n (Utilize '|' para pular linha)\n\n  ");
						break;
					}
					break;
				}
				getchar();
				scanf("%[^\n]", &caseToCreate.tips[j - 1][i]);
				if ((caseToCreate.tips[j - 1][i][0] >= 65 && caseToCreate.tips[j - 1][i][0] <= 90) ||	//verifica se come�a com uma letra
					(caseToCreate.tips[j - 1][i][0] >= 97 && caseToCreate.tips[j - 1][i][0] <= 122)) {
					flag = 1;			//Se sim continua o c�digo
				}
			} while (flag == 0);
		}
		flag = 0;
		do {
			system("cls");
			printf("----------------------------------------------------------------------\n");
			printf("|                        CRIAR CASO - DICAS                          |\n");
			printf("----------------------------------------------------------------------\n");
			switch (caseToCreate.thiefPath[i]) {
				case RS:
					printf(" As dicas do Rio Grande do Sul foram:\n\n");
					break;
				case MS:
					printf(" As dicas do Mato Grosso do Sul foram:\n\n");
					break;
				case GO:
					printf(" As dicas de Goi�s foram:\n\n");
					break;
				case ES:
					printf(" As dicas do Esp�rito Santo foram:\n\n");
					break;
				case MT:
					printf(" As dicas do Mato Grosso foram:\n\n");
					break;
				case SC:
					printf(" As dicas de Santa Catarina foram:\n\n");
					break;
				case MG:
					printf(" As dicas de Minas Gerais foram:\n\n");
					break;
				case SP:
					printf(" As dicas de S�o Paulo foram:\n\n");
					break;
				case PR:
					printf(" As dicas do Paran� foram:\n\n");
					break;
				case RJ:
					printf(" As dicas do Rio de Janeiro foram:\n\n");
					break;
			}
			for (j = 1; j <= 3; j++) {
				switch (j) {
					case 1:
						printf(" Pra�a:\n");
						break;
					case 2:
						printf("\n Hotel:\n");
						break;
					case 3:
						printf("\n Banco:\n");
						break;
				}
				char caracter;
				int k = 0;
				printf(" \"");
				do {
					caracter = caseToCreate.tips[j - 1][i][k];
					if (caracter != '\0') {
						if (caracter != '|') {
							printf("%c", caracter);
						} else {
							printf("\n");
						}
						k++;
					}
				} while (caracter != '\0');
				printf("\"\n");
			}
			printf("------------------------------------------------------------\n");
			printf(" Gostaria de reescrever alguma dica? (Sim/N�o)\n");
			printf(" Resposta: ");
			scanf("%s", &escolha);
			if (escolha[0] == 'N' || escolha[0] == 'S' || escolha[0] == 'n' || escolha[0] == 's') {
				flag = 1;			//se for s ou n continua
			}
		} while (flag == 0);
		switch (escolha[0]) {		//Switch da escolha do usuario
		case 's':
		case'S':		//se a escolha foi sim ent�o pede para o usuario introduzir uma dica nova
			modificationFlag = 0;
			do {
				do {
					system("cls");
					printf("----------------------------------------------------------------------\n");
					printf("|                        CRIAR CASO - DICAS                          |\n");
					printf("----------------------------------------------------------------------\n");
					printf(" Escolha a dica que ser� modificada\n");
					for (j = 1; j <= 3; j++) {
						
						switch (j) {
							case 1:
								printf("\n  %i- Pra�a\n", j);
								break;
							case 2:
								printf("\n  %i- Hotel\n", j);
								break;
							case 3:
								printf("\n  %i- Banco\n", j);
								break;
						}
						char caracter;
						int k = 0;
						printf(" \"");
						do {
							caracter = caseToCreate.tips[j - 1][i][k];
							if (caracter != '\0') {
								if (caracter != '|') {
									printf("%c", caracter);
								} else {
									printf("\n");
								}
								k++;
							}
						} while (caracter != '\0');
						printf("\"\n");
					}
					printf("  4- Confirmar modifica��es.\n\n");
					printf("----------------------------------------------------------------------\n");
					printf(" Resposta: ");
					scanf("%i", &escolhaNum);
				} while (escolhaNum < 1 || escolhaNum > 4);
				switch (escolhaNum) {
				case 4:
					modificationFlag = 1;
					break;
				default:
					flag = 0;
					do {
						system("cls");
						printf("----------------------------------------------------------------------\n");
						printf("|                        CRIAR CASO - DICAS                          |\n");
						printf("----------------------------------------------------------------------\n");
						switch (caseToCreate.thiefPath[i]) {
						case RS:
							printf(" O %i� local escolhido foi Rio Grande do Sul\n\n", i + 1);
							switch (escolhaNum) {
							case 1:
								printf(" Insira uma dica para ser descoberta na Pra�a:\n\n  ");
								break;
							case 2:
								printf(" Insira uma dica para ser descoberta no Hotel:\n\n  ");
								break;
							case 3:
								printf(" Insira uma dica para ser descoberta no Banco:\n\n  ");
								break;
							}
							break;
						case MS:
							printf(" O %i� local escolhido foi Mato Grosso do Sul\n\n", i + 1);
							switch (escolhaNum) {
							case 1:
								printf(" Insira uma dica para ser descoberta na Pra�a:\n\n  ");
								break;
							case 2:
								printf(" Insira uma dica para ser descoberta no Hotel:\n\n  ");
								break;
							case 3:
								printf(" Insira uma dica para ser descoberta no Banco:\n\n  ");
								break;
							}
							break;
						case GO:
							printf(" O %i� local escolhido foi Goi�s\n\n", i + 1);
							switch (escolhaNum) {
							case 1:
								printf(" Insira uma dica para ser descoberta na Pra�a:\n\n  ");
								break;
							case 2:
								printf(" Insira uma dica para ser descoberta no Hotel:\n\n  ");
								break;
							case 3:
								printf(" Insira uma dica para ser descoberta no Banco:\n\n  ");
								break;
							}
							break;
						case ES:
							printf(" O %i� local escolhido foi Esp�rito Santo\n\n", i + 1);
							switch (escolhaNum) {
							case 1:
								printf("Insira uma dica para ser descoberta na Pra�a:\n\n  ");
								break;
							case 2:
								printf("Insira uma dica para ser descoberta no Hotel:\n\n  ");
								break;
							case 3:
								printf("Insira uma dica para ser descoberta no Banco:\n\n  ");
								break;
							}
							break;
						case MT:
							printf(" O %i� local escolhido foi Mato Grosso\n\n", i + 1);
							switch (escolhaNum) {
							case 1:
								printf(" Insira uma dica para ser descoberta na Pra�a:\n\n  ");
								break;
							case 2:
								printf(" Insira uma dica para ser descoberta no Hotel:\n\n  ");
								break;
							case 3:
								printf(" Insira uma dica para ser descoberta no Banco:\n\n  ");
								break;
							}
							break;
						case SC:
							printf(" O %i� local escolhido foi Santa Catarina\n\n", i + 1);
							switch (escolhaNum) {
							case 1:
								printf(" Insira uma dica para ser descoberta na Pra�a:\n\n  ");
								break;
							case 2:
								printf(" Insira uma dica para ser descoberta no Hotel:\n\n  ");
								break;
							case 3:
								printf(" Insira uma dica para ser descoberta no Banco:\n\n  ");
								break;
							}
							break;
						case MG:
							printf(" O %i� local escolhido foi Minas Gerais\n\n", i + 1);
							switch (escolhaNum) {
							case 1:
								printf(" Insira uma dica para ser descoberta na Pra�a:\n\n  ");
								break;
							case 2:
								printf(" Insira uma dica para ser descoberta no Hotel:\n\n  ");
								break;
							case 3:
								printf(" Insira uma dica para ser descoberta no Banco:\n\n  ");
								break;
							}
							break;
						case SP:
							printf(" O %i� local escolhido foi S�o Paulo\n\n", i + 1);
							switch (escolhaNum) {
							case 1:
								printf(" Insira uma dica para ser descoberta na Pra�a:\n\n  ");
								break;
							case 2:
								printf(" Insira uma dica para ser descoberta no Hotel:\n\n  ");
								break;
							case 3:
								printf(" Insira uma dica para ser descoberta no Banco:\n\n  ");
								break;
							}
							break;
						case PR:
							printf(" O %i� local escolhido foi Paran�\n\n", i + 1);
							switch (escolhaNum) {
							case 1:
								printf(" Insira uma dica para ser descoberta na Pra�a:\n\n  ");
								break;
							case 2:
								printf(" Insira uma dica para ser descoberta no Hotel:\n\n  ");
								break;
							case 3:
								printf(" Insira uma dica para ser descoberta no Banco:\n\n  ");
								break;
							}
							break;
						case RJ:
							printf(" O %i� local escolhido foi Rio de Janeiro\n\n", i + 1);
							switch (escolhaNum) {
							case 1:
								printf(" Insira uma dica para ser descoberta na Pra�a:\n\n  ");
								break;
							case 2:
								printf(" Insira uma dica para ser descoberta no Hotel:\n\n  ");
								break;
							case 3:
								printf(" Insira uma dica para ser descoberta no Banco:\n\n  ");
								break;
							}
							break;
						}
						getchar();
						scanf("%[^\n]", &caseToCreate.tips[escolhaNum - 1][i]);
						if ((caseToCreate.tips[escolhaNum - 1][i][0] >= 65 && caseToCreate.tips[escolhaNum - 1][i][0] <= 90) ||	//verifica se come�a com uma letra
							(caseToCreate.tips[escolhaNum - 1][i][0] >= 97 && caseToCreate.tips[escolhaNum - 1][i][0] <= 122)) {
							flag = 1;			//Se sim continua o c�digo
						}
					} while (flag == 0);
					break;
				}
			} while (modificationFlag == 0);
			break;
		case 'n':	//se a escolha for n�o ent�o continua o c�digo
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

void ModificarArqCasos(char caseName[], int difficulty) {
	char arquivoCopy[50][100], character;
	int nCasosCadastrados, i, j;



	if (difficulty == 1) {
		caseFile = fopen("CasosFacil.txt", "r");
	}
	else if (difficulty == 2) {
		caseFile = fopen("CasosMedio.txt", "r");
	}
	else if (difficulty == 3) {
		caseFile = fopen("CasosDificil.txt", "r");
	}

	arquivoCopy[0][0] = fgetc(caseFile);
	nCasosCadastrados = arquivoCopy[0][0] - 48;

	for (i = 1; i <= nCasosCadastrados; i++) {
		j = 0;
		do {
			character = fgetc(caseFile);
			if (character != '\n') {
				arquivoCopy[i][j] = character;
				j++;
			}
		} while (character != '-');
		arquivoCopy[i][j] = '\0';
	}

	strcpy(arquivoCopy[i], caseName);
	strcat(arquivoCopy[i], "-\0");
	arquivoCopy[0][0] += 1;
	fclose(caseFile);

	if (difficulty == 1) {
		caseFile = fopen("CasosFacil.txt", "w");
	}
	else if (difficulty == 2) {
		caseFile = fopen("CasosMedio.txt", "w");
	}
	else if (difficulty == 3) {
		caseFile = fopen("CasosDificil.txt", "w");
	}

	fprintf(caseFile, "%i\n", arquivoCopy[0][0] - 48);
	for (i = 1; i <= nCasosCadastrados + 1; i++) {
		fprintf(caseFile, "%s\n", arquivoCopy[i]);
	}

	fclose(caseFile);
}

