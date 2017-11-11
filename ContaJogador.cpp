#include "Funcoes.h"

FILE *arquivo, *contaJogador, *nome;	//Variavel para o arquivo do caso novo

int FazerLogin(char NomeJogador[])
{
	char login[50], senha[50], caracter, loginCompara[50], senhaCompara[50], lixo, TentarNovamente = 'n';
	int i = 0, j = 0;
	int LoginSucesso = 0;

	do {
		arquivo = fopen("Contas_jogador.txt", "r");

		TentarNovamente = 'n';
		LoginSucesso = 0;

		system("cls");
		printf("------------------------------------------------------------\n");
		printf("|                       FAZER LOGIN                        |\n");
		printf("------------------------------------------------------------\n");;

		printf(" Login: ");
		scanf("%s", &login);

		printf(" Senha: ");
		scanf("%s", &senha);

		while (!feof(arquivo) && LoginSucesso == 0)//while (fgetc(arquivo) != '*')
		{
			//if ((!feof(arquivo)) && (LoginSucesso != 1))
			//{
			//lixo = fgetc(arquivo);
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
				strcpy(NomeJogador, login);
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
			//}
			lixo = fgetc(arquivo);
			/*if (feof(arquivo)) {
				break;
			}*/
		}
		if (LoginSucesso == 1) {
			printf("\n Seja bem-vindo(a) %s :]\n", NomeJogador);
			Sleep(1500);
			fclose(arquivo);

			return 1;

		} else {
			printf("\n Login e/ou senha inválido(s)!");
			Sleep(1500);
			printf("\n\nDeseja tentar novamente? (Sim/Não)\n");
			printf("Resposta: ");

			getchar();
			scanf("%c", &TentarNovamente);
			fclose(arquivo);

			if (TentarNovamente == 'n' || TentarNovamente == 'N') 
			{
				return 0;
			}

		}
	} while (TentarNovamente == 's' || TentarNovamente == 'S');



}

int Verifica_Login_Disponivel(char login[])
{
	char caracter, loginCompara[50], lixo;
	int i = 0, j = 0;

	contaJogador = fopen("Contas_jogador.txt", "r");

	while (!feof(contaJogador)//while (fgetc(arquivo) != '*')
	{
			i = 0;
			do
			{
					caracter = fgetc(contaJogador);
					if (caracter != '\n') {
						loginCompara[i] = caracter;
						i++;
					}
				
			} while (caracter != '-' && !feof(contaJogador));

			loginCompara[i - 1] = '\0';

			if (strcmp(login, loginCompara) == 0)
			{
				fclose(contaJogador);
				return 0;
			}
		lixo = fgetc(contaJogador);
	}
	fclose(contaJogador);
	return 1;
} //Função local

int CriarContaJogador(char NomeJogador[])
{
	char login[50], senha[50], TentarNovamente;
	int i = 0, j = 0;
	int LoginSucesso = 0;

	do 
	{

		TentarNovamente = 'n';
		LoginSucesso = 0;

		arquivo = fopen("Contas_jogador.txt", "a+");

		system("cls");
		printf("------------------------------------------------------------\n");
		printf("|                   CRIAR CONTA JOGADOR                     |\n");
		printf("------------------------------------------------------------\n");;

		printf(" Login: ");
		scanf("%s", &login);

		printf(" Senha: ");
		scanf("%s", &senha);

		if ((Verifica_Login_Disponivel(login)) == 1) {
			fprintf(arquivo, "\n%s-", login);

			strcpy(NomeJogador, login);
			strcat(login, ".txt");
			contaJogador = fopen(login, "w");

			fprintf(contaJogador, "%s-\n\n", senha);

			fprintf(contaJogador, "1\n");
			fprintf(contaJogador, "0\n\n");

			fprintf(contaJogador, "0");

			fclose(contaJogador);
			fclose(arquivo);

			return 1;

		} 
		else 
		{
			printf("\n Login indisponivel!\n");
			Sleep(1500);

			printf("\n Deseja tentar novamente? (Sim/Não)\n");
			printf(" Resposta: ");

			getchar();
			scanf("%c", &TentarNovamente);

			fclose(contaJogador);
			fclose(arquivo);

			if (TentarNovamente == 'n' || TentarNovamente == 'N') 
			{
				return 0;
			}
		}

	} while (TentarNovamente == 's' || TentarNovamente == 'S');
	
	system("pause");
}

void Verifica_Conta(char NomeJogador[], char NomeCaso[]) {
	char caracter, lixo, NomeConta[50], lixo_vetor[50];
	int i = 0, linha = 1, NivelJogador, teste, Experiencia, Flag_checkpoint, quantidade_casos, caso_escolhido;
	time_t t;

	srand(time(&t));
	strcpy(NomeConta, NomeJogador);
	strcat(NomeConta, ".txt");

	arquivo = fopen(NomeConta, "r");

	while (!feof(arquivo)) { // Verificando informações da conta

		if (linha == 1) // Senha(lixo)
		{
			fscanf(arquivo, "%s", &lixo_vetor);
		}


		else if (linha == 2) // Nível
		{
			fscanf(arquivo, "%i", &NivelJogador);
		}

		else if (linha == 3) // Experiencia
		{
			fscanf(arquivo, "%i", &Experiencia);
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
	
	printf("\n- Voce esta atualmente no nivel %i\n",NivelJogador);
	fclose(arquivo);

	//-------------- inicio ABRINDO ARQUIVO DO NÍVEL CORRESPONDENTE --------------
	if (NivelJogador == 1) 
	{
		arquivo = fopen("CasosFacil.txt", "r");
	}
	else if (NivelJogador == 2) {
		arquivo = fopen("CasosMedio.txt", "r");
	}
	else if (NivelJogador == 3) {
		arquivo = fopen("CasosDificil.txt", "r");
	}
	//-------------- fim ABRINDO ARQUIVO DO NÍVEL CORRESPONDENTE --------------

	//-------------- inicio ESCOLHENDO CASO --------------
	linha = 0;
	fscanf(arquivo, "%i", &quantidade_casos);
	caso_escolhido = 1 + (rand() % quantidade_casos);

	do{
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

	printf("\n\nNOME DO CASO ESCOLHIDO: %s\n", NomeCaso);
	system("pause");

	//-------------- fim ESCOLHENDO CASO --------------
}
