#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
#define PULA printf("\n")

int main(){
    Grafo g;
    cria_grafo(&g, 6);
    adiciona_aresta(&g,0,1);


    return 0;
}
