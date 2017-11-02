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

	}
	system("pause");
}
