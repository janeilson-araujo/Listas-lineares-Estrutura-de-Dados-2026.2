#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista lista, *plista;

struct lista
{
    float dado;
    plista proximo;
};

#define FLOAT_EPSILON 1e-5f

static int floatIgual(float a, float b)
{
    float diferenca = a - b;
    return diferenca < FLOAT_EPSILON && diferenca > -FLOAT_EPSILON;
}

struct descritor
{
    plista primeiro;
    plista ultimo;
    int tamanho;
};

pdescritor iniciarLista(void)
{
    pdescritor d = calloc(1, sizeof(descritor));
    return d;
}

void exibirElementos(pdescritor d)
{
    if (d == NULL || d->primeiro == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    plista atual = d->primeiro;

    printf("Lista:");
    for (int i = 0; i < d->tamanho; i++)
    {
        printf(" %.7g", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

void esvaziarLista(pdescritor d)
{
    if (d == NULL || d->primeiro == NULL)
    {
        if (d != NULL)
        {
            d->primeiro = NULL;
            d->ultimo = NULL;
            d->tamanho = 0;
        }
        return;
    }

    plista atual = d->primeiro;

    for (int i = 0; i < d->tamanho; i++)
    {
        plista remover = atual;
        atual = atual->proximo;
        free(remover);
    }

    d->primeiro = NULL;
    d->ultimo = NULL;
    d->tamanho = 0;
}

void inserirElementoInicio(pdescritor d, float elem)
{
    if (d == NULL)
    {
        return;
    }

    plista novo = calloc(1, sizeof(lista));
    if (novo == NULL)
    {
        return;
    }

    novo->dado = elem;

    if (d->primeiro == NULL)
    {
        d->primeiro = novo;
        d->ultimo = novo;
        novo->proximo = novo;
    }
    else
    {
        novo->proximo = d->primeiro;
        d->ultimo->proximo = novo;
        d->primeiro = novo;
    }

    d->tamanho++;
}

void inserirElementoFinal(pdescritor d, float elem)
{
    if (d == NULL)
    {
        return;
    }

    plista novo = calloc(1, sizeof(lista));
    if (novo == NULL)
    {
        return;
    }

    novo->dado = elem;

    if (d->primeiro == NULL)
    {
        d->primeiro = novo;
        d->ultimo = novo;
        novo->proximo = novo;
    }
    else
    {
        novo->proximo = d->primeiro;
        d->ultimo->proximo = novo;
        d->ultimo = novo;
    }

    d->tamanho++;
}

void inserirElementoQualquerP(pdescritor d, float elem, int posicao)
{
    if (d == NULL || posicao < 1 || posicao > d->tamanho + 1)
    {
        return;
    }

    if (posicao == 1)
    {
        inserirElementoInicio(d, elem);
    }
    else if (posicao == d->tamanho + 1)
    {
        inserirElementoFinal(d, elem);
    }
    else
    {
        plista novo = calloc(1, sizeof(lista));
        if (novo == NULL)
        {
            return;
        }

        novo->dado = elem;
        plista anterior = d->primeiro;

        for (int i = 1; i < posicao - 1; i++)
        {
            anterior = anterior->proximo;
        }

        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
        d->tamanho++;
    }
}

void removerPorValor(pdescritor d, float valor)
{
    if (d == NULL || d->primeiro == NULL)
    {
        return;
    }

    plista atual = d->primeiro;
    plista anterior = d->ultimo;
    int quantidade = d->tamanho;

    for (int i = 0; i < quantidade; i++)
    {
        plista proximo = atual->proximo;

        if (floatIgual(atual->dado, valor))
        {
            if (d->tamanho == 1)
            {
                d->primeiro = NULL;
                d->ultimo = NULL;
                d->tamanho = 0;
                free(atual);
                return;
            }

            anterior->proximo = proximo;

            if (atual == d->primeiro)
            {
                d->primeiro = proximo;
            }
            if (atual == d->ultimo)
            {
                d->ultimo = anterior;
            }

            free(atual);
            d->tamanho--;
            atual = proximo;
        }
        else
        {
            anterior = atual;
            atual = proximo;
        }
    }
}

float removerPorPosicao(pdescritor d, int posicao)
{
    if (d == NULL || d->primeiro == NULL ||
        posicao < 1 || posicao > d->tamanho)
    {
        return 0.0f;
    }

    plista remover = d->primeiro;
    plista anterior = d->ultimo;

    for (int i = 1; i < posicao; i++)
    {
        anterior = remover;
        remover = remover->proximo;
    }

    float valor = remover->dado;

    if (d->tamanho == 1)
    {
        d->primeiro = NULL;
        d->ultimo = NULL;
    }
    else
    {
        anterior->proximo = remover->proximo;

        if (remover == d->primeiro)
        {
            d->primeiro = remover->proximo;
        }
        if (remover == d->ultimo)
        {
            d->ultimo = anterior;
        }
    }

    free(remover);
    d->tamanho--;
    return valor;
}

int buscarElementoPorValor(pdescritor d, float valor)
{
    if (d == NULL || d->primeiro == NULL)
    {
        return -1;
    }

    plista atual = d->primeiro;

    for (int i = 1; i <= d->tamanho; i++)
    {
        if (floatIgual(atual->dado, valor))
        {
            return i;
        }
        atual = atual->proximo;
    }

    return -1;
}

int tamanhoLista(pdescritor d)
{
    if (d == NULL)
    {
        return 0;
    }
    return d->tamanho;
}