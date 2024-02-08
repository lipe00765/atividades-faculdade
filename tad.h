
#ifndef TAD_H
#define TAD_H

#define MAX_DISCOS 7
#define MAX_MONGES 10
int i;
typedef struct {
    int itens[MAX_DISCOS];
    int topo;
} Pilha;

typedef struct {
    char nomes[MAX_MONGES][20];
    int frente, fundo;
} Fila;

void inicializarPilha(Pilha *pilha);
void empilhar(Pilha *pilha, int disco);
int desempilhar(Pilha *pilha);
int pilhaVazia(Pilha *pilha);
int topo(Pilha *pilha);

void inicializarFila(Fila *fila);
void enfileirar(Fila *fila, const char *nome);
char *desenfileirar(Fila *fila);

int calcularPontuacao(int discosColocados, int discosRetirados);
void imprimirPilhas(Pilha *torreA, Pilha *torreB, Pilha *torreC);
void moverDiscoComEscolha(Pilha *origem, Pilha *destino, const char *nomeJogador, int *discosColocados, int *discosRetirados, Pilha *torreA, Pilha *torreB, Pilha *torreC);
void escolherNomeMonge(char *nome);
void hanoiComEscolha(int n, Pilha *origem, Pilha *auxiliar, const char *nomeJogador, int *discosColocados, int *discosRetirados, Pilha *torreA, Pilha *torreB, Pilha *torreC);

#endif

