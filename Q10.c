#include <stdio.h>
#include <stdlib.h>

struct pilha{
    int info;
    struct pilha* prox;
}; typedef struct pilha pilha;

struct fila{
    int info;
    struct fila* prox;
}; typedef struct fila fila;

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

int enfileirar(fila** f, int n){
    fila* novo = (fila*) malloc(sizeof(fila));

    if(novo == NULL){
        return 0;
    }
    novo->info = n;
    if(*f == NULL){
        novo->prox = NULL;
        *f = novo;
        return 1;
    }

    fila* aux = *f;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    novo->prox = NULL;
    aux->prox = novo;
    return 1;
}

int desinfileirar(fila** f){
    if(*f == NULL){
        return 0;
    }
    fila* novo = *f;
    *f = (*f)->prox;
    free(novo);
    return 1;
}

void imprime_pilha(pilha* p){
    while(p != NULL){
        printf("%d ", p->info);
        p = p->prox;
    }
}

void imprime_fila(fila* p){
    while(p != NULL){
        printf("%d ", p->info);
        p = p->prox;
    }
}



int main(){
fila* f1 = NULL;
pilha* p1 = NULL;

    enfileirar(&f1, 1);
    enfileirar(&f1, 2);
    enfileirar(&f1, 3);
    enfileirar(&f1, 4);
    imprime_fila(f1);
    while(f1 != NULL){
        push(&p1, f1->info);
        desinfileirar(&f1);   
    }
    printf("\n");
    imprime_pilha(p1);

}