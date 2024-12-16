#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista* prox;
};
typedef struct lista lista;

lista* insere(lista* l, int i){
    lista* novo = (lista*) malloc(sizeof(lista));
    novo->info = i;
    novo-> prox = l;
    return novo;
}

int conta_no(lista* l){
    int i = 0;
    lista *aux = l;
    while(aux != NULL){
        i++;
        aux = aux->prox;
    }
    return i;
}

int main(){

    lista* l = NULL;
    int contador = 0;

    l = insere(l, 1);
    l = insere(l, 2);
    l = insere(l, 3);
    l = insere(l, 4);
    l = insere(l, 5);
    l = insere(l, 6);
    l = insere(l, 7);
    l = insere(l, 8);
    l = insere(l, 8);
    contador = conta_no(l);
    printf("%d", contador);

return 0;
}