#include "pilhadinenc.h"
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin *raiz, int valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, int valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);


int totalnaofolhas_ArvBin(ArvBin *raiz);
int totalfolhas_ArvBin(ArvBin *raiz);
int maiorValorABB(ArvBin* raiz);
int menorValorABB(ArvBin* raiz);
int buscaImpar(ArvBin *raiz);
int maior_ArvBin(ArvBin *raiz);
void espelhar(ArvBin* ant,ArvBin* nova);
int IsStrictlyBinary(ArvBin* root);
int similar(ArvBin* a, ArvBin* b);
