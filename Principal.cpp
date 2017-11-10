#include "Funcoes.h"

void main() {
	int OpcaoEntrada, crieConta, opcao;
	char NomeJogador[50], NomeCaso[50];

	OpcaoEntrada = BemVindo();

	if (OpcaoEntrada == 1) { //caso escolha adm
		crieConta = AdmVerif();
		if (crieConta == 0) {
			AdmCriacao(); //se n houver nada no arquivo pede pra criar login e senha
		}
		else if (crieConta == 1) {
			AdmSucesso(); //se tiver coisa vai comparar se eh igual
		}
	}
	else 
	{ //caso escolha player

			system("cls");

			printf("MENU JOGADOR\n\n1- Fazer login\n2- Criar uma nova conta\n3- Entrar como convidado\n\n");
			printf("Escolha uma opcao: ");
			scanf("%i", &opcao);

			if (opcao == 1) // Fazer login
			{
				FazerLogin(NomeJogador);
				
				Verifica_Conta(NomeJogador,NomeCaso);

			}

			else if (opcao == 2) // Criar conta
			{
				system("cls");
				CriarContaJogador();
			}
			else if (opcao == 3) // Entrar como Convidado
			{
				system("cls");

				printf("--- CONVIDADO ---\n\n");
				printf("Informe um apelido: ");
				scanf("%s", NomeJogador);

				printf("\nSeja bem-vindo(a) %s :]\n", &NomeJogador);

			}
		

	}
	system("pause");
}
