#include "Funcoes.h"

FILE *arquivo, *contaJogador, *nome;	//Variavel para o arquivo do caso novo

int JogadorMenu() {
	int escolhaNum;

	do{
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                             MENU JOGADOR                           |\n");
		printf("----------------------------------------------------------------------\n\n");
		printf("  1- Fazer login\n");
		printf("  2- Fazer cadastro\n");
		printf("  3- Logar como convidado [O progresso não será salvo]\n");
		printf("  4- Voltar\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Resposta: ");
		scanf("%i", &escolhaNum);
		if (escolhaNum < 1 || escolhaNum > 4) {
			printf("\n Opção inválida!");
			Sleep(1500);
		}
	} while (escolhaNum < 1 || escolhaNum > 4);

	return escolhaNum;
}

int FazerLogin(typePlayer player[]) {
	char login[50], senha[50], caracter, loginCompara[50], senhaCompara[50], lixo, TentarNovamente[5];
	int i = 0, j = 0;
	int LoginSucesso = 0;

	do {
		arquivo = fopen("Contas_jogador.txt", "r");

		LoginSucesso = 0;

		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                             FAZER LOGIN                            |\n");
		printf("----------------------------------------------------------------------\n");

		printf(" Login: ");
		scanf("%s", &login);

		printf(" Senha: ");
		scanf("%s", &senha);

		while (!feof(arquivo) && LoginSucesso == 0)
		{
			i = 0;
			do {
				caracter = fgetc(arquivo);
				if (caracter != '\n') {
					loginCompara[i] = caracter;
					i++;
				}
			} while (caracter != '-' && !feof(arquivo));

			loginCompara[i - 1] = '\0';

			if (strcmp(login, loginCompara) == 0) {
				strcpy(player[0].name, login);
				strcat(login, ".txt");
				contaJogador = fopen(login, "r");
				j = 0;
				do {
					caracter = fgetc(contaJogador);
					senhaCompara[j] = caracter;
					j++;
				} while (caracter != '-');
				senhaCompara[j - 1] = '\0';

				if (strcmp(senha, senhaCompara) == 0) {
					LoginSucesso = 1;
				}
				fclose(contaJogador);
			}

			lixo = fgetc(arquivo);

		}
		if (LoginSucesso == 1) {
			printf("\n Seja bem-vindo(a) %s :]\n", player[0].name);
			Sleep(1500);
			fclose(arquivo);

			return 1;

		} else {
			printf("\n Login e/ou senha inválido(s)!");
			Sleep(1500);
			printf("\n\nDeseja tentar novamente? (Sim/Não)\n");
			printf("Resposta: ");

			getchar();
			scanf("%s", &TentarNovamente);
			fclose(arquivo);

			if (TentarNovamente[0] == 'n' || TentarNovamente[0] == 'N') {
				return 0;
			}

		}
	} while (true);
}

int Verifica_Login_Disponivel(char login[]) {
	char caracter, loginCompara[50], lixo;
	int i = 0, j = 0;

	contaJogador = fopen("Contas_jogador.txt", "r");

	while (!feof(contaJogador))//while (fgetc(arquivo) != '*')
	{
		i = 0;
		do {
			caracter = fgetc(contaJogador);
			if (caracter != '\n') {
				loginCompara[i] = caracter;
				i++;
			}

		} while (caracter != '-' && !feof(contaJogador));

		loginCompara[i - 1] = '\0';

		if (strcmp(login, loginCompara) == 0) {
			fclose(contaJogador);
			return 0;
		}
		lixo = fgetc(contaJogador);
	}
	fclose(contaJogador);
	return 1;
} //Função local

void CriarContaJogador(typePlayer player[]) {
	char login[50], senha[50], TentarNovamente[5];
	int i = 0, j = 0;
	int LoginSucesso;

	do {
		LoginSucesso = 0;

		arquivo = fopen("Contas_jogador.txt", "a+");

		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                        CRIAR CONTA JOGADOR                         |\n");
		printf("----------------------------------------------------------------------\n");

		printf(" Login: ");
		scanf("%s", &player[0].name);

		printf(" Senha: ");
		scanf("%s", &senha);

		if ((Verifica_Login_Disponivel(player[0].name)) == 1) {
			fprintf(arquivo, "\n%s-", player[0].name);

			strcpy(login, player[0].name);
			strcat(login, ".txt");
			contaJogador = fopen(login, "w");

			fprintf(contaJogador, "%s-\n\n", senha);

			fprintf(contaJogador, "1\n");
			fprintf(contaJogador, "0\n\n");

			fprintf(contaJogador, "0");

			fclose(contaJogador);
			fclose(arquivo);

			printf("\n Conta criada com sucesso!");
			Sleep(1500);
			break;

		} else {
			printf("\n Login indisponivel!\n");
			Sleep(1500);

			printf("\n Deseja tentar novamente? (Sim/Não)\n");
			printf(" Resposta: ");

			getchar();
			scanf("%s", &TentarNovamente);

			fclose(contaJogador);
			fclose(arquivo);

			if (TentarNovamente[0] == 'n' || TentarNovamente[0] == 'N') {
				break;
			}
		}

	} while (true);
}


int ContaJogadorMenu(typePlayer player[]) {
	int opcao;

	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                            CONTA JOGADOR                           |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Nome : %s\n", player[0].name);
		printf(" Nível: %i\n\n", player[0].level);
		printf("  1- Jogar\n");
		printf("  2- Deslogar\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Resposta: ");
		scanf("%i", &opcao);
	} while (opcao < 1 || opcao > 2);

	if (opcao == 1) {
		printf("\n Carregando");
		Sleep(500);
		printf(".");
		Sleep(750);
		printf(".");
		Sleep(1000);
		printf(".");
		Sleep(750);
		return 1;
	}
	return 0;
}


void Verifica_Conta(typePlayer player[]) {
	char caracter, lixo, NomeConta[50], lixo_vetor[50];
	int i = 0, linha = 1, Flag_checkpoint, menuJogador;

	strcpy(NomeConta, player[0].name);
	strcat(NomeConta, ".txt");

	arquivo = fopen(NomeConta, "r");

	while (!feof(arquivo)) { // Verificando informações da conta

		if (linha == 1) // Senha(lixo)
		{
			fscanf(arquivo, "%s", &lixo_vetor);
		}


		else if (linha == 2) // Nível
		{
			fscanf(arquivo, "%i", &player[0].level);
		}

		else if (linha == 3) // Experiencia
		{
			fscanf(arquivo, "%i", &player[0].exp);
		}

		else if (linha == 6) // Checkpoint
		{
			fscanf(arquivo, "%i", &Flag_checkpoint);
		}

		else // 
		{
			lixo = fgetc(arquivo);
		}

		linha++;
	}

	fclose(arquivo);
}

void EscolherCaso(char NomeCaso[], typePlayer player[]) {
	int i = 0, linha = 1, quantidade_casos, caso_escolhido, NivelJogador;
	char caracter, lixo;
	time_t t;


	NivelJogador = player[0].level;

	srand(time(&t));
	//-------------- inicio ABRINDO ARQUIVO DO NÍVEL CORRESPONDENTE --------------
	if (NivelJogador == 1) {
		arquivo = fopen("CasosFacil.txt", "r");
	} else if (NivelJogador == 2) {
		arquivo = fopen("CasosMedio.txt", "r");
	} else if (NivelJogador == 3) {
		arquivo = fopen("CasosDificil.txt", "r");
	}



	//-------------- inicio ABRINDO ARQUIVO DO NÍVEL CORRESPONDENTE --------------
	if (NivelJogador == 1) {
		arquivo = fopen("CasosFacil.txt", "r");
	} else if (NivelJogador == 2) {
		arquivo = fopen("CasosMedio.txt", "r");
	} else if (NivelJogador == 3) {
		arquivo = fopen("CasosDificil.txt", "r");
	}
	//-------------- fim ABRINDO ARQUIVO DO NÍVEL CORRESPONDENTE --------------

	//-------------- inicio ESCOLHENDO CASO --------------
	linha = 0;
	fscanf(arquivo, "%i", &quantidade_casos);
	caso_escolhido = 1 + (rand() % quantidade_casos);


	do {
		i = 0;
		do {
			caracter = fgetc(arquivo);
			if (caracter != '\n') {
				NomeCaso[i] = caracter;
				i++;
			}
		} while (caracter != '-');
		NomeCaso[i - 1] = '\0';

		lixo = fgetc(arquivo);
		linha++;
	} while (linha != caso_escolhido);

	//-------------- fim ESCOLHENDO CASO --------------

}

int LoginConvidado(typePlayer player[]) {
	FILE *nomeJogadorArq;
	char arqName[60], resp[5];
	int flag = 0;

	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                             MENU JOGADOR                           |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Informe um apelido: ");
		scanf("%s", player[0].name);
		strcpy(arqName, player[0].name);
		strcat(arqName, ".txt");
		nomeJogadorArq = fopen(arqName, "r");
		if (nomeJogadorArq != NULL) {
			fclose(nomeJogadorArq);

			printf("\n Nome existente!");
			Sleep(1500);
			printf("\n\n Gostaria de tentar outro nome? (Sim/Não)\n Resposta: ");
			scanf("%s", &resp);
			if (resp[0] == 'n' || resp[0] == 'N') {
				return 0;
			}
		} else {
			player[0].level = 1;
			player[0].exp = 0;
			return 1;
		}
	} while (true);
}
