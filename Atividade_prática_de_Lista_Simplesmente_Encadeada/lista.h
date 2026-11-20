#ifndef LISTA_H
#define LISTA_H

typedef struct descritor descritor, *pdescritor;

pdescritor iniciarLista(void);

int exibirElementos(pdescritor d);

void esvaziarLista(pdescritor d);

void inserirElementoInicio(pdescritor d, int elem);

void inserirElementoFinal(pdescritor d, int elem);

void inserirElementoQualquerP();

void removerPorValor();

int removerPorPosicao();

int buscarElementoPorValor();

int tamanhoLista();

#endif