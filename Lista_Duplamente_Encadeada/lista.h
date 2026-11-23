#ifndef LISTA_H
#define LISTA_H

typedef struct descritor descritor, *pdescritor;

pdescritor iniciarLista(void);

void exibirElementos(pdescritor d);

void esvaziarLista(pdescritor d);

void inserirElementoInicio(pdescritor d, char elem);

void inserirElementoFinal(pdescritor d, char elem);

void inserirElementoQualquerP(pdescritor d, char elem, int posicao);

void removerPorValor(pdescritor d, char valor);

char removerPorPosicao(pdescritor d, int posicao);

int buscarElementoPorValor(pdescritor d, char valor);

int tamanhoLista(pdescritor d);

#endif