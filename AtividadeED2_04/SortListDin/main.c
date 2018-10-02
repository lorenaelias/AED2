#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

void selectionSort_MD(Lista *li)
{
    struct aluno temp;
    Elem *menor, *no;
    Elem *atual = *li;

    while(atual->prox != NULL)
    {
        menor = atual;
        no = menor->prox;

        while(no != NULL){
            if(no->dados.matricula < menor->dados.matricula)
                menor = no;
            no = no->prox;
        }
        if(atual != menor){
            temp = atual->dados;
            atual->dados = menor->dados;
            menor->dados = temp;
        }
        atual = atual->prox;
    }
}

void selectionSort_MP(Lista *li)
{
    Elem *no, *ant_no, *menor, *ant_menor, *temp;
    Elem *atual = *li;
    Elem *ant_atual = NULL;

    while(atual->prox != NULL)
    {
        menor = atual;
        ant_menor = ant_atual;

        ant_no = menor;
        no = menor->prox;

        while(no != NULL)
        {
            if(no->dados.matricula < menor->dados.matricula){
                menor = no;
                ant_menor = ant_no;
            }
            ant_no = no;
            no = no->prox;
        }
        if(atual != menor)
        {
            if(ant_atual == NULL)
                *li = menor;
            else
                ant_atual->prox = menor;

            ant_menor->prox = atual;
            temp = menor->prox;
            menor->prox = atual->prox;
            atual->prox = temp;

            atual = menor;
        }
        ant_atual = atual;
        atual = atual->prox;
    }
}

int main(){
    struct aluno a[4] = {{2,"Andre",9,7,8},
                         {4,"Ricardo",7,8,6},
                         {1,"Bianca",9,6,8},
                         {3,"Ana",5,6,7}};
    Lista* li = cria_lista();

    int i;
    for(i=0; i < 4; i++)
        insere_lista_inicio(li,a[i]);

    imprime_lista(li);

    selectionSort_MP(li);

    imprime_lista(li);

    libera_lista(li);
    system("pause");
    return 0;
}
