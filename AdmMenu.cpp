#include "Funcoes.h"


void AdmMenu(char nomeADM[], char senhaADM[]) {
	int escolhaNum, returnFlag;

	returnFlag = 0;
	do {
		do {
			system("cls");
			printf("------------------------------------------------------------\n");
			printf("|                  PERFIL DO ADMINISTRADOR                 |\n");
			printf("------------------------------------------------------------\n\n");
			printf("  1- Modificar dados da conta\n");
			printf("  2- Adicionar casos no jogo\n");
			printf("  3- Voltar\n");
			printf("------------------------------------------------------------\n");
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
				//Mais tarde
				returnFlag = 1;
				break;
		}
	} while (returnFlag == 0);
}