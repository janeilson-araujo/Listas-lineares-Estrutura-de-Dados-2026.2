#include <stdio.h>
#include <stdlib.h>
#include <lista.h>

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
    pdescritor d = (pdescritor) calloc(1,sizeof(descritor));

    return d;
}

int exibirElementos(pdescritor d)
{
    if(d == NULL){
        fprintf(stderr, "Erro: Lista não inicializada.");
        return ;
    }
    plista p = d->primeiro;
    while (p != NULL)
    {
        printf("%d ", &p);

        p = p->proximo;
    }
}

void esvaziarLista(plista l)
{

    if (l->proximo != NULL)
    {
        esvaziarLista(l->proximo);
    }
    free(l);
}

void inserirElementoInicio(pdescritor d, int elem)
{
    if (d == NULL)
    { // ajeitar essa logica
        fprintf(stderr, "Erro: Lista não inicializada.");
        return ;
    }

    plista l = calloc(1, sizeof(lista));

    l->dado = elem;
    l->proximo = d->primeiro;
    d->primeiro = l;

    d->tamanho = d->tamanho + 1;
}

void inserirElementoFinal(pdescritor d, int elem)
{
    if (d == NULL)
    { // ajeitar essa logica
        fprintf(stderr, "Erro: Lista não inicializada.");
        return ;
    }

    plista l = calloc(1, sizeof(lista));

    l->dado = elem;
    d->ultimo->proximo = l;
    d->ultimo = l;

    d->tamanho = d->tamanho + 1;
}

void inserirElementoQualquerP(pdescritor d, int elem, int posicao)
{
    if (posicao > d->tamanho)
    { // ajeitar essa logica
        return;
    }
    plista l = calloc(1, sizeof(lista));
    plista x = d->primeiro;

    for (int i = 1; i < posicao; i++)
    {
        x = x->proximo;
    }

    l->dado = elem;
    l->proximo = x->proximo;
    x->proximo = l;

    d->tamanho = d->tamanho + 1;
}

void removerPorValor(pdescritor d, int valor)
{
    if (d == NULL)
    { // ajeitar essa logica
        return;
    }

    plista x = d->primeiro;

    for (int i = 1; i < d->tamanho; i++)
    {

        if (x->dado == valor)
        {

            if (i == 1)
            {
                d->primeiro = x->proximo;
                free(x);
            }
        }

        x = x->proximo;
    }
}