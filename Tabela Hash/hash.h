#define MAX 30

struct aluno{
    int matricula;
    char nome[MAX];
    float n1,n2,n3;
};

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);

void liberaHash(Hash* ha);

int insereHash_SemColisao(Hash* ha, struct aluno al);

int buscaHash_SemColisao(Hash* ha, int mat, struct aluno* al);

int chaveDivisao(int chave, int TABLE_SIZE);
