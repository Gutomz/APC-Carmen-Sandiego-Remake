#include "Funcoes.h"

FILE *AdmConta;


void AdmCriacao(char nomeADM[], char senhaADM[]) { //criacao de login e senha
	AdmConta = fopen("ContaAdm.txt", "w");

	system("cls");
	printf("----------------------------------------------------------------------\n");
	printf("|                           CRIAR CONTA ADM                          |\n");
	printf("----------------------------------------------------------------------\n");
	printf(" Login: ");
	scanf("%s", nomeADM);

	fprintf(AdmConta, "%s\n", nomeADM);
	printf(" Senha: ");
	scanf("%s", senhaADM);
	criptografa(senhaADM);

	for (int i = 0; i< strlen(senhaADM); i++) {
		fputc(senhaADM[i], AdmConta);
	}

	printf("\nConta criada com sucesso! Aguarde...");
	Sleep(1500);
	fclose(AdmConta);
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

int AdmLogin(char nomeADM[], char senhaADM[]) {
	char loginReal[45], TentarNovamente[5];
	char senhaReal[30];
	int i;

	AdmConta = fopen("ContaAdm.txt", "r");

	fscanf(AdmConta, "%s", &loginReal);
	fscanf(AdmConta, "%s", &senhaReal);//recebendo dados do arquivo

	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                              LOGIN ADM                             |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Login: ");
		scanf("%s", nomeADM);
		printf(" Senha: ");
		scanf("%s", senhaADM);
		criptografa(senhaADM);

		if (strcmp(nomeADM, loginReal) == 0) {
			if (strcmp(senhaADM, senhaReal) == 0) {
				printf("\n Seja bem vindo %s! :]", &loginReal);
				Sleep(1500);

				fclose(AdmConta);
				return 1;

			}
		}

		printf("\n Login e/ou senha inválido(s)!");
		Sleep(1500);

		printf("\n\n Deseja tentar novamente? (Sim/Não)\n");
		printf(" Resposta: ");

		getchar();
		scanf("%s", &TentarNovamente);

		if (TentarNovamente[0] == 'n' || TentarNovamente[0] == 'N') {
			fclose(AdmConta);
			return 0;
		}

	} while (true);

}

int AdmVerif() {
	int  tam;
	int crieConta;
	AdmConta = fopen("ContaAdm.txt", "r");

	fseek(AdmConta, 0, SEEK_END); //verificacao se o arquivo esta vazio
	tam = ftell(AdmConta);
	if (tam == 0 || tam < 0) {
		crieConta = 0;
	}
	else {
		crieConta = 1;
	}

	fclose(AdmConta);
	return crieConta;
}

int AdmMenu(char nomeADM[], char senhaADM[]) {
	int escolhaNum;


	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                       PERFIL DO ADMINISTRADOR                      |\n");
		printf("----------------------------------------------------------------------\n\n");
		printf("  1- Modificar dados da conta\n");
		printf("  2- Adicionar casos no jogo\n");
		printf("  3- Deslogar\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Resposta: ");
		scanf("%i", &escolhaNum);
		if (escolhaNum < 1 || escolhaNum > 3) {
			printf("\n Opção inválida!");
			Sleep(1500);
		}
	} while (escolhaNum < 1 || escolhaNum > 3);

	switch (escolhaNum) {
		case 1:
			//Mais tarde
			break;
		case 2:
			CaseCreation();
			break;
		case 3:
			return 1;
			break;
	}
	return 0;
}