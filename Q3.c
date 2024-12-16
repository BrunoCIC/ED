#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista* prox;
}; 
typedef struct lista lista;

lista *inicializa(){
    return NULL;
}

lista* insere(lista* l, int i){
    lista *novo = (lista*) malloc(sizeof(lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

void imprime_lista (lista *l) {
lista * lista_imprime = l ;
while ( lista_imprime != NULL ) {
printf ("%d ", lista_imprime -> info );
lista_imprime -> prox ;
}
printf("\n");
}


lista* concatena(lista* l1, lista* l2){
    if(l1 == NULL){
        return l2;
    }
        lista* l3 = l1;
        while(l3->prox != NULL){
            l3 = l3->prox;
        }   
        l3->prox = l2;
    return l1;
}


int main(){

lista* l1 = NULL;
lista* l2 = NULL;

l1 = insere(l1, 2);
l1 = insere(l1, 3);
l1 = insere(l1, 5);
l1 = insere(l1, 6);
l2 = insere(l2, 7);
l2 = insere(l2, 12);
concatena(l1, l2);
imprime_lista(l1);

return 0;
}