#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "Hash.h"

struct grafo{
	int **matriz;
	int qnt;
	Hash* h;
};

Grafo* cria_grafo(int TAM){
	Grafo* gr = (Grafo*) malloc(sizeof(Grafo));
	Hash* h = cria_hash(TAM);
	gr->qnt = TAM;
	int i;
	gr->matriz = (int**) malloc(TAM*sizeof(int*));
	for(i=0;i<TAM;i++){
		gr->matriz[i] = (int*) malloc(TAM * sizeof(int));
	}
	inicializa_grafo(gr);
	gr->h = h;
	return gr;
}

void inicializa_grafo(Grafo* gr){
	if(gr==NULL) return;
	int i,j;
	for(i=0;i<gr->qnt;i++){
		for(j=0;j<gr->qnt;j++){
			gr->matriz[i][j]=0;
		}
	}

}
void libera_grafo(Grafo* gr){
	int x= 0;
	if(gr !=NULL){
		int i,j;
		for(i=0;i<gr->qnt;i++)
			free(gr->matriz[i]);
		libera_hash(gr->h);
		free(gr);
	}
}

int insere_grafo(Grafo* gr, char* origem, char* destino){
	if(gr==NULL) return 0;
	insere_palavra(gr->h,origem);//chama a funcao do arquivo Hash.c
	insere_palavra(gr->h,destino);
	int i = calcula_posicao(origem, getTABLE_SIZE(gr->h));
	int j = calcula_posicao(destino, getTABLE_SIZE(gr->h));
	gr->matriz[i][j]++;
	return 1;
}

int remove_grafo(Grafo* gr, char* origem, char* destino){
	if(gr==NULL) return 0;
	int i = calcula_posicao(origem, getTABLE_SIZE(gr->h));
	int j = calcula_posicao(destino, getTABLE_SIZE(gr->h));
	if(gr->matriz[i][j]){//verifica se existe uma ligacao nesta posicao
		remove_palavra(gr->h,origem);
		remove_palavra(gr->h,destino);
		gr->matriz[i][j]--;
	}
	return 1;
}

int printa_porco(Grafo* gr)
{
	int i, j;
	for(i = 0; i < gr->qnt; i++){
		for(j = 0; j < gr->qnt; j++){
			if(gr->matriz[i][j] != 0){
				printf("A  %s\n", retorna_palavra(gr->h, i));
				printf("B  %s\n", retorna_palavra(gr->h, j));
			}
		}
	}
}
