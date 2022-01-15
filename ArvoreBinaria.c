#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* criaArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

//! percorre e libera os nos
void liberaNO(struct NO* no){
    if(no == NULL)
        return;
    liberaNO(no->esq); //! libera todos os nos da esquerda
    liberaNO(no->dir); //! libera todos os nos da direita
    free(no);
    no = NULL;
}

//! trata a raiz
void liberaArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    liberaNO(*raiz); //! libera cada no
    free(raiz); //! libera a raiz
}

//! numero total de niveis em uma arvore
int alturaArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int alt_esq = alturaArvBin(&((*raiz)->esq));
    int alt_dir = alturaArvBin(&((*raiz)->dir));
    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

//! quantidade de elementos na arvore
int totalNO_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

//! visita a raiz, o filho da esquerda e o filho da direita
void preOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

//! visita o filho da esquerda, a raiz e o filho da direita
void emOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

//! visita o filho da esquerda, o filho da direita e a raiz
void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}

int insereArvBin(ArvBin* raiz,int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc (sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){  // navega nos nós da arvora ate chegar em um nó folha
            ant = atual;
            if(valor == atual->info){  // elem ja existe
                free(novo);
                return 0;
            }
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor >  ant->info)  // insere como filho desse n[o folha
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

int consultaArvBin(ArvBin *raiz,int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info)
            return 1;
        if(valor > atual ->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int removeArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){           //! Achou o nó a ser removido. Tratar o tipo de remoção
            if(atual == *raiz)
                *raiz = removeAtual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = removeAtual(atual);
                else
                    ant->esq = removeAtual(atual);
            }
            return 1;
        }
        ant = atual;                //!Continua andando na árvore a procura do nó a ser removido
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

struct NO* removeAtual(struct NO* atual){
    struct NO *no1, *no2;
    if(atual->esq == NULL){  //! nao tem filho na esquerda
        no2 = atual->dir;    //! apontar para o filho da direita
        free(atual);         //! trata no folha e no com 1 filho
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){ //! procura filho mais a direita na sub arvore da esquerda
        no1 = no2;
        no2 = no2->dir;
    }

    if(no1 != atual){        //! copia filho mais a direita na sub-arvore da esquerda para o lugar do nó removido
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
};
