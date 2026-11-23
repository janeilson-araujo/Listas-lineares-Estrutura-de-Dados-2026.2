# Exercício: Implementando o Tipo Abstrato Lista Encadeada

## Objetivo

Praticar a implementação e manipulação de estruturas de dados do tipo **Lista Linear Simplesmente Encadeada**, utilizando um TAD (Tipo Abstrato de Dados).

## Enunciado

Especifique e implemente um Tipo Abstrato de Dados chamado `TListaEncadeada`, que manipule dados do tipo inteiro e ofereça os seguintes serviços:

- Exibir todos os elementos armazenados na lista;
- Esvaziar completamente a lista;
- Inserir um novo elemento no início da lista;
- Inserir um novo elemento no final da lista;
- Inserir um novo elemento em uma posição específica da lista;
- Remover um elemento específico da lista pelo valor (todas as ocorrências do valor devem ser removidas);
- Remover um elemento específico da lista pela posição (a função deve retornar o valor removido);
- Buscar um elemento na lista pelo valor. A função deve retornar a posição do elemento na lista. Caso ele não exista, retornar o valor `-1`;
- Obter o tamanho atual da lista.

A implementação deve utilizar ponteiros para criar e manipular os nós da lista encadeada.

## Comandos

O programa principal (`main.c`) deve ler comandos via entrada padrão (teclado) para manipular a lista.

Os comandos possíveis são:

| Comando | Descrição |
| --- | --- |
| `-s` | Exibe o estado atual da lista. |
| `-c` | Esvazia a lista. |
| `-ii X` | Insere o valor `X` no início da lista. |
| `-if X` | Insere o valor `X` no final da lista. |
| `-i X Y` | Insere o valor `X` na posição `Y` da lista (a posição inicial é 1). |
| `-r X` | Remove o elemento `X` da lista. |
| `-rp X` | Remove o elemento presente na posição `X` da lista. |
| `-b X` | Busca o elemento `X` na lista e informa sua posição. |
| `-t` | Exibe o tamanho atual da lista. |
| `-f` | Finaliza a execução do programa. |

## Exemplo de uso

### Entrada de dados

```text
-ii 10 -if 20 -if 30 -s
-b 20
-i 25 3 -s
-r 10 -s
-rp 2 -s
-t
-c -s
-f
```

### Saída esperada

```text
Lista: 10 20 30
Elemento 20 encontrado na posição 2.
Lista: 10 20 25 30
Lista: 20 25 30
Lista: 20 30
Tamanho da lista: 2
Lista vazia.
```

## Formatos aceitos

- ZIP

### Requisitos do arquivo ZIP

Para ser corretamente corrigido, o código deve ser entregue em um único arquivo ZIP contendo um `Makefile` na raiz.

O `Makefile` deve:

- conter apenas o comando de compilação na diretiva `all` — será executado `make all` para compilar o código;
- conter apenas o comando de execução na diretiva `run` — será executado `make run` para executar o código.

## Casos de teste

### Entrada 1

```text
-ii 10 -if 20 -if 30 -s
-b 20
-i 25 3 -s
-r 10 -s
-rp 2 -s
-t
-c -s
-f
```

### Saída esperada 1

```text
Lista: 10 20 30
Elemento 20 encontrado na posição 2.
Lista: 10 20 25 30
Lista: 20 25 30
Lista: 20 30
Tamanho da lista: 2
Lista vazia.
```

### Entrada 2

```text
-ii 5 -if 15 -if 25 -if 35 -if 45 -s
-b 25
-b 50
-i 10 2 -s
-i 20 4 -s
-r 15 -s
-r 45 -s
-rp 3 -s
-rp 1 -s
-b 5
-b 100
-t
-i 30 2 -s
-i 40 3 -s
-i 50 4 -s
-i 60 5 -s
-s
-rp 2 -s
-rp 4 -s
-b 40
-b 60
-t
-c -s
-ii 99 -if 88 -i 77 2 -i 66 3 -i 55 4 -s
-b 99
-b 88
-b 77
-b 66
-b 55
-r 77 -s
-r 55 -s
-rp 2 -s
-rp 1 -s
-b 88
-t
-c -s
-f
```

### Saída esperada 2

```text
Lista: 5 15 25 35 45
Elemento 25 encontrado na posição 3.
Elemento 50 não encontrado.
Lista: 5 10 15 25 35 45
Lista: 5 10 15 20 25 35 45
Lista: 5 10 20 25 35 45
Lista: 5 10 20 25 35
Lista: 5 10 25 35
Lista: 10 25 35
Elemento 5 não encontrado.
Elemento 100 não encontrado.
Tamanho da lista: 3
Lista: 10 30 25 35
Lista: 10 30 40 25 35
Lista: 10 30 40 50 25 35
Lista: 10 30 40 50 60 25 35
Lista: 10 30 40 50 60 25 35
Lista: 10 40 50 60 25 35
Lista: 10 40 50 25 35
Elemento 40 encontrado na posição 2.
Elemento 60 não encontrado.
Tamanho da lista: 5
Lista vazia.
Lista: 99 77 66 55 88
Elemento 99 encontrado na posição 1.
Elemento 88 encontrado na posição 5.
Elemento 77 encontrado na posição 2.
Elemento 66 encontrado na posição 3.
Elemento 55 encontrado na posição 4.
Lista: 99 66 55 88
Lista: 99 66 88
Lista: 99 88
Lista: 88
Elemento 88 encontrado na posição 1.
Tamanho da lista: 1
Lista vazia.
```

### Entrada 3

```text
-s -f
```

### Saída esperada 3

```text
Lista vazia.
```

### Entrada 4

```text
-ii 10 -if 20 -if 30 -if 10 -if 40 -if 10 -if 50 -s
-r 10 -s
-b 10
-b 20
-b 30
-b 40
-b 50
-t
-s
-f
```

### Saída esperada 4

```text
Lista: 10 20 30 10 40 10 50
Lista: 20 30 40 50
Elemento 10 não encontrado.
Elemento 20 encontrado na posição 1.
Elemento 30 encontrado na posição 2.
Elemento 40 encontrado na posição 3.
Elemento 50 encontrado na posição 4.
Tamanho da lista: 4
Lista: 20 30 40 50
```
