#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da pilha
struct pilha {
    char letra;
    struct pilha* prox;
};
typedef struct pilha pilha;

// Função para empilhar uma letra
void push(pilha** p, char letra) {
    pilha* novo = (pilha*)malloc(sizeof(pilha));
    novo->letra = letra;
    novo->prox = *p;
    *p = novo;
}

// Função para desempilhar uma letra
char pop(pilha** p) {
    if (*p == NULL) {
        return '\0';
    }
    pilha* temp = *p;
    char letra = temp->letra;
    *p = (*p)->prox;
    free(temp);
    return letra;
}

void inverte_palavras(char* texto) {
    pilha* p = NULL;
    int i = 0;
    while (texto[i] != '\0') {
        while (texto[i] != ' ' && texto[i] != '.' && texto[i] != '\0') {
            push(&p, texto[i]);
            i++;
        }
        while (p != NULL) {
            printf("%c", pop(&p));
        }
        if (texto[i] == ' ' || texto[i] == '.') {
            printf("%c", texto[i]);
            i++;
        }
    }
}

int main() {
    char texto[] = "ESTE EXERCÍCIO É MUITO FÁCIL.";
    
    printf("Texto original: %s\n", texto);
    printf("Texto invertido: ");
    inverte_palavras(texto);
    printf("\n");

    return 0;
}
