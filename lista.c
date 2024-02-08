#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void adicionar(Lista* lista, int num) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }

    novoNo->num = num;
    novoNo->proximo = NULL;
    novoNo->anterior = lista->tras;

    if (lista->frente == NULL) {
        lista->frente = novoNo;
    } else {
        lista->tras->proximo = novoNo;
    }

    lista->tras = novoNo;
}

void dividirLista(Lista* original, Lista* pares, Lista* impares) {
    No* atual = original->frente;

    while (atual != NULL) {
        if (atual->num % 2 == 0) {
            adicionar(pares, atual->num);
        } else {
            adicionar(impares, atual->num);
        }
        atual = atual->proximo;
    }
}

void exibirLista(No* frente) {
    No* atual = frente;

    while (atual != NULL) {
        printf("%d ", atual->num);
        atual = atual->proximo;
    }

    printf("\n");
}

void liberarLista(Lista* lista) {
    No* atual = lista->frente;
    No* proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    lista->frente = NULL;
    lista->tras = NULL;
}

