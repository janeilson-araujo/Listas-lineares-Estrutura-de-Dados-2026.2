#ifndef LISTA_H
#define LISTA_H

typedef struct descritor descritor, *pdescritor;

pdescritor iniciarLista(void);

void exibirElementos(pdescritor d);

void esvaziarLista(pdescritor d);

void inserirElementoInicio(pdescritor d, float elem);

void inserirElementoFinal(pdescritor d, float elem);

void inserirElementoQualquerP(pdescritor d, float elem, int posicao);

void removerPorValor(pdescritor d, float valor);

float removerPorPosicao(pdescritor d, int posicao);

int buscarElementoPorValor(pdescritor d, float valor);

int tamanhoLista(pdescritor d);

#endif