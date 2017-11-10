#include "Funcoes.h"

FILE *AdmConta;

int BemVindo() { //escolha do modo de jogo
	int OpcaoEntrada;
	do {
		system("cls");
		printf("------------------------------------------------------------\n");
		printf("|                     ONDE TÁ A CARMINHA?                  |\n");
		printf("------------------------------------------------------------\n");
		printf(" Escolha uma das opções abaixo:\n\n");
		printf("  1- Administrador\n  2- Jogador\n  3- Sair\n");
		printf("------------------------------------------------------------\n");
		printf(" Resposta: ");
		scanf("%i", &OpcaoEntrada);
		if (OpcaoEntrada < 1 || OpcaoEntrada > 3) {
			printf("\n Opção inválida!");
			Sleep(1500);
		}
	} while (OpcaoEntrada < 1 || OpcaoEntrada > 3);


	return OpcaoEntrada;
}

void AdmCriacao(char nomeADM[], char senhaADM[]) { //criacao de login e senha

	AdmConta = fopen("conta.txt", "w");
	if (!AdmConta) {
		printf("Erro na abertura do arquivo.\n");
	}
	else {
		system("cls");
		printf("------------------------------------------------------------\n");
		printf("|                      CRIAR CONTA ADM                     |\n");
		printf("------------------------------------------------------------\n");
		printf(" Login: ");
		scanf("%s", nomeADM);

		fprintf(AdmConta, "%s\n", nomeADM);
		printf(" Senha: ");
		scanf("%s", senhaADM);
		criptografa(senhaADM);

		for (int i = 0; i< strlen(senhaADM); i++) {
			fputc(senhaADM[i], AdmConta);
		}

		printf("\nConta criada com sucesso!");
		Sleep(1500);
		fclose(AdmConta);
	}
}

void criptografa(char senha[]) {
	char variavelSenha[30];


		for (int i = 0; i < strlen(senha); i++) {
			if (senha[i] == 'c') {
				senha[i] = 'f';
			}
			else  if (senha[i] == 'b') {
				senha[i] = 'e';
			}
			else if (senha[i] == 'x') {
				senha[i] = 'a';
			}
			else {
				senha[i] = senha[i] + 3;
			}

	}


}
int AdmSucesso(char nomeADM[], char senhaADM[]) {
	char loginReal[45], TentarNovamente;
	char senhaReal[30];
	int i, flagWhile = 0;

	AdmConta = fopen("conta.txt", "r");
	if (!AdmConta) {
		printf("Erro na abertura do arquivo.\n");
	}
	fscanf(AdmConta, "%s", &loginReal);
	fscanf(AdmConta, "%s", &senhaReal);//recebendo dados do arquivo
	do {
		system("cls");
		printf("------------------------------------------------------------\n");
		printf("|                         LOGIN ADM                        |\n");
		printf("------------------------------------------------------------\n");
		printf(" Login: ");
		scanf("%s", nomeADM);
		printf(" Senha: ");
		scanf("%s", senhaADM);
		criptografa(senhaADM);

		if (strcmp(senhaADM, senhaReal) == 0) {
			flagWhile = 1; //se der certo flag=1 n entra no while
			printf("\n Seja bem vindo %s! :]", &loginReal);
			Sleep(1500);

			fclose(AdmConta);
			return 1;

		} else {
			printf("\n Login e/ou senha inválido(s)!");
			Sleep(1500);

			printf("\n\n Deseja tentar novamente? (Sim/Não)\n");
			printf(" Resposta: ");

			getchar();
			scanf("%c", &TentarNovamente);
			fclose(AdmConta);

			if (TentarNovamente == 'n' || TentarNovamente == 'N') {
				return 0;
			}
		}

	} while (flagWhile == 0);

}
int AdmVerif() {

	int  tam;
	int crieConta;
	AdmConta = fopen("conta.txt", "r");
	if (!AdmConta) {
		printf("Erro na abertura do arquivo.\n");
	}
	else {
		fseek(AdmConta, 0, SEEK_END); //verificacao se o arquivo esta vazio
		tam = ftell(AdmConta);
		if (tam == 0 || tam < 0) {
			crieConta = 0;
		}
		else {
			crieConta = 1;
		}

	}
	fclose(AdmConta);
	return crieConta;
}