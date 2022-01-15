#include "ArvoreBinaria.h"

int main()
{
    ArvBin* nova = cria_ArvBin();
    FILE *f = fopen("alunos.txt","r");

    if(f == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO\n");
        return 0;
    }

    struct al* aluno = {1234,"jose",10,7,8};

    while(1)
    {
        fscanf(f,"%d %s %d %d %d",aluno->matricula,aluno->nome,aluno->p1,aluno->p2,aluno->p3);

        insere_ArvBin(nova, al);

        printf("[%d]: %s  p1: %d  p2: %d  p3: %d\n",aluno->matricula,aluno->nome,aluno->p1,aluno->p2,aluno->p3);
        if(feof(f))
            break;

    }
    fclose(f);

    return 0;
}
