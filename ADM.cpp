#include "Funcoes.h"

FILE * AdmConta;

int BemVindo() { //escolha do modo de jogo
	int OpcaoEntrada;
	printf("\t\t\tBEM VINDO!!!\n\n");
	do {
		printf("Escolha uma das opcoes abaixo:\n");
		printf(" 1-Administrador.\n 2-Jogador.\n");
		scanf("%i", &OpcaoEntrada);
		if (OpcaoEntrada != 1 && OpcaoEntrada != 2) {
			system("cls");
			printf("\t\tOPCAO INVALIDA.\n");
		}
	} while (OpcaoEntrada != 1 && OpcaoEntrada != 2);


	return OpcaoEntrada;
}

void AdmCriacao() { //criacao de login e senha
	char login[45];
	char senha[30];

	AdmConta = fopen("conta.txt", "a");
	if (!AdmConta) {
		printf("Erro na abertura do arquivo.\n");
	}
	else {
		printf("\t\t\tCRIACAO DE LOGIN E SENHA\n\n");
		printf("Digite o login.[maximo de 30]\n");
		scanf("%s", &login);

		fprintf(AdmConta, "%s\n", login);
		printf("Digite a senha[maximo de 15].\n");
		scanf("%s", &senha);
		criptografa(senha);

		printf("Sucesso\n");
	}
}
void criptografa(char senha[]) {
	char variavelSenha[30];

	AdmConta = fopen("conta.txt", "a");
	if (!AdmConta) {
		printf("Erro na abertura do arquivo.\n");
	}
	else {
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


		for (int i = 0; i< strlen(senha); i++) {
			// fprintf(AdmConta, "%s", senha[i]);
			variavelSenha[i] = senha[i];
			fputc(variavelSenha[i], AdmConta);
		}


	}


}
int AdmSucesso() {
	char verifLogin[45], loginReal[45];
	char verifSenha[30], senhaReal[30];
	int i, flagWhile = 0;
	system("cls");
	AdmConta = fopen("conta.txt", "r");
	if (!AdmConta) {
		printf("Erro na abertura do arquivo.\n");
	}
	fscanf(AdmConta, "%s", &loginReal);
	fscanf(AdmConta, "%s", &senhaReal);//recebendo dados do arquivo
	do {
		system("cls");
		printf("Foi verificado que ja existe uma conta de ADM criada.\n");
		printf("\t\t Por favor, confirme seus dados.\n");
		printf("Digite o login cadastrado:\n");
		scanf("%s", &verifLogin);
		if (strcmp(verifLogin, loginReal) == 0) {
			printf("Login digitado corretamente.Agora digite sua senha:\n");
			scanf("%s", &verifSenha);
			criptografa(verifSenha);
			flagWhile = 1; //se der certo flag=1 n entra no while
			if (strcmp(verifSenha, senhaReal) == 0) {
				printf("Seja bem vindo %s\n", &loginReal);
			}
		}

	} while (flagWhile == 0);


	return 0;
}
int AdmVerif() {
	FILE *AdmConta;

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
			printf("O arquivo esta vazio. Por favor crie seu nome e senha.\n");
			crieConta = 0;
		}
		else {
			printf("OK.\n");
			crieConta = 1;
		}

	}
	fclose(AdmConta);
	return crieConta;
}