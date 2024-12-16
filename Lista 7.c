#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pilha {
    char letra;
    struct pilha* prox;
}; typedef struct pilha pilha;

int push(pilha** p, char n) {
    pilha* novo = (pilha*) malloc(sizeof(pilha));
    if (novo == NULL) {
        return 0;
    }
    novo->letra = n;
    novo->prox = *p;
    *p = novo;
    return 1;
}

int pop(pilha** p, char* n) {
    if (*p == NULL) {
        return 0;
    }
    pilha* topo = *p;
    *p = (*p)->prox;
    *n = topo->letra;
    free(topo);
    return 1;
}

int verificaFormaXY(const char* str) {
    int len = strlen(str);

    if (len % 2 != 0) {
        return 0;
    }

    int meio = len / 2;
    if (str[meio - 1] != str[meio]) {
        return 0;
    }

    pilha* p = NULL;

    for (int i = 0; i < meio; i++) {
        push(&p, str[i]);
    }

    for (int i = meio; i < len; i++) {
        char c;
        if (!pop(&p, &c) || c != str[i]) {
            return 0;
        }
    }

    return 1;
}

char* inverte(const char* str){
    pilha* p = NULL;
    int len = strlen(str);

    for(int i = 0; i < len; i++){
        if(str[i] != '.'){
            push(&p, str[i]);
        }
    }

    char* aux = (char*) malloc((len + 1) * sizeof(char));
    int i = 0;
    while(p->prox != NULL){
        pop(&p, &aux[i]);
        i++;
    }
    aux[i] = '.';
    aux[i+1] = '\0';

    return aux;
}


int main() {
    const char* str = "abacaxi anatomico.";
    char* aux = inverte(str);
    
    printf("%s",aux);
    

    return 0;
}
