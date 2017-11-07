#include "Funcoes.h"

void LeituraJogador() {
	FILE * arquivo;
	typeCase dadosCaso;
	char nomeMocinho;
	char nome;
	int auxiliar=0, flagGuto = 0;
	arquivo = fopen("caso1.txt", "r");
	if (!arquivo) {
		printf("Erro na abertura do arquivo.\n");
	}
	printf("Ola, o nome do seu caso eh:  ");
	do {
		nome = fgetc(arquivo);
		if (nome != '*') {
			dadosCaso.caseTitle[auxiliar] = nome;
			auxiliar++;
		}
		else {
			flagGuto = 1;
		}


	}
	while (flagGuto==0);
	printf("%s\n", dadosCaso.caseTitle);

	fclose(arquivo);

}
