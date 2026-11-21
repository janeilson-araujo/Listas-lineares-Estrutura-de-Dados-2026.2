#ifndef LISTA_H
#define LISTA_H

typedef struct descritor descritor, *pdescritor;

pdescritor iniciarLista(void);

int exibirElementos(pdescritor d);

void esvaziarLista(pdescritor d);

void inserirElementoInicio(pdescritor d, int elem);

void inserirElementoFinal(pdescritor d, int elem);

void inserirElementoQualquerP(pdescritor d, int elem, int posicao);

void removerPorValor(pdescritor d, int valor);

int removerPorPosicao();

int buscarElementoPorValor();

int tamanhoLista();

#endif