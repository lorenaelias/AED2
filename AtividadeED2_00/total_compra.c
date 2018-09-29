#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *f = fopen("compra.txt","r");
    if(f == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO\n");
        return 0;
    }
    char prod[30];
    float qtd, valor, total = 0.0;

    while(1)
    {
        fscanf(f,"%s %f %f",prod,&qtd,&valor);
        if(feof(f))
            break;
        total += qtd * valor;
    }
    fclose(f);
    printf("TOTAL = %.2f\n",total);
    return 0;
}
