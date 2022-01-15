#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main(){
    ArvBin* arvore = cria_ArvBin();
    insere_ArvBin(arvore,10);
    insere_ArvBin(arvore,5);
    insere_ArvBin(arvore,10);
    insere_ArvBin(arvore,2);
    insere_ArvBin(arvore,8);

    printf("existe impar? 1 sim - 0 nao [%d]\n",buscaImpar(arvore));

    printf("maior no = %d\n",maior_ArvBin(arvore));

    int nfol = totalnaofolhas_ArvBin(arvore);
    int fol = totalfolhas_ArvBin(arvore);
    printf("\nn nao folhas = %d, n folhas = %d\n",nfol,fol);

    int i = totalNO_ArvBin(arvore);
    printf("\ntotal de nos = [%d]\n",i);

//    removePar(arvore);

//    printf("\ntotal de nos = [%d]\n",totalNO_ArvBin(arvore));

    //printf("%d\n",eh_ABB(arvore));

    ArvBin* nova = cria_ArvBin();
    insere_ArvBin(nova,33);
    insere_ArvBin(nova,15);
    insere_ArvBin(nova,41);
    insere_ArvBin(nova,38);
    insere_ArvBin(nova,34);
    insere_ArvBin(nova,47);
    insere_ArvBin(nova,43);
    insere_ArvBin(nova,49);
    printf("\n");
    preOrdem_ArvBin(nova);
    printf("\n");
    emOrdem_ArvBin(nova);
    printf("\n");
    posOrdem_ArvBin(nova);
    printf("\n");

    return 0;
}
