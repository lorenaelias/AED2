#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main(){
    ArvAVL* arvore = cria_ArvAVL();

    insere_ArvAVL(arvore,8);
    insere_ArvAVL(arvore,5);
    insere_ArvAVL(arvore,10);
    insere_ArvAVL(arvore,3);
    insere_ArvAVL(arvore,6);
    insere_ArvAVL(arvore,9);
    insere_ArvAVL(arvore,12);
    insere_ArvAVL(arvore,2);
    insere_ArvAVL(arvore,4);
    insere_ArvAVL(arvore,7);
    insere_ArvAVL(arvore,11);
    insere_ArvAVL(arvore,1);



    remove_ArvAVL(arvore,8);

    preOrdem_ArvAVL(arvore);

    return 0;
}
