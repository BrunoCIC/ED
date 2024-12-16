#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista* prox;
};
typedef struct lista lista;

lista* insere(lista* l, int n){
    lista* novo = (lista*) malloc(sizeof(lista));
    novo->info = n;
    novo->prox = NULL;

    if(l == NULL){
        return novo;
    } 

    lista* aux = l;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return l;
}


lista* copia(lista* l){
    lista* copia = NULL;

    while(l != NULL){
        copia = insere(copia, l->info);
        l = l->prox;
    }
    return copia;
}

void imprime(lista* l){
    while(l != NULL){
        printf("%d ", l->info);
        l = l->prox;
    }
}



int main(){

    lista* l = NULL;
    lista* aux = NULL;

    l = insere(l, 1);
    l = insere(l, 2);
    l = insere(l, 3);
    l = insere(l, 4);
    l = insere(l, 5);
    l = insere(l, 6);
    l = insere(l, 7);
    l = insere(l, 8);
    imprime(l);
    printf("\n");
    aux = copia(l);
    imprime(aux);

   
return 0;
}