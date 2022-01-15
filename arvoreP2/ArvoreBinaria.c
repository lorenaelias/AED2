#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Protótipos

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;

    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;

    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;

    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento já existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }

        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;

    struct NO* atual = *raiz;

    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}

//! daqui pra baixo sao questoes da lista de aed2
//! nao testei alguns codigos

int totalnaofolhas_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    if(((&((*raiz)->esq)) == NULL) && ((&((*raiz)->dir)) == NULL))
        return 0;

    return (1 + totalnaofolhas_ArvBin(&((*raiz)->dir)) + totalnaofolhas_ArvBin(&((*raiz)->esq)));
}

int totalfolhas_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    if(&((*raiz)->dir) == NULL && &((*raiz)->esq) == NULL)
        return 1;
    else
        return totalfolhas_ArvBin(&((*raiz)->dir))+ totalfolhas_ArvBin(&((*raiz)->esq));
}

int buscaImpar(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz != NULL){
        if((((*raiz)->info) % 2) != 0)
            return 1;
        buscaImpar(&((*raiz)->esq));
        buscaImpar(&((*raiz)->dir));
    }
    return 0;
}

void removePar(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        if((((*raiz)->info) % 2) == 0)
            remove_ArvBin(&(*raiz),(*raiz)->info);
        removePar(&((*raiz)->esq));
        removePar(&((*raiz)->dir));
    }
}

int maiorValorABB(ArvBin* raiz){
    if(raiz == NULL)
        return -1;

    struct NO* atual = *raiz;

    while(atual->dir != NULL)
        atual = atual->dir;

    return(atual->info);
}

int menorValorABB(ArvBin* raiz){
    if(raiz == NULL)
        return -1;

    struct NO* atual = *raiz;

    while(atual->esq != NULL)
        atual = atual->esq;

    return(atual->info);
}

int eh_ABB(ArvBin* raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 1;

    // se maior da esquerda for maior que atual, nao é abb
    if (((*raiz)->esq!=NULL) && (maiorValorABB(&(*raiz)->esq) > (*raiz)->info))
        return 0;

    // se menor da direita for menor que atual, nao é abb
    if (((*raiz)->dir!=NULL) && (menorValorABB(&(*raiz)->dir) < (*raiz)->info))
        return 0;

    // aplica recursao, se algum dos dois lados nao for abb, a arvore inteira nao é abb
    if (!eh_ABB(&(*raiz)->esq) || !eh_ABB(&(*raiz)->dir))
        return 0;

    // se passar por todos os testes, é uma abb
    return 1;
}

void espelhar(ArvBin* ant,ArvBin* nova){
  if(*ant != NULL){
    insere_ArvBin(nova,(*ant)->info);
    espelhar(&(*ant)->esq, &(*nova)->dir);
    espelhar(&(*ant)->dir, &(*nova)->esq);
  }
  else
    return;
}

int similar(ArvBin* a, ArvBin* b) {
return (estaVazia_ArvBin(a) && estaVazia_ArvBin(b)) || ((!estaVazia_ArvBin(a) && !estaVazia_ArvBin(b) && (*a)->info == (*b)->info
&& similar(&(*a)->esq, &(*b)->esq) && similar(&(*a)->dir, &(*b)->dir)));
}

int IsStrictlyBinary(ArvBin* root) {

    if((&(*root)->esq) == NULL && (&(*root)->dir == NULL))
        return 1;

    else if ((&(*root)->esq == NULL && &(*root)->dir != NULL)  ||
             (&(*root)->dir == NULL && &(*root)->esq != NULL)   )
        return 0;

    else
        return IsStrictlyBinary(&(*root)->esq) && IsStrictlyBinary(&(*root)->dir);
}

// tamanho da arvore iterativo
int treeHeight(ArvBin *root)
{
    if (root == NULL)
        return 0;
    if (*root == NULL)
        return 0;

    Fila *q = cria_fila();

    // empilha a raiz
    push(q,*root);
    int height = 0;

    while (1)
    {
        // nodeCount (tamanho da fila) indica num de nos no nivel atual
        int nodeCount = tamanho(q);
        if (nodeCount == 0)
            return height;

        height++;

        // desempilha todos os nós do nivel atual
        // empilha todos os nós do proximo nivel
        while (nodeCount > 0)
        {
            struct no *node = le_inicio(q);
            pop(q);
            if (node->left != NULL)
                push( q, &((*node)->left) );

            if (node->right != NULL)
                push( q, &((*node)->right) );
            nodeCount--;
        }
    }
}

void preOrdem_ArvBinI(ArvBin* raiz){
    if(raiz == NULL)
        return;
    //! cria pilha
    //! empilhar a raiz
    //! enquanto a pilha nao estiver vazia
    //! guarda topo da pilha
    //! printa o topo
    //! desempilha
    //! empilha direita
    //! empilha esquerda
}


// achei na interwebs pq eu to com preguiça ja
// percurso em nivel de uma arvore binaria
/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

//! caminhos da raiz ate cada folha
/*Given a binary tree, print out all of its root-to-leaf
 paths, one per line. Uses a recursive helper to do the work.*/
void printPaths(struct node* node)
{
  int path[1000];
  printPathsRecur(node, path, 0);
}

/* Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths.*/
void printPathsRecur(struct node* node, int path[], int pathLen)
{
  if (node==NULL)
    return;

  /* append this node to the path array */
  path[pathLen] = node->data;
  pathLen++;

  /* it's a leaf, so print the path that led to here  */
  if (node->left==NULL && node->right==NULL)
  {
    printArray(path, pathLen);
  }
  else
  {
    /* otherwise try both subtrees */
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}
