#include "hash.h"
#include "hash.c"

int main(){
    Hash* ha = criaHash(1472);

    int x = insereHash_SemColisao(ha,al);

    int y = buscaHash_SemColisao(ha,mat,&al);

    return 0;
}
