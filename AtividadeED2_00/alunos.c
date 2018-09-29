#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("notas.txt","r");
    if(f == NULL)
    {
        printf("ERRO NA LEITURA DO ARQUIVO\n");
        return 0;
    }
    char nome[30];
    float nota;
    float media = 0.0;
    float nota1 = 0.0;
    float maior = 0.0;
    int i = 0;
    char str[5];

    while(!feof(f))
    {
        fscanf(f,"%s[^: ]",str);
        fscanf(f,"%s[^: ]",nome);
        fscanf(f,"%s[^: ]",str);
        fscanf(f,"%f[^: ]",&nota);
        printf("%s %.2f\n",nome,nota);
        media += nota;
        i++;
        if(nota > maior)
            maior = nota;
    }
    fclose(f);
    media /= i;

    printf("\nMEDIA DA TURMA = %.2f\n",media);
    printf("MAIOR NOTA = %.2f\n",maior);
    return 0;
}
