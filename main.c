
#include <stdio.h>
#include "tad.h"

int main() {
    Pilha torreA, torreB, torreC;
    Fila filaJogadores;
    int pontuacoes[MAX_MONGES];
    int i;

    inicializarPilha(&torreA);
    inicializarPilha(&torreB);
    inicializarPilha(&torreC);
    inicializarFila(&filaJogadores);

    int numMonges;
    printf("Informe a quantidade de monges: ");
    scanf("%d", &numMonges);

    for (i = MAX_DISCOS; i > 0; i--) {
        empilhar(&torreA, i);
    }

    for (i = 1; i <= numMonges; i++) {
        char nome[20];
        escolherNomeMonge(nome);
        enfileirar(&filaJogadores, nome);
    }

    while (filaJogadores.frente != -1) {
        char nomeJogador[20];
        strcpy(nomeJogador, desenfileirar(&filaJogadores));
        int discosColocados = 0, discosRetirados = 0;

        printf("\nJogador: %s\n", nomeJogador);

        hanoiComEscolha(MAX_DISCOS, &torreA, &torreB, nomeJogador, &discosColocados, &discosRetirados, &torreA, &torreB, &torreC);

        pontuacoes[filaJogadores.frente] = calcularPontuacao(discosColocados, discosRetirados);

        printf("Pontuação final de %s: %d\n", nomeJogador, pontuacoes[filaJogadores.frente]);
    }

    return 0;
}

