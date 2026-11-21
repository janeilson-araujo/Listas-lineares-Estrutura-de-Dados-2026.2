#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista lista, *plista;

struct lista
{
    int dado;
    plista proximo;
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

    d->tamanho = 0;

    return d;
}

int exibirElementos(pdescritor d)
{
    if (d == NULL || d->primeiro == NULL)
    {
        fprintf(stderr, "Erro: Lista não inicializada ou vazia.");
        return;
    }

    plista p = d->primeiro;

    while (p != NULL)
    {
        printf("%d ", &p);

        p = p->proximo;
    }
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
        fprintf(stderr, "Erro: Lista não inicializada ou vazia.");
        return;
    }

    freeElem(d->primeiro);

    d->primeiro = NULL;
    d->ultimo = NULL;
    d->tamanho = 0;
}

void inserirElementoInicio(pdescritor d, int elem)
{
    if (d == NULL)
    {
        fprintf(stderr, "Erro: Lista não inicializada.");
        return;
    }

    plista l = calloc(1, sizeof(lista));

    l->dado = elem;

    if (d->primeiro != NULL)
    {
        l->proximo = d->primeiro;
        d->primeiro = l;
    }
    else
    {
        d->primeiro = l;
        d->ultimo = l;
    }

    d->tamanho = d->tamanho + 1;
}

void inserirElementoFinal(pdescritor d, int elem)
{
    if (d == NULL || d->primeiro == NULL)
    {
        fprintf(stderr, "Erro: Lista não inicializada ou vazia.");
        return;
    }

    plista l = calloc(1, sizeof(lista));

    l->dado = elem;
    d->ultimo->proximo = l;
    d->ultimo = l;

    d->tamanho = d->tamanho + 1;
}

void inserirElementoQualquerP(pdescritor d, int elem, int posicao)
{
    if (d == NULL || posicao < 1 || posicao > d->tamanho + 1)
    {
        fprintf(stderr, "Erro: posição maior que quantidade de elementos na lista.");
        return;
    }

    plista l = calloc(1, sizeof(lista));
    plista x = d->primeiro;

    for (int i = 1; i < posicao; i++)
    {
        x = x->proximo;
    }

    l->dado = elem;

    if (posicao == 1)
    {
        l->proximo = d->primeiro;
        d->primeiro = l;
    }
    else if (posicao == d->tamanho + 1)
    {
        x->proximo = l;
        d->ultimo = l;
    }
    else
    {
        l->proximo = x->proximo;
        x->proximo = l;
    }

    d->tamanho = d->tamanho + 1;
}

void removerPorValor(pdescritor d, int valor)
{
    if (d == NULL)
    {
        fprintf(stderr, "Erro: Lista não inicializada.");
        return;
    }

    plista l = d->primeiro;
    plista anterior = NULL;

    for (int i = 1; i <= d->tamanho; i++)
    {

        if (l->dado == valor)
        {

            if (i == 1)
            {

                d->primeiro = d->primeiro->proximo;
                free(l);
                l = NULL;
                l = d->primeiro;
            }
            else if (i == d->tamanho)
            {
                d->ultimo = anterior;
                free(l);
                l = NULL;
                l = anterior->proximo;
            }
            else
            {
                anterior->proximo = l->proximo;
                free(l);
                l = NULL;
            }

            d->tamanho = d->tamanho - 1;
        }
        else
        {
            anterior = l;
            l = l->proximo;
        }
    }
}

int removerPorPosicao(pdescritor d, int posicao)
{
    if (d == NULL)
    {
        fprintf(stderr, "Erro: Lista não inicializada.");
        return;
    }

    plista l = d->primeiro;
    plista anterior = NULL;

    for (int i = 1; i <= posicao; i++)
    {

        if (i == posicao)
        {
            anterior->proximo = l->proximo;
            free(l);
        }
        else
        {
            anterior = l;
            l = l->proximo;
        }
    }
}

int buscarElementoPorValor(pdescritor d, int valor)
{
    if (d == NULL)
    {
        fprintf(stderr, "Erro: Lista não inicializada.");
        return;
    }

    plista l = d->primeiro;

    for (int i = 1; i < d->tamanho; i++)
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
        return;
    }

    return d->tamanho;
}