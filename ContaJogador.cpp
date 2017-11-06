#include "Funcoes.h"

FILE *arquivo, *contaJogador;	//Variavel para o arquivo do caso novo

void FazerLogin()
{
	char login[50], senha[50], caracter, loginCompara[50], senhaCompara[50], NomeJogador[50], lixo;
	int i = 0, j = 0;
	int LoginSucesso = 0;

	arquivo = fopen("Contas_jogador.txt", "r");

	printf("--- LOGIN ---\n\n");

	printf("Login: ");
	scanf("%s", &login);

	printf("Senha: ");
	scanf("%s", &senha);

	while (!feof(arquivo))//while (fgetc(arquivo) != '*')
	{
		if ((!feof(arquivo)) && (LoginSucesso != 1))
		{
			//lixo = fgetc(arquivo);
			i = 0;
			do
			{
				caracter = fgetc(arquivo);
				if (caracter != '\n')
				{
					loginCompara[i] = caracter;
					i++;
				}
			} while (caracter != '-');

			loginCompara[i - 1] = '\0';

			if (strcmp(login, loginCompara) == 0)
			{
				strcpy(NomeJogador, login);
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
				fclose(contaJogador);
			}
		}
		lixo = fgetc(arquivo);
	}

	if (LoginSucesso == 1)
	{
		printf("\nLogin relizado com sucesso!!\n");
		printf("\nSeja bem-vindo(a) %s :]\n", NomeJogador);

	}
	else
	{
		printf("\nLogin ou senha invalidos!!\n");
	}

	fclose(arquivo);
}

int Verifica_Login_Disponivel(char login[])
{
	char caracter, loginCompara[50], lixo;
	int i = 0, j = 0;

	contaJogador = fopen("Contas_jogador.txt", "r");

	while (!feof(contaJogador))//while (fgetc(arquivo) != '*')
	{
		if (!feof(contaJogador))
		{
			i = 0;
			do
			{
				caracter = fgetc(contaJogador);
				if (caracter != '\n')
				{
					loginCompara[i] = caracter;
					i++;
				}
			} while (caracter != '-');

			loginCompara[i - 1] = '\0';

			if (strcmp(login, loginCompara) == 0)
			{
				fclose(contaJogador);
				return 0;
			}
		}
		lixo = fgetc(contaJogador);
	}
	fclose(contaJogador);
	return 1;
} //Função local

void CriarContaJogador()
{
	char login[50], senha[50], NomeJogador[50];
	int i = 0, j = 0;
	int LoginSucesso = 0;

	arquivo = fopen("Contas_jogador.txt", "a+");

	printf("--- CADASTRO ---\n\n");

	printf("Login: ");
	scanf("%s", &login);

	printf("Senha: ");
	scanf("%s", &senha);

	if ((Verifica_Login_Disponivel(login)) == 1)
	{
		fprintf(arquivo, "\n%s-", login);

		strcpy(NomeJogador, login);
		strcat(login, ".txt");
		contaJogador = fopen(login, "w");

		fprintf(contaJogador, "%s-", senha);

		fclose(contaJogador);
		fclose(arquivo);
	}
	else
	{
		printf("\nLogin indisponivel !!\n");
	}
}

void ApresentarCaso()
{
	printf("BEM VINDO AO JOGO.\n");

}