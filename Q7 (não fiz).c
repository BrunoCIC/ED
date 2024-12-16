#include <stdio.h>
#include <stdlib.h>

struct pilha{
    int info;
    struct pilha* prox;
}; typedef struct pilha pilha;

int push(pilha** p, int n){
    pilha* novo = (pilha*) malloc(sizeof(pilha));

    if(novo == NULL){
        return 0;
    }

    novo->info = n;
    novo->prox = *p;
    *p = novo;
    
    return 1;
}

int pop(pilha** p){
    if(*p == NULL){
        return 0;
    }

    pilha* novo = *p;
    *p = (*p)->prox;

    int info = novo->info;
    free(novo);
    return 1;
}