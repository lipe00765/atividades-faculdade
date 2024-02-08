#include <stdio.h>
#include "lista.h"

int main() {
    Lista listaOriginal;
    listaOriginal.frente = NULL;
    listaOriginal.tras = NULL;

    Lista listaPares;
    listaPares.frente = NULL;
    listaPares.tras = NULL;

    Lista listaImpares;
    listaImpares.frente = NULL;
    listaImpares.tras = NULL;

    int numero;

    printf("Digite numeros inteiros ou 0 para sair:\n");

    while (1) {
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        adicionar(&listaOriginal, numero);
    }

    printf("Lista Original:\n");
    exibirLista(listaOriginal.frente);

    dividirLista(&listaOriginal, &listaPares, &listaImpares);

    printf("Lista de Numeros Pares:\n");
    exibirLista(listaPares.frente);

    printf("Lista de Numeros Impares:\n");
    exibirLista(listaImpares.frente);

    liberarLista(&listaOriginal);
    liberarLista(&listaPares);
    liberarLista(&listaImpares);

    return 0;
}

