#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista* prox;
}; typedef struct lista lista;

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

void imprime(lista* l){
    lista* aux = l;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

lista* apagaNprimeiros(lista* l, int n){
    lista* aux = NULL;
    int i = 0;
    while(i != n){
        l = l->prox;
        i++;
    }

    while(l != NULL){
        aux = insere(aux, l->info);
        l = l->prox;
    }
    return aux;
}

int main(){

    lista* l1 = NULL;

    l1 = insere(l1, 1);
    l1 = insere(l1, 2);
    l1 = insere(l1, 3);
    l1 = insere(l1, 4);
    l1 = insere(l1, 5);
    l1 = insere(l1, 6);
    imprime(l1);
    l1 = apagaNprimeiros(l1, 4);
    imprime(l1);
}