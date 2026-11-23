#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista lista, *plista;

struct lista
{
    int dado;
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
    for (int i = 0; i < d->tamanho; i++)
    {
        printf(" %d", p->dado);
        p = p->proximo;
    }

    return;
}

void esvaziarLista(pdescritor d)
{
    if (d == NULL || d->primeiro == NULL)
    {
        return;
    }

    plista p = d->primeiro;

    for (int i = 0; i < d->tamanho; i++)
    {
        plista remover = p;
        p = p->proximo;
        free(remover);
    }

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
        l->anterior = d->ultimo;
        d->primeiro->anterior = l;
        d->ultimo->proximo = l;
        d->primeiro = l;
    }
    else
    {
        l->proximo = l;
        l->anterior = l;
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
        l->proximo = l;
        l->anterior = l;
        d->primeiro = l;
        d->ultimo = l;
    }
    else
    {
        l->proximo = d->primeiro;
        l->anterior = d->ultimo;
        d->ultimo->proximo = l;
        d->primeiro->anterior = l;
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

    if (posicao == 1)
    {
        inserirElementoInicio(d, elem);
        return;
    }

    if (posicao == d->tamanho + 1)
    {
        inserirElementoFinal(d, elem);
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
    l->proximo = x->proximo;
    l->anterior = x;
    x->proximo->anterior = l;
    x->proximo = l;

    d->tamanho = d->tamanho + 1;
}

static void desligarElem(pdescritor d, plista l)
{
    if (d->tamanho == 1)
    {
        d->primeiro = NULL;
        d->ultimo = NULL;
        return;
    }

    l->anterior->proximo = l->proximo;
    l->proximo->anterior = l->anterior;

    if (l == d->primeiro)
    {
        d->primeiro = l->proximo;
    }

    if (l == d->ultimo)
    {
        d->ultimo = l->anterior;
    }
}

void removerPorValor(pdescritor d, int valor)
{
    if (d == NULL)
    {
        fprintf(stderr, "Erro: Lista não inicializada.");
        return;
    }

    plista l = d->primeiro;
    int quantidade = d->tamanho;

    for (int i = 0; i < quantidade; i++)
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
}

int removerPorPosicao(pdescritor d, int posicao)
{
    if (d == NULL || d->primeiro == NULL ||
        posicao < 1 || posicao > d->tamanho)
    {
        return -1;
    }

    plista l = d->primeiro;

    for (int i = 1; i < posicao; i++)
    {
        l = l->proximo;
    }

    int valorRemovido = l->dado;

    desligarElem(d, l);

    free(l);
    d->tamanho--;

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
