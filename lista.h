#ifndef LISTA_H
#define LISTA_H

struct No {
    int num;
    struct No* proximo;
    struct No* anterior;
};

typedef struct No No;

struct Lista {
    No* frente;
    No* tras;
};

typedef struct Lista Lista;

void adicionar(Lista* lista, int num);
void dividirLista(Lista* original, Lista* pares, Lista* impares);
void exibirLista(No* frente);
void liberarLista(Lista* lista);

#endif

