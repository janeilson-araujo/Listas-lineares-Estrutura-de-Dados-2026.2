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

static void iniciarLista(pdescritor d, int elem)
{
    plista l = calloc(1, sizeof(lista));

    l->dado = elem;

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

void esvaziarLista(plista l){
    if(l->proximo != NULL){
       esvaziarLista(l->proximo); 
    }
    free(l);
}

void inserirElementoInicio(pdescritor d, int elem){
    if(d == NULL){ //ajeitar essa logica
        iniciarLista(d, elem);
    }
    
    plista l = calloc(1, sizeof(lista));

    l->dado = elem;
    l->proximo = d->primeiro;
    d->primeiro = l;
}

void inserirElementoFinal(pdescritor d, int elem){
    if(d == NULL){  //ajeitar essa logica
        iniciarLista(d, elem);
    }

    plista l = calloc(1, sizeof(lista));

    l->dado = elem;
    d->ultimo->proximo = l;
    d->ultimo = l;
}

