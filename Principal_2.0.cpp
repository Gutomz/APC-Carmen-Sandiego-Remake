#include "Funcoes.h"


HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.



void main() {
	char nomeAdm[50], senhaAdm[50];
	char caseName[50];

	typePlayer player[2];

	int opcaoMenu, opcaoMenuJogador;

	setlocale(LC_ALL, "Portuguese");
	SetVideo();

	do {
		opcaoMenu = BemVindo();
		switch (opcaoMenu) {
			case 1://Administrador
				if (AdmVerif() == 0) {
					AdmCriacao(nomeAdm, senhaAdm);
				}

				if (AdmLogin(nomeAdm, senhaAdm) == 1) {
					while (AdmMenu(nomeAdm, senhaAdm) == 0);
				}
				break;
			case 2://Jogador
				do {
					opcaoMenuJogador = JogadorMenu();
					switch (opcaoMenuJogador) {
						case 2://Fazer cadastro
							CriarContaJogador(player);
								break;

						case 1://Fazer login
							if (FazerLogin(player) == 0) {
								break;
							}

							Verifica_Conta(player);

							while (ContaJogadorMenu(player) == 1) {
								EscolherCaso(caseName, player);
								LerArquivoCaso(caseName, player);
							}
							break;
						case 3://Entrar como convidado
							if (LoginConvidado(player) == 0) {
								break;
							}
							while (ContaJogadorMenu(player) == 1) {
								EscolherCaso(caseName, player);
								LerArquivoCaso(caseName, player);
							}
							break;
					}
				} while (opcaoMenuJogador != 4);
				break;
			case 3://Ranking
				MostrarRanking();
				break;
		}
	} while (opcaoMenu != 4);



}

void SetVideo() {
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleTitle("Onde ta a Carminha?");
	SMALL_RECT windowSize = { 0, 0, 69, 34 };
	SetConsoleWindowInfo(wHnd, 1, &windowSize);
	COORD bufferSize = { 10, 10 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);

}

int BemVindo() { //escolha do modo de jogo
	int OpcaoEntrada;
	do {
		system("cls");
		printf("----------------------------------------------------------------------\n");
		printf("|                          ONDE TÁ A CARMINHA?                       |\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Escolha uma das opções abaixo:\n\n");
		printf("  1- Administrador\n  2- Jogador\n  3- Ranking\n  4- Sair\n");
		printf("----------------------------------------------------------------------\n");
		printf(" Resposta: ");
		scanf("%i", &OpcaoEntrada);
		if (OpcaoEntrada < 1 || OpcaoEntrada > 4) {
			printf("\n Opção inválida!");
			Sleep(1500);
		}
	} while (OpcaoEntrada < 1 || OpcaoEntrada > 4);


	return OpcaoEntrada;
}