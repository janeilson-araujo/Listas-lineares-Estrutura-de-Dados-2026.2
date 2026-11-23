#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(void)
{
    pdescritor lista = iniciarLista();
    char comando[16];
    float valor;
    int posicao;

    if (lista == NULL)
    {
        return EXIT_FAILURE;
    }

    while (scanf("%15s", comando) == 1)
    {
        if (strcmp(comando, "-s") == 0)
        {
            exibirElementos(lista);
        }
        else if (strcmp(comando, "-c") == 0)
        {
            esvaziarLista(lista);
        }
        else if (strcmp(comando, "-ii") == 0)
        {
            scanf("%f", &valor);
            inserirElementoInicio(lista, valor);
        }
        else if (strcmp(comando, "-if") == 0)
        {
            scanf("%f", &valor);
            inserirElementoFinal(lista, valor);
        }
        else if (strcmp(comando, "-i") == 0)
        {
            scanf("%f %d", &valor, &posicao);
            inserirElementoQualquerP(lista, valor, posicao);
        }
        else if (strcmp(comando, "-r") == 0)
        {
            scanf("%f", &valor);
            removerPorValor(lista, valor);
        }
        else if (strcmp(comando, "-rp") == 0)
        {
            scanf("%d", &posicao);
            removerPorPosicao(lista, posicao);
        }
        else if (strcmp(comando, "-b") == 0)
        {
            scanf("%f", &valor);
            posicao = buscarElementoPorValor(lista, valor);

            if (posicao == -1)
            {
                printf("Elemento %.7g não encontrado.\n", valor);
            }
            else
            {
                printf("Elemento %.7g encontrado na posição %d.\n",
                       valor, posicao);
            }
        }
        else if (strcmp(comando, "-t") == 0)
        {
            printf("Tamanho da lista: %d\n", tamanhoLista(lista));
        }
        else if (strcmp(comando, "-f") == 0)
        {
            break;
        }
    }

    esvaziarLista(lista);
    free(lista);
    return EXIT_SUCCESS;
}
