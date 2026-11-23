#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
    pdescritor lista = iniciarLista();
    char comando[4];
    char valor;
    int posicao;
    int exibicaoPendente = 0;

    if (lista == NULL)
    {
        return EXIT_FAILURE;
    }

    while (scanf("%3s", comando) == 1)
    {
        if (exibicaoPendente)
        {
            if (strcmp(comando, "-f") == 0)
            {
                printf(".");
            }
            else
            {
                printf("\n");
            }
            exibicaoPendente = 0;

            if (strcmp(comando, "-f") == 0)
            {
                printf("\n");
                break;
            }
        }

        if (strcmp(comando, "-s") == 0)
        {
            exibirElementos(lista);
            exibicaoPendente = 1;
        }
        else if (strcmp(comando, "-c") == 0)
        {
            esvaziarLista(lista);
        }
        else if (strcmp(comando, "-ii") == 0)
        {
            scanf(" %c", &valor);
            inserirElementoInicio(lista, valor);
        }
        else if (strcmp(comando, "-if") == 0)
        {
            scanf(" %c", &valor);
            inserirElementoFinal(lista, valor);
        }
        else if (strcmp(comando, "-i") == 0)
        {
            scanf(" %c %d", &valor, &posicao);
            inserirElementoQualquerP(lista, valor, posicao);
        }
        else if (strcmp(comando, "-r") == 0)
        {
            scanf(" %c", &valor);
            removerPorValor(lista, valor);
        }
        else if (strcmp(comando, "-rp") == 0)
        {
            scanf("%d", &posicao);
            removerPorPosicao(lista, posicao);
        }
        else if (strcmp(comando, "-b") == 0)
        {
            scanf(" %c", &valor);
            posicao = buscarElementoPorValor(lista, valor);

            printf("Posição do elemento %c: %d\n", valor, posicao);
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

    if (exibicaoPendente)
    {
        printf("\n");
    }

    esvaziarLista(lista);
    free(lista);
    return 0;
}
