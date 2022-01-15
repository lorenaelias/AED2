#include"TrabalhoFinalAED22.h"

/* Implementa��o de um grafo baseado em lista de adjacencia */
/*Um n� � composto por um inteiro que ir� indicar sua posi��o na lista de palavas �nicas
  uma string que representar� a palavra que estar� fazedo a liga��o e um ponteiro para o
  poss�vel n� seguinte*/
struct no{
    int vertice;
    char palavra[30];
    struct no *prox;
};

/*O grafo � composto por um inteiro representando a quantidade total de n�s,
  um vetor com o grau de liga��o de cada v�rtice
  e o grafo em si */
struct grafo{
    int qtde_vertices;
    int *grau;
    No**aresta;
};

/* Cria um grafo com numero de vertices 'n'                     */
/* e faz a aloca��o de todas as estruturas que serao utilizadas */
Grafo* cria_grafo(int vert){
    Grafo *G;
    int i;
    G=(Grafo*)malloc(sizeof(Grafo));
    if(G==NULL)
    {
        free(G);
        return NULL;
    }

    G->qtde_vertices=vert;
    G->grau=(int*)malloc(vert*sizeof(int));
    for(i=0;i<vert;i++){
        G->grau[i]=0;
    }
    G->aresta=(No**)malloc(vert*sizeof(No*));
    for(i=0; i<G->qtde_vertices; i++)
    {
        G->aresta[i]=NULL;
    }
    if(G->aresta==NULL)
    {
        free(G->aresta);
        free(G->grau);
        free(G);
        return NULL;
    }
    return G;
}

/* Libera todas as estruturas utilizadas para gerar o grafo 'G' */
void libera_grafo(Grafo **G){
    if((*G)!=NULL)
    {
        int i;
        No *aux,*ant;
        for(i=0; i<(*G)->qtde_vertices; i++)
        {
            aux=(*G)->aresta[i];
            ant=NULL;
            while(aux!=NULL)
            {
                ant=aux;
                aux=aux->prox;
                free(ant);
            }
        }
        free((*G)->grau);
        free(*G);
        *G=NULL;
    }
}

/* Mostra os vertices do grafo 'G' e  suas respectivas liga��es */
void mostra_grafo(Grafo *G,char palavras[5000][50]){
    No *aux;
    int i;
    for(i=0; i<G->qtde_vertices; i++)
    {
        aux=G->aresta[i];
        printf("v[%d] - (%s) - Tem conexoes com :\n",i,palavras[i]);
        while(aux!=NULL)
        {
            printf("v[%d] - (%s) | ",aux->vertice,aux->palavra);
            aux=aux->prox;
        }
        printf("\n\n");
    }
}

/* Busca pela palavra  'pal'  no  vetor  de strings  'palavras' */
int busca(char palavras[5000][50],char *pal,int tam){
    int i;
    for(i=0;i<tam;i++){
        if(strcmp(pal,palavras[i])==0)return i;
    }
    return 0;
}

/* Preenche as ligacoes do grafo 'G' */
void preencheGrafo(Grafo *G,char lista[5000][50],char palavras[5000][50],int tamLista,int tamPalavras){
    int i;
    for(i=0;i<tamLista-1;i++){
        insere_arestaN(G,lista[i],lista[i+1],palavras,tamPalavras);
    }
}

/* Insere uma ligacao entre p1 e p2 (aresta) */
int insere_arestaN(Grafo *G,char *p1,char *p2,char palavras[5000][50],int tam){
    if(G==NULL)return -1;
    if(p1[strlen(p1)-1]=='.')return -1;
    int v1 = busca(palavras,p1,tam);
    int v2 = busca(palavras,p2,tam);
    No * aux = G->aresta[v1];
    while(aux!=NULL && aux->vertice != v2){
        aux = aux->prox;
    }
    if(aux!=NULL)
        return 0;
    No *novo=(No*)malloc(sizeof(No));
    if(novo!=NULL)
    {
        strcpy(novo->palavra,p2);
        novo->vertice=v2;
        novo->prox=G->aresta[v1];
        G->aresta[v1]=novo;
    }
    No* aux2 = G->aresta[v1];
    G->grau[v1]++;

    return 1;
}

/* Gera uma frase, caminhando aleatoriamente pelo grafo 'G' */
void gera_frase(Grafo *G,char palavras[5000][50],int tamPalavras){
    int i,posAtual,posSeguinte;
    do{
        posAtual = rand() % (tamPalavras-1);
    }while((palavras[posAtual][0]<'A' || palavras[posAtual][0]>'Z') || palavras[posAtual][strlen(palavras[posAtual])-1]=='.');
    printf("%s ",palavras[posAtual]);
    do{
        if(G->grau[posAtual]==0)break;
        No *aux=G->aresta[posAtual];
        posSeguinte = rand() % (G->grau[posAtual]);
        for(i=0;i<posSeguinte;i++)aux=aux->prox;
        printf("%s ",aux->palavra);
        posAtual = aux->vertice;
        if(palavras[posAtual][strlen(palavras[posAtual])-1]=='.' || palavras[posAtual][strlen(palavras[posAtual])-1]=='?' || palavras[posAtual][strlen(palavras[posAtual])-1]=='!' || G->grau[posAtual]==0)break;
    }while(1);
}

/*fun��o para mostrar o t�tulo do Trabalho desenvolvido*/
void menu(){
    printf("         ***  *****  ****   *****  ****    *****  ****   \n");
    printf("        *     *      *   *  *   *  *   *   *   *  *   *  \n");
    printf("        *  ** *****  ****   *****  *    *  *   *  ****   \n");
    printf("        *   * *      * *    *   *  *   *   *   *  * *    \n");
    printf("         ***  *****  *  *   *   *  ****    *****  *  *   \n\n");
    printf("                           ****    *****                   \n");
    printf("                           *   *   *                       \n");
    printf("                           *    *  *****                   \n");
    printf("                           *   *   *                       \n");
    printf("                           ****    *****                   \n\n");
    printf("   *      *****  ****   *****       *      *****  ****   *****\n");
    printf("   *      *      *   *  *   *       *      *      *   *  *   *\n");
    printf("   *      *****  ****   *   *  ***  *      *****  ****   *   *\n");
    printf("   *      *      * *    *   *       *      *      * *    *   *\n");
    printf("   *****  *****  *  *   *****       *****  *****  *  *   *****\n");
    printf("\n\n");
}
/*mostra o vetor de pesos do Grafo 'G' */
void mostra_pesos(Grafo *G){
    int i;
    for(i=0;i<G->qtde_vertices;i++){
        printf("v[%d] tem grau %d \n",i,G->grau[i]);
    }
}
