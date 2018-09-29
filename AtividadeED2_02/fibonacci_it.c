#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibonacci(int n)
{
    int ant1 = 0, ant2 = 1, atual = 0;
    int i;

    if(n < 2)
    {
        if( n == 1 )
            atual = 1;
        else if( n == 0 )
            atual = 0;
    }
    else
    {
        for(i = 2; i <= n; i++)
        {
            atual = ant1 + ant2;
            ant1 = ant2;
            ant2 = atual;
        }
    }
    return atual;
}

int main()
{
    FILE *f = fopen("tempo2.txt","a");
    if( f == NULL )
    {
        printf("ERRO AO ABRIR ARQUIVO\n");
        return 0;
    }

    clock_t inicio, fim;
    unsigned long long int tempo;
    inicio = clock();

    int n;
    scanf("%d",&n);
    printf("Fib de %d: %d\n",n,fibonacci(n));
    fim = clock();
    tempo = (fim - inicio)*1000 / CLOCKS_PER_SEC;
    printf("Tempo: %llu ms\n",tempo);
    fprintf(f,"%llums\n",tempo);

    fclose(f);
    return 0;
}
