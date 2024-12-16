#include <stdio.h>
#include <stdlib.h>

struct pilha{
    int info;
    struct pilha* prox;
}; typedef struct pilha pilha;

int push(pilha **p, int n){
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

int verifica_igual(pilha* p1, pilha* p2){
    pilha* p = p1;
    pilha* aux = p2;
    while(p != NULL || aux != NULL){
        if(p->info == aux->info){
            aux = aux->prox;
            p = p->prox;
        } else if (p->info != aux->info) {
            printf("Pilhas diferentes!");
            return 0;
        }
    }
    return 1;
}

void imprime(pilha* p1){
    while(p1 != NULL){
        printf("%d ", p1->info);
        p1 = p1->prox;
    }
}

int main(){

pilha* p1 = NULL;
pilha* p2 = NULL;
int i;
    
    push(&p1, 1);
    push(&p1, 2);
    push(&p1, 3);
    push(&p2, 1);
    push(&p2, 2);
    push(&p2, 3);
    push(&p2, 3);
    imprime(p1);
    printf("\n");
    imprime(p2);
    printf("\n");
    i = verifica_igual(p1, p2);
    if(i == 1){
        printf("Igual");
    } 
}