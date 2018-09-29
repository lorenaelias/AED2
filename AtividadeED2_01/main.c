#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#include "ListaSequencial.h"
#include "ListaDinEncad.h"

int main(){
    clock_t inicio, fim;
    unsigned long int tempo;
    inicio = clock();


    //! ESTATICA SEQUENCIAL
    /*
    int n;
    Lista *li = cria_lista();
    struct aluno al = {100,"Adamastor",60,70,80,
                       200,"Astolfo",  65,70,76,
                       300,"Rodigo",   100,100,100};;

    scanf("%d",&n);
    for(int i = 0; i<n; i++)
        //insere_lista_final(li, al);
        insere_lista_inicio(li, al);
    //!
    */

    //! DINAMICA ENCADEADA
    int n;

    while(scanf("%d",&n)){

        Lista *li = cria_lista();
        struct aluno al = {100,"Adamastor",60,70,80,
                           200,"Astolfo",  65,70,76,
                           300,"Rodigo",   100,100,100};;

        for(int i = 0; i<n; i++)
            //insere_lista_final(li, al);
            insere_lista_inicio(li, al);



        fim = clock();
        tempo = (fim - inicio)*1000 / CLOCKS_PER_SEC;
        printf("Tempo: %dms\n",tempo);
    }

    system("pause");
    return 0;
}
