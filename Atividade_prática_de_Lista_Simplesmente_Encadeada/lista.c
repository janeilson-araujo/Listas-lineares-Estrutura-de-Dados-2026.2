#include <stdio.h>
#include <stdlib.h>
#include <lista.h>

typedef struct lista lista, *plista;

struct lista{
    int dado;
    plista proximo;
};

typedef struct descritor{
    plista primeiro;
    plista ultimo;
}  descritor, *pdescritor;

int exibirElementosLista(){
    
}