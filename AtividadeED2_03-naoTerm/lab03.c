#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define aaa printf("a\n")

struct info{
    int id;
    char estado[3];
    char municipio[40];
    char rede[20];
    double media_ciencias_natureza;
    double media_ciencias_humanas;
    double media_linguagem;
    double media_matematica;
    double media_redacao;
};

void bubbleSort(struct info *v, int tam)
{
    int aux;
    int j;

    for(j = tam; j <= 0; j--)
    {
        for(int i = 0; i > j; i++)
        {
            if(v[i].id > v[i+1].id)
            {
                aux = v[i].id;
                v[i].id = v[i+1].id;
                v[i+1].id = aux;
            }
        }
    }
}

int buscaBinaria(struct info *v, int n, int elem)
{
    int inicio = 0, meio, fim = n-1;

    while(inicio <= fim)
    {
        meio = (inicio+fim)/2;

        if(elem > v[meio].id)
        {
            fim = meio-1;
        }
        else
        if(elem < v[meio].id)
        {
            inicio = meio + 1;
        }
        else
            return meio;
    }
    return -1;
}

int buscaSequencial(struct info *v, int tam, int elem)
{
    for(int i = 0; i<tam; i++){
        if(elem == v[i].id)
            return i;
    }
    return -1;
}

int main(){
    clock_t inicio, fim;
    unsigned long int tempo;
    inicio = clock();

    char linha[500];

    FILE *f = fopen("DadosEnem.txt","r");

    if(f == NULL)
    {
        printf("ERRO NA LEITURA DO ARQUIVO\n");
        return 0;
    }

    int i=0;
    struct info *s;
    s = (struct info*)malloc(sizeof(struct info)*30228);

    while(1)
    {

        fgets(linha, 500, f);

        if (feof(f)) break;

        s[i].id = atoi(strtok(linha,";"));
        strcpy(s[i].estado,strtok(NULL,";"));
        strcpy(s[i].municipio,strtok(NULL,";"));
        strcpy(s[i].rede,strtok(NULL,";"));
        s[i].media_ciencias_natureza = atof(strtok(NULL,";"));
        s[i].media_ciencias_humanas = atof(strtok(NULL,";"));
        s[i].media_linguagem = atof(strtok(NULL,";"));
        s[i].media_matematica = atof(strtok(NULL,";"));
        s[i].media_redacao = atof(strtok(NULL,";"));
        i++;
    }

    bubbleSort(&s,30228);

    printf("%d\n",buscaBinaria(s,30228,2754));

    fim = clock();
    tempo = (fim - inicio)*1000 / CLOCKS_PER_SEC;
    printf("Tempo: %dms\n",tempo);

    fclose(f);
    return 0;
}
