#include "tad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i;
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

void empilhar(Pilha *pilha, int disco) {
    pilha->itens[++pilha->topo] = disco;
}

int desempilhar(Pilha *pilha) {
    return pilha->itens[pilha->topo--];
}

int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int topo(Pilha *pilha) {
    return pilha->itens[pilha->topo];
}

void inicializarFila(Fila *fila) {
    fila->frente = -1;
    fila->fundo = -1;
}

void enfileirar(Fila *fila, const char *nome) {
    if (fila->fundo == MAX_MONGES - 1) {
        printf("Fila de jogadores cheia.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(fila->nomes[++fila->fundo], nome);

    if (fila->frente == -1) {
        fila->frente = 0;
    }
}

char *desenfileirar(Fila *fila) {
    if (fila->frente == -1) {
        printf("Fila de jogadores vazia.\n");
        exit(EXIT_FAILURE);
    }

    char *nome = fila->nomes[fila->frente++];

    if (fila->frente > fila->fundo) {
        fila->frente = -1;
        fila->fundo = -1;
    }

    return nome;
}

int calcularPontuacao(int discosColocados, int discosRetirados) {
    return 3 * discosColocados - discosRetirados;
}

void imprimirPilhas(Pilha *torreA, Pilha *torreB, Pilha *torreC) {
    printf("Torre A: ");
    for (i = torreA->topo; i >= 0; i--) {
        printf("%d ", torreA->itens[i]);
    }
    printf("\nTorre B: ");
    for (i = torreB->topo; i >= 0; i--) {
        printf("%d ", torreB->itens[i]);
    }
    printf("\nTorre C: ");
    for (i = torreC->topo; i >= 0; i--) {
        printf("%d ", torreC->itens[i]);
    }
    printf("\n");
}

void moverDiscoComEscolha(Pilha *origem, Pilha *destino, const char *nomeJogador, int *discosColocados, int *discosRetirados, Pilha *torreA, Pilha *torreB, Pilha *torreC) {
    int disco = desempilhar(origem);
    empilhar(destino, disco);

    (*discosColocados)++;
    (*discosRetirados)--;

    printf("Jogador: %s, Movimentos: %d, Pontuação: %d, Origem: %c, Destino: %c\n",
           nomeJogador, *discosColocados + *discosRetirados,
           calcularPontuacao(*discosColocados, *discosRetirados),
           (origem == torreA ? 'A' : (origem == torreB ? 'B' : 'C')),
           (destino == torreA ? 'A' : (destino == torreB ? 'B' : 'C')));

    imprimirPilhas(torreA, torreB, torreC);
}

void escolherNomeMonge(char *nome) {
    printf("Escolha o nome do monge: ");
    scanf("%s", nome);
}

void hanoiComEscolha(int n, Pilha *origem, Pilha *auxiliar, const char *nomeJogador, int *discosColocados, int *discosRetirados, Pilha *torreA, Pilha *torreB, Pilha *torreC) {
    printf("Escolha o destino para o disco (A, B, C): ");
    char destino;
    scanf(" %c", &destino);

    Pilha *destinoPilha;
    switch (destino) {
    case 'A':
        destinoPilha = torreA;
        break;
    case 'B':
        destinoPilha = torreB;
        break;
    case 'C':
        destinoPilha = torreC;
        break;
    default:
        printf("Destino inválido.\n");
        exit(EXIT_FAILURE);
    }

    if (n > 0) {
        hanoiComEscolha(n - 1, origem, destinoPilha, nomeJogador, discosColocados, discosRetirados, torreA, torreB, torreC);
        moverDiscoComEscolha(origem, destinoPilha, nomeJogador, discosColocados, discosRetirados, torreA, torreB, torreC);
        hanoiComEscolha(n - 1, auxiliar, origem, nomeJogador, discosColocados, discosRetirados, torreA, torreB, torreC);
    }
}

