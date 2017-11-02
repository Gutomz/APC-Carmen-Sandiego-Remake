#include "Funcoes.h"

FILE *newCase, *arquivo, *contaJogador;	//Variavel para o arquivo do caso novo

void FazerLogin()
{
	char login[50], senha[50], caracter, loginCompara[50], senhaCompara[50], lixo;
	int i = 0, j = 0;
	int LoginSucesso = 0;

	arquivo = fopen("Contas_jogador.txt", "r");

	printf("Login: ");
	scanf("%s", &login);

	printf("Senha: ");
	scanf("%s", &senha);

	while (fgetc(arquivo) != '*')
	{
		i = 0;
		do
		{

			caracter = fgetc(arquivo);
			loginCompara[i] = caracter;
			i++;
		} while (caracter != '-');

		loginCompara[i - 1] = '\0';

		if (strcmp(login, loginCompara) == 0)
		{
			strcat(login, ".txt");
			contaJogador = fopen(login, "r");
			j = 0;
			do
			{
				caracter = fgetc(contaJogador);
				senhaCompara[j] = caracter;
				j++;
			} while (caracter != '-');
			senhaCompara[j - 1] = '\0';

			if (strcmp(senha, senhaCompara) == 0)
			{
				LoginSucesso = 1;
			}
		}
	}

	if (LoginSucesso == 1)
	{
		printf("\nLogin relizado com sucesso!!\n");
	}
	else
	{
		printf("\nLogin ou senha invalidos!!\n");
	}
}
