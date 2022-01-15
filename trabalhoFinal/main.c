/*
	Grupo  LRG
	Integrantes:
	Lorena da Silva Elias   - 11721BCC019
	Rodrigo Zamboni Silva  	- 11721BCC034
    Gabriel Bueno Otsuka  	- 11721BCC018
*/
#include"TrabalhoFinalAED22.h"
#include"TrabalhoFinalAED22.c"

int main(){

    menu();
    //Executa a leitura do nome do arquivo o qual o algoritmo ira trabalhar
    char fonte[100];
    printf("Digite o nome do arquivo com o texto base\n");
    scanf("%s[^\n]\n",fonte);

    //Abertura e checagem de arquivo
    FILE *fp;
    fp = fopen(fonte,"r");
    if (fp == NULL){
        printf ("ERRO NA ABERTURA DO ARQUIVO\n");
        return 0;
    }

    int cont=0,j=0;             // contadores auxiliares
    char str[600],*tok;         // auxiliares para percorrer o arquivo
    char palavras[5000][50];    // vetor de palavras sem repeticao
    char lista[5000][50];       // vetor de palavras com repeticao

    //Esse while trata o arquivo de texto, preparando as paravras para serem inseridas no grafo
    while(1){

        if(fgets(str,600,fp) == NULL) break;
        tok = strtok(str," \n");
        strcpy(lista[j],tok);
        j++;
        if(busca(palavras,tok,cont)==0){
            strcpy(palavras[cont],tok);
            cont++;
        }
        while(1){
            tok = strtok(NULL," \n");
            if(tok == NULL)break;
            strcpy(lista[j],tok);
            j++;
            if(busca(palavras,tok,cont)==0){
                strcpy(palavras[cont],tok);
                cont++;
            }
        }
  }

    Grafo *G = cria_grafo(cont);
    preencheGrafo(G,lista,palavras,j,cont);

    srand(time(NULL));

    //Faz a leitura de um valor 'qnt' que será a quantidade de frase aleatórias a ser geradas
    printf("\nNumero de frases a serem geradas: ");
    int qnt;
    scanf("%d",&qnt);
    system("cls");
    menu();

    //gera as 'qnt' frases aleatórias
    while(qnt != 0){
        gera_frase(G,palavras,cont);
        qnt--;
    }
    printf("\n\n");


return  0;
}
