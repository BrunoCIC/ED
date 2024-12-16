#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista lista;

lista* insere_vetor(lista* l, int v[]) {
    lista* aux = l;
    for (int i = 0; i < 10; i++) {
        lista* novo = (lista*) malloc(sizeof(lista));
        novo->info = v[i];
        novo->prox = NULL;

        if (aux == NULL) {
            aux = novo;
            l = aux;
        } else {
            aux->prox = novo;
            aux = aux->prox;
        }
    }
    return l;
}

void imprime(lista* l) {
    while (l != NULL) {
        printf("%d ", l->info);
        l = l->prox;
    }
    printf("\n");
}


int main() {
    lista* l = NULL;
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    l = insere_vetor(l, v);
    imprime(l);
    return 0;
}
