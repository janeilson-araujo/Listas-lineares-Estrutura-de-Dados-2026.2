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
        printf("Lista vazia.\n");
        return ;
    }

    plista p = d->primeiro;

    printf("Lista:");
    while (p != NULL)
    {
        printf("%d ", p->dado);
        p = p->proximo;
    }

    printf("\n");
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

void inserirElementoInicio(pdescritor d, int elem)
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
        d->ultimo->proximo = l;
        d->ultimo = l;
    }

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
        d->primeiro = l;
        if (d->ultimo == NULL)
        {
            d->ultimo = l;
        }
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

    while (l != NULL)
    {
        if (l->dado == valor)
        {
            plista remover = l;

            if (anterior == NULL)
            {
                l = d->primeiro;
                d->primeiro = l->proximo;
                l = d->primeiro;
            }
            else
            {
                anterior->proximo = l->proximo;
                l = l->proximo;
            }

            if (remover == d->ultimo)
            {
                d->ultimo = anterior;
            }

            free(remover);
            d->tamanho--;
        }
        else
        {
            anterior = l;
            l = l->proximo;
        }
    }

    if (d->tamanho == 0)
    {
        d->primeiro = NULL;
        d->ultimo = NULL;
    }
}

int removerPorPosicao(pdescritor d, int posicao)
{
    if (d == NULL || d->primeiro == NULL ||
        posicao < 1 || posicao > d->tamanho)
    {
        return -1;
    }

    plista l = d->primeiro;
    plista anterior = NULL;

    for (int i = 1; i < posicao; i++)
    {
        anterior = l;
        l = l->proximo;
    }

    int valorRemovido = l->dado;

    if (anterior == NULL)
    {
        d->primeiro = l->proximo;
    }
    else
    {
        anterior->proximo = l->proximo;
    }

    if (l == d->ultimo)
    {
        d->ultimo = anterior;
    }

    free(l);
    d->tamanho--;

    if (d->tamanho == 0)
    {
        d->primeiro = NULL;
        d->ultimo = NULL;
    }

    return valorRemovido;
}

int buscarElementoPorValor(pdescritor d, int valor)
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