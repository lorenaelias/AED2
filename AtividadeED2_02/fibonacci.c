#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibonacci(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    else
        return(fibonacci(n-1)+fibonacci(n-2));
}

int main()
{
    FILE *f = fopen("tempo1.txt","a");
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
