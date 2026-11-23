#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista lista, *plista;

struct lista
{
    char dado;
    plista proximo;
    plista anterior;
};

typedef struct descritor
{
    plista primeiro;
    plista ultimo;
    int tamanho;
} descritor, *pdescritor;

pdescritor iniciarLista(void)
{
    pdescritor d = (pdescritor)calloc(1, sizeof(descritor));

    if (d == NULL)
    {
        return NULL;
    }

    d->tamanho = 0;

    return d;
}

void exibirElementos(pdescritor d)
{
    if (d == NULL || d->primeiro == NULL)
    {
        printf("Lista vazia");
        return;
    }

    plista p = d->primeiro;

    printf("Lista:");
    while (p != NULL)
    {
        printf(" %c", p->dado);
        p = p->proximo;
    }

    return;
}

static void freeElem(plista l)
{
    if (l == NULL)
    {
        return;
    }

    freeElem(l->proximo);

    free(l);
}

void esvaziarLista(pdescritor d)
{
    if (d == NULL || d->primeiro == NULL)
    {
        return;
    }

    freeElem(d->primeiro);

    d->primeiro = NULL;
    d->ultimo = NULL;
    d->tamanho = 0;
}

void inserirElementoInicio(pdescritor d, char elem)
{
    if (d == NULL)
    {
        fprintf(stderr, "Erro: Lista não inicializada.");
        return;
    }

    plista l = calloc(1, sizeof(lista));

    if (l == NULL)
    {
        return;
    }

    l->dado = elem;

    if (d->primeiro != NULL)
    {
        l->proximo = d->primeiro;
        d->primeiro->anterior = l;
        d->primeiro = l;
    }
    else
    {
        d->primeiro = l;
        d->ultimo = l;
    }

    d->tamanho = d->tamanho + 1;
}

void inserirElementoFinal(pdescritor d, char elem)
{
    if (d == NULL)
    {
        fprintf(stderr, "Erro: Lista não inicializada.");
        return;
    }

    plista l = calloc(1, sizeof(lista));

    if (l == NULL)
    {
        return;
    }

    l->dado = elem;

    if (d->primeiro == NULL)
    {
        d->primeiro = l;
        d->ultimo = l;
    }
    else
    {
        l->anterior = d->ultimo;
        d->ultimo->proximo = l;
        d->ultimo = l;
    }

    d->tamanho = d->tamanho + 1;
}

void inserirElementoQualquerP(pdescritor d, char elem, int posicao)
{
    if (d == NULL || posicao < 1 || posicao > d->tamanho + 1)
    {
        fprintf(stderr, "Erro: posição maior que quantidade de elementos na lista.");
        return;
    }

    plista l = calloc(1, sizeof(lista));

    if (l == NULL)
    {
        return;
    }

    plista x = d->primeiro;

    for (int i = 1; i < posicao - 1; i++)
    {
        x = x->proximo;
    }

    l->dado = elem;

    if (posicao == 1)
    {
        l->proximo = d->primeiro;
        if (d->primeiro != NULL)
        {
            d->primeiro->anterior = l;
        }
        d->primeiro = l;
        if (d->ultimo == NULL)
        {
            d->ultimo = l;
        }
    }
    else if (posicao == d->tamanho + 1)
    {
        l->anterior = x;
        x->proximo = l;
        d->ultimo = l;
    }
    else
    {
        l->proximo = x->proximo;
        l->anterior = x;
        x->proximo->anterior = l;
        x->proximo = l;
    }

    d->tamanho = d->tamanho + 1;
}

static void desligarElem(pdescritor d, plista l)
{
    if (l->anterior == NULL)
    {
        d->primeiro = l->proximo;
    }
    else
    {
        l->anterior->proximo = l->proximo;
    }

    if (l->proximo == NULL)
    {
        d->ultimo = l->anterior;
    }
    else
    {
        l->proximo->anterior = l->anterior;
    }
}

void removerPorValor(pdescritor d, char valor)
{
    if (d == NULL)
    {
        fprintf(stderr, "Erro: Lista não inicializada.");
        return;
    }

    plista l = d->primeiro;

    while (l != NULL)
    {
        plista remover = l;
        l = l->proximo;

        if (remover->dado == valor)
        {
            desligarElem(d, remover);
            free(remover);
            d->tamanho--;
        }
    }

    if (d->tamanho == 0)
    {
        d->primeiro = NULL;
        d->ultimo = NULL;
    }
}

char removerPorPosicao(pdescritor d, int posicao)
{
    if (d == NULL || d->primeiro == NULL ||
        posicao < 1 || posicao > d->tamanho)
    {
        return '\0';
    }

    plista l = d->primeiro;

    for (int i = 1; i < posicao; i++)
    {
        l = l->proximo;
    }

    char valorRemovido = l->dado;

    desligarElem(d, l);

    free(l);
    d->tamanho--;

    if (d->tamanho == 0)
    {
        d->primeiro = NULL;
        d->ultimo = NULL;
    }

    return valorRemovido;
}

int buscarElementoPorValor(pdescritor d, char valor)
{
    if (d == NULL || d->primeiro == NULL)
    {
        return -1;
    }

    plista l = d->primeiro;

    for (int i = 1; i <= d->tamanho; i++)
    {
        if (l->dado == valor)
        {
            return i;
        }
        l = l->proximo;
    }

    return -1;
}

int tamanhoLista(pdescritor d)
{
    if (d == NULL)
    {
        fprintf(stderr, "Erro: Lista não inicializada.");
        return 0;
    }

    return d->tamanho;
}