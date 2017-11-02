#include "Funcoes.h"

void main() {
	int OpcaoEntrada, crieConta, resultado;

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
	else { //caso escolha player

		int opcao;

		system("cls");

		printf("MENU JOGADOR\n\n1- Fazer login\n2- Criar uma nova conta\n3- Entrar como convidado\n\n");
		printf("Escolha uma opcao: ");
		scanf("%i", &opcao);

		if (opcao == 1) // Fazer login
		{
			system("cls");
			FazerLogin();
		}

		else if (opcao == 2) // Criar conta
		{

		}
		else if (opcao == 3) // Entrar como Convidado
		{

		}

	}
	system("pause");
}
