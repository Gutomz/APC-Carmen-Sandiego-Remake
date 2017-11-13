#include "Funcoes.h"

void main() {
	int OpcaoEntrada, crieConta, opcao, returnFlag, FlagLogin;
	char NomeJogador[50], NomeCaso[50];
	char NomeADM[50], SenhaADM[50];

	setlocale(LC_ALL, "Portuguese");

	returnFlag = 0;
	do {
		OpcaoEntrada = BemVindo();

		if (OpcaoEntrada == 1) { //caso escolha adm
			crieConta = AdmVerif();
			if (crieConta == 0) {
				AdmCriacao(NomeADM, SenhaADM); //se n houver nada no arquivo pede pra criar login e senha
			} else if (crieConta == 1) {
				FlagLogin = AdmSucesso(NomeADM, SenhaADM); //se tiver coisa vai comparar se eh igual
			}

			if (FlagLogin == 1) 
			{
				AdmMenu(NomeADM, SenhaADM);
			}
		} else if (OpcaoEntrada == 2) { //caso escolha player

			do {
				
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("|                        MENU JOGADOR                      |\n");
				printf("------------------------------------------------------------\n\n");
				printf("  1- Fazer login\n");
				printf("  2- Fazer cadastro\n");
				printf("  3- Logar como convidado [O progresso não será salvo]\n");
				printf("  4- Voltar\n");
				printf("------------------------------------------------------------\n");
				printf(" Resposta: ");
				scanf("%i", &opcao);
				if (opcao < 1 || opcao > 4) {
					printf("\n Opção inválida!");
					Sleep(1500);
				}
			} while (opcao < 1 || opcao > 4);
		
			if (opcao == 1) // Fazer login
			{
				FlagLogin = FazerLogin(NomeJogador);

				if (FlagLogin == 1) 
				{
					Verifica_Conta(NomeJogador, NomeCaso);
					LeituraJogador(NomeCaso);
				}
			}

			else if (opcao == 2) // Criar conta
			{
				system("cls");
				FlagLogin = CriarContaJogador(NomeJogador);

				if (FlagLogin == 1)
				{
					Verifica_Conta(NomeJogador, NomeCaso);
				}

			} else if (opcao == 3) // Entrar como Convidado
			{
				system("cls");

				printf("--- CONVIDADO ---\n\n");
				printf("Informe um apelido: ");
				scanf("%s", NomeJogador);

				printf("\nSeja bem-vindo(a) %s :]\n", &NomeJogador);

			}
			else if (opcao == 4) {
				
			}


		}
		else {
			returnFlag = 1;
			system("cls");
		}
	} while (returnFlag == 0);
}
