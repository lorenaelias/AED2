#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct aluno{
    int matricula;
    char nome[30];
    int p1,p2,p3;
};
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
//int insere_ArvBin(ArvBin* raiz, struct aluno al);
int remove_ArvBin(ArvBin *raiz, struct aluno *al);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
struct aluno* consulta_ArvBin(ArvBin *raiz, struct aluno *al);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);

