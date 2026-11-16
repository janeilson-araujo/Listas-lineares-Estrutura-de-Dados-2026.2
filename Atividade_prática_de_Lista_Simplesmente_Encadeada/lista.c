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

static void iniciarLista(pdescritor d)
{
    plista l = calloc(1, sizeof(lista));

    d->primeiro = l;
    d->ultimo = l;
}

int exibirElementos(pdescritor d)
{
    plista p = d->primeiro;
    while(p != NULL){
        printf("%d ",&p);

        p = p->proximo;
    }
}

int esvaziarLista(pdescritor d){
    plista p = d->primeiro;
    

}