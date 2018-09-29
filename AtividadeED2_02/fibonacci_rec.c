#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float fibonacci(int n)
{
    float soma=0
    ;
    if(n == 0)
        return 1;
    for(int i = 0; i<n; i++)
    {
        soma += fibonacci(i);
    }
    return (((2.0/n)*soma)+n);
}

int main()
{
    FILE *f = fopen("tempo3.txt","w");
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
