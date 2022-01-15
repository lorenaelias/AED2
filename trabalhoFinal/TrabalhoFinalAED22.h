/* Bibliotecas e protótipos das funções utilizadas */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>


typedef struct no No;
typedef struct grafo Grafo;

Grafo *cria_grafo(int vert);
void mostra_grafo(Grafo *G,char palavras[5000][50]);
void libera_grafo(Grafo **G);
int insere_arestaN(Grafo *G,char *p1,char *p2,char palavras[5000][50],int tam);
void preencheGrafo(Grafo *G,char lista[5000][50],char palavras[5000][50],int tamLista,int tamPalavras);
int busca(char palavras[5000][50],char *pal,int tam);
void gera_frase(Grafo *G,char palavras[5000][50],int tamPalavras);
void mostra_pesos(Grafo *G);
