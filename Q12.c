#include <stdlib.h>
#include <stdio.h>

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

int conta_impar(pilha* p){
    int i = 0;
    while(p != NULL){
        if(p->info % 2 != 0){
            i++;
        }
        p = p->prox;
    }
    return i;
}

int main(){
    pilha* p = NULL;
    int i = 0;

    push(&p, 1);
    push(&p, 5);
    push(&p, 7);
    push(&p, 9);
    push(&p, 2);
    push(&p, 6);
    push(&p, 11);
    i = conta_impar(p);
    printf("%d", i);
}