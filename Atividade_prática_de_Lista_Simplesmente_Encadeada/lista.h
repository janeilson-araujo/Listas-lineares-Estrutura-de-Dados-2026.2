#ifndef LISTA_H
#define LISTA_H

typedef struct descritor descritor, *pdescritor;

pdescritor iniciarLista(void);

int exibirElementos(pdescritor d);

void esvaziarLista();

void inserirElementoInicio();

void inserirElementoFinal();

void inserirElementoQualquerP();

void removerPorValor();

int removerPorPosicao();

int buscarElementoPorValor();

int tamanhoLista();

#endif