#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
}; typedef struct lista lista;

lista* insere(lista* l, int n) {
    lista* novo = (lista*) malloc(sizeof(lista));
    novo->info = n;
    novo->prox = l;
    return novo;
}

lista* concatena(lista* l1, lista* l2) {
    lista* aux = l1;
    lista* aux2 = l2;
    lista* l3 = NULL;

    while (aux != NULL) {
        l3 = insere(l3, aux->info);
        aux = aux->prox;
    }

    while (aux2 != NULL) {
        l3 = insere(l3, aux2->info);
        aux2 = aux2->prox;
    }

    return l3;
}

void imprime(lista* l) {
    lista* aux = l;
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

int main() {
    lista* l1 = NULL;
    lista* l2 = NULL;
    lista* l3 = NULL;

    l1 = insere(l1, 1);
    l1 = insere(l1, 2);
    l1 = insere(l1, 3);
    l1 = insere(l1, 4);

    l2 = insere(l2, 5);
    l2 = insere(l2, 6);

    printf("Lista 1: ");
    imprime(l1);

    printf("Lista 2: ");
    imprime(l2);

    l3 = concatena(l1, l2);

    printf("Lista concatenada: ");
    imprime(l3);

    return 0;
}
