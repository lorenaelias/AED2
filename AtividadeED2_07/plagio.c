#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 40

typedef struct grafo* Grafo;

struct grafo {
    int n; //numero de vertices
    int **mat;
};

void criaGrafo(Grafo g, char *p)  {
  int i;

  g->mat = calloc (n, sizeof(int*));
  g->mat[0] = NULL;
  for (i = 1; i < n; i++)
    g->mat = calloc (i, sizeof(int));
  g->n = n;
}

void destroi(Grafo g) {
  int i;
  for (i = 1; i < g->n; i++)
    free(g->mat[i]);
  free(g->mat);
}

void adicionaAresta(Grafo g, int v1, int v2) {
  if (v1 > v2)
    g->mat[v1][v2] = 1;
  else
    g->mat[v2][v1] = 1;
}

int existeAresta(Grafo g, int v1, int v2) {
  return v1 > v2 ? g->mat[v1][v2] : g->mat[v2][v1];
}

void removeAresta(Grafo g, int v1, int v2) {
  if (v1 > v2)
    g->mat[v1][v2] = 0;
  else
    g->mat[v2][v1] = 0;
}

int main(){
    FILE *f = fopen("fonte1.txt","r");

    if(f == NULL){
        printf("erro ao abrir\n");
        return 0;
    }

    char palavra[max];
    char c;
    int count = 0, flag = 0;
    int index = 0;
    char *p;
    char palavras[40][20];

    while(1){
        if(fgets(palavra,30,f) == NULL)
            break;

        int n = strlen(palavra);
        if(palavra[n-1] =='\n')
            palavra[n-1] ='\0';

        p=strtok(palavra," ");

        while( p != NULL){
            int flag = 0;
            for(int i = 0; i < index; i++)
                if(strcmp(p,palavras[i])==0)flag=1;

            if(flag==0){
                strcpy(palavras[index],p);
                index++;
            }
            p=strtok(NULL," ");
        }
    }
    fclose(f);

    for(int i = 0; i < index; i++){
        printf("%s\n",palavras[i]);
    }

    return 0;
}
