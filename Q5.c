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
    novo->prox = l;
    return novo;
}

lista* insere_final(lista* l, int n){
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


lista* remove_n_primeiros(lista* l, int n){

    for(int i = 0; i < n; i++){
        l = l->prox;
    }

    lista* aux = NULL;

    while(l != NULL){
        aux = insere(aux, l->info);
        l = l->prox;
    }

return aux;
}

void imprime(lista *l) {
    lista * lista_imprime = l ;
    while ( lista_imprime != NULL ) {
        printf ("%d ", lista_imprime -> info );
        lista_imprime = lista_imprime -> prox ;
 }

 printf ("\n");
 }

int main(){

lista* l = NULL;
lista* exemplo = NULL;

l = insere_final(l, 1);
l = insere_final(l, 2);
l = insere_final(l, 3);
l = insere_final(l, 4);
imprime(l);
printf("\n");
exemplo = remove_n_primeiros(l, 2);
imprime(exemplo);

}