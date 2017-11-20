#include "Funcoes.h"

FILE *arquivoContas;

int Conta_XPtotal(int nivel, int experiencia);

void MostrarRanking()
{
	char caracter, lixo, NomeConta[50], lixo_vetor[50], nomePlayer[50][50], auxNome[50];
	int i = 0, j = 0, linha = 1, NivelJogador, Experiencia, playerAtual=0, experienciaTotal[50], cont = 0, auxExperiencia;

	// ---------------------------- PEGANDO NOME DOS USUÁRIOS ---------------------------------------
	arquivoContas = fopen("Contas_jogador.txt", "r");
	while (!feof(arquivoContas))
	{
		i = 0;
		do 
		{
			caracter = fgetc(arquivoContas);
			if (caracter != '\n') 
			{
				nomePlayer[playerAtual][i] = caracter;
				i++;
			}
		} while (caracter != '-' && !feof(arquivoContas));
		nomePlayer[playerAtual][i - 1] = '\0';
		playerAtual++;
	}
	fclose(arquivoContas);
	i = 0;
	//nomePlayer[playerAtual][i] = 'X';
	// ---------------------------- PEGANDO NOME DOS USUÁRIOS ---------------------------------------

	playerAtual = 0;

	// ---------------------------- PEGANDO XP E CALCULANDO XP TOTAL ---------------------------------------
	while (nomePlayer[playerAtual][i] != '\0')
	{
		strcpy(NomeConta, nomePlayer[playerAtual]);
		strcat(NomeConta, ".txt");

		arquivoContas = fopen(NomeConta, "r");

		while (!feof(arquivoContas)) { // Verificando informações da conta

			if (linha == 1) // Senha(lixo)
			{
				fscanf(arquivoContas, "%s", &lixo_vetor);
			}


			else if (linha == 2) // Nível
			{
				fscanf(arquivoContas, "%i", &NivelJogador);
			}

			else if (linha == 3) // Experiencia
			{
				fscanf(arquivoContas, "%i", &Experiencia);
			}

			else // 
			{
				lixo = fgetc(arquivoContas);
			}

			linha++;
		}
		fclose(arquivoContas);

		experienciaTotal[playerAtual] = Conta_XPtotal(NivelJogador, Experiencia);
		playerAtual++;

		linha = 1;
		cont++;

	}
	// ---------------------------- PEGANDO XP E CALCULANDO XP TOTAL ---------------------------------------

	// ---------------------------- ORDENANDO VETORES ---------------------------------------

	for (i = 0; i < cont - 1; i++)
	{
		for (j = 0; j < cont - i - 1; j++)
		{
			if (experienciaTotal[j] < experienciaTotal[j+1])
			{
				auxExperiencia = experienciaTotal[j];
				experienciaTotal[j] = experienciaTotal[j + 1];
				experienciaTotal[j + 1] = auxExperiencia;

				strcpy(auxNome, nomePlayer[j]);
				strcpy(nomePlayer[j], nomePlayer[j+1]);
				strcpy(nomePlayer[j+1], auxNome);
			}
		}
	}

	// ---------------------------- ORDENANDO VETORES ---------------------------------------

	// ---------------------------- EXIBINDO O RANKING ---------------------------------------

	if (cont > 5) //Exibir no máximo 5 pessoas
	{
		cont = 5;
	}

	system("cls");
	printf("----------------------------------------------------------------------\n");
	printf("|                               RANKING                              |\n");
	printf("----------------------------------------------------------------------\n\n");

	printf("  NOME					");
	printf("EXPERIÊNCIA\n");
	for (i = 0; i < cont; i++)
	{
		printf("  %i. %s				     ", (i+1), nomePlayer[i]);
		printf("%i\n", experienciaTotal[i]);
	}
	
	printf("\n");
	system("pause>nul");
	// ---------------------------- EXIBINDO O RANKING ---------------------------------------
}

int Conta_XPtotal(int nivel, int experiencia)
{
	int xpTotal = 0;

	if (nivel == 3)
	{
		xpTotal += 6;
	}
	else if (nivel == 2)
	{
		xpTotal += 2;
	}
	else if (nivel == 1)
	{
		xpTotal += 0;
	}

	xpTotal += experiencia;
	
	return(xpTotal);

}