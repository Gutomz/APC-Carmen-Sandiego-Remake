#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <locale.h>
#include <time.h>

int BemVindo();
int AdmSucesso();
void AdmCriacao();
int AdmVerif();
void criptografa(char senha[]);

void FazerLogin(char NomeJogador[]);
void CriarContaJogador();
void Verifica_Conta(char NomeJogador[], char NomeCaso[]);