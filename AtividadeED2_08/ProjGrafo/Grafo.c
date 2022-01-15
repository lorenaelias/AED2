#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h" //inclui os Protótipos

//Definição do tipo Grafo
struct grafo{
    int eh_ponderado;   //! se existe peso -> == 1
    int nro_vertices;   //!
    int grau_max;       //! tamanho
    int** arestas;      //! guarda as arestas
    float** pesos;      //! guarda os pesos
    int* grau;          //! guarda o grau de cada vertice
};


/*!
    A criacao de um grafo é na verdade a criacao dos vertices dispersos
    dentro disso tem-se a alocacao de todos os vetores e matriz que serao utilizados na elaboracao de uma estrutura grafo
*/
Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo)); //! aloca uma estrutura grafo
    if(gr != NULL){ //!se nao houver problema com a alocacao, faz o resto
        int i;
        gr->nro_vertices = nro_vertices;    //! copia de dados passados por parametro
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*) calloc(nro_vertices,sizeof(int)); //! aloca o vetor grau para o numero de vertices inseridos

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));  //! aloca a matriz de arestas para o numero de vertices inseridos
        for(i=0; i<nro_vertices; i++)                               //! continua alocacao pq é ponteiro pra ponteiro
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));


        //! se o grafo é ponderado, faz isso
        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*)); //! aloca a matriz de peso
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));//! continua essa alocacao
        }

    }
    return gr; //! retorna o ponteiro para o grafo criado
}

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->arestas[i]);           //! libera arestas
        free(gr->arestas);

        if(gr->eh_ponderado){               //! se for ponderado liberar a matriz de pesos
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)                                  //! testes antes de inserir aresta
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)        //! garantir que o numero inserido nao seja negativo nem maior que o num de vertices
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;


    //! aqui comeca a insercao da aresta
    gr->arestas[orig][gr->grau[orig]] = dest;

    //!so acontece se for ponderado
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;    //! a matriz de pesos recebe o peso recebido por parametro

    gr->grau[orig]++;                              //! incrementa o grau da posicao origem
    //! termina a insercao de uma aresta

    //! se nao for dirigido u esta ligado a v, v esta ligado a u
    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);         //! pra nao entrar em loop infinito atribui 1 ao eh digrafo
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;


    int i = 0;

    while(i<gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;                //! i vai ser a posicao da aresta que desejamos remover
    if(i == gr->grau[orig]) //! elemento nao encontrado
        return 0;

    gr->grau[orig]--;       //! decrementa o grau do vertice de origem
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];

    //! se for ponderado
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];

    //! se nao for dirigido tem que remover tambem a ligacao do segundo vertice com o primeiro
    if(eh_digrafo == 0)
        removeAresta(gr,dest,orig,1);
    return 1;
}

void imprime_Grafo(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;

    for(i=0; i < gr->nro_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->eh_ponderado)
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n");
    }
}

int hamiltoniano(Grafo *gr,int *caminho){
    int i, j;
    int aux;
    int repetidos[gr->nro_vertices];

    for(i=0; i < gr->nro_vertices; i++){
        repetidos[i] = 0;  //! zera vetor de repetidos
    }

    //! testa se passa pelos vertices somente uma vez
    for(i=0; i < gr->nro_vertices; i++){
        repetidos[caminho[i]]++;            //! caminho guarda os vertices que foram visitados
        if(repetidos[caminho[i]] > 1){      //! se houver vertices repetidos, nao eh hamiltoniano
            printf("\nPossui vertices repetidos, nao eh hamiltoniano");
            return 0;
        }
    }

    //! testa se a aresta eh valida
    for(i = 0; i < gr->nro_vertices; i++){
        for(j=0; j < gr->grau[i]+1;j++){
            if(gr->arestas[caminho[i]][j] == caminho[i+1])
                aux = 1;
        }

        if(aux == 0) {
            printf("\nPossui aresta invalida, nao eh hamiltoniano");
            return 0;
        }
    }
    printf("\nEh hamiltoniano\n");
    return 1;
}

int procuraMenorDistancia(float *dist, int *visitado, int NV){
    int i, menor = -1, primeiro = 1;
    for(i=0; i < NV; i++){
        if(dist[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}

void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist){
    int i, cont, NV, ind, *visitado, vert;
    cont = NV = gr->nro_vertices;
    visitado = (int*) malloc(NV * sizeof(int));
    for(i=0; i < NV; i++){
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }
    dist[ini] = 0;
    while(cont > 0){
        vert = procuraMenorDistancia(dist, visitado, NV);
        //printf("u = %d\n",u);
        if(vert == -1)
            break;

        visitado[vert] = 1;
        cont--;
        for(i=0; i<gr->grau[vert]; i++){
            ind = gr->arestas[vert][i];
            if(dist[ind] < 0){
               dist[ind] = dist[vert] + 1;//ou peso da aresta
               ant[ind] = vert;
            }else{
                if(dist[ind] > dist[vert] + 1){
                    dist[ind] = dist[vert] + 1;//ou peso da aresta
                    ant[ind] = vert;
                }
            }
        }
    }

    free(visitado);
}

void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont){
    int i;
    visitado[ini] = cont;
    for(i=0; i<gr->grau[ini]; i++){
        if(!visitado[gr->arestas[ini][i]])
            buscaProfundidade(gr,gr->arestas[ini][i],visitado,cont+1);
    }
}

void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado){
    int i, cont = 1;
    for(i=0; i<gr->nro_vertices; i++)
        visitado[i] = 0;
    buscaProfundidade(gr,ini,visitado,cont);

    for(i=0; i < gr->nro_vertices; i++)
        printf("%d -> %d\n",i,visitado[i]);
}

void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado){
    int i, vert, NV, cont = 1;
    int *fila, IF = 0, FF = 0;

    for(i=0; i<gr->nro_vertices; i++)
        visitado[i] = 0;

    NV = gr->nro_vertices;
    fila = (int*) malloc(NV * sizeof(int));
    FF++;
    fila[FF] = ini;
    visitado[ini] = cont;

    while(IF != FF){
        IF = (IF + 1) % NV;
        vert = fila[IF];
        cont++;

        for(i=0; i<gr->grau[vert]; i++){
            if(!visitado[gr->arestas[vert][i]]){
                FF = (FF + 1) % NV;
                fila[FF] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }

    free(fila);

    for(i=0; i < gr->nro_vertices; i++)
        printf("%d -> %d\n",i,visitado[i]);
}
