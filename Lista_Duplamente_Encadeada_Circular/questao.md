# Exercício: Implementando o Tipo Abstrato Lista Duplamente Encadeada Circular

## Objetivo

Praticar a implementação e manipulação de estruturas de dados do tipo **Lista Linear Duplamente Encadeada Circular**, utilizando um TAD (Tipo Abstrato de Dados).

## Enunciado

Especifique e implemente um Tipo Abstrato de Dados chamado `TListaDupCirc`, que manipule dados do tipo `int` e ofereça os seguintes serviços:

- Exibir todos os elementos armazenados na lista;
- Esvaziar completamente a lista;
- Inserir um novo elemento no início da lista;
- Inserir um novo elemento no final da lista;
- Inserir um novo elemento em posição específica da lista;
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
| `-b X` | Busca o elemento `X` na lista e informa a posição do elemento. |
| `-t` | Exibe o tamanho atual da lista. |
| `-f` | Finaliza a execução do programa. |

## Exemplo de uso

### Entrada de dados

```text
-ii -10 -if -20 -if -30 -s
-b -20
-i -25 3 -s
-r -10 -s
-rp 2 -s
-t
-c -s
-f
```

### Saída esperada

```text
Lista: -10 -20 -30
Posição do elemento -20: 2
Lista: -10 -20 -25 -30
Lista: -20 -25 -30
Lista: -20 -30
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
-ii -10 -if -20 -if -30 -s
-b -20
-i -25 3 -s
-r -10 -s
-rp 2 -s
-t
-c -s
-f
```

### Saída esperada 1

```text
Lista: -10 -20 -30
Posição do elemento -20: 2
Lista: -10 -20 -25 -30
Lista: -20 -25 -30
Lista: -20 -30
Tamanho da lista: 2
Lista vazia.
```

### Entrada 2

```text
-ii -10 -if -20 -if -30 -if -40 -if -50 -s
-b -30
-b -99
-i -15 2 -s
-i -25 4 -s
-r -20 -s
-r -50 -s
-rp 3 -s
-rp 1 -s
-b -10
-b -100
-t
-i -35 2 -s
-i -45 3 -s
-i -55 4 -s
-i -65 5 -s
-s
-rp 2 -s
-rp 4 -s
-b -45
-b -65
-t
-c -s
-ii -70 -if -80 -i -85 2 -i -90 3 -i -95 4 -s
-b -70
-b -80
-b -85
-b -90
-b -95
-r -85 -s
-r -95 -s
-rp 2 -s
-rp 1 -s
-b -80
-t
-c -s
-f
```

### Saída esperada 2

```text
Lista: -10 -20 -30 -40 -50
Posição do elemento -30: 3
Posição do elemento -99: -1
Lista: -10 -15 -20 -30 -40 -50
Lista: -10 -15 -20 -25 -30 -40 -50
Lista: -10 -15 -25 -30 -40 -50
Lista: -10 -15 -25 -30 -40
Lista: -10 -15 -30 -40
Lista: -15 -30 -40
Posição do elemento -10: -1
Posição do elemento -100: -1
Tamanho da lista: 3
Lista: -15 -35 -30 -40
Lista: -15 -35 -45 -30 -40
Lista: -15 -35 -45 -55 -30 -40
Lista: -15 -35 -45 -55 -65 -30 -40
Lista: -15 -35 -45 -55 -65 -30 -40
Lista: -15 -45 -55 -65 -30 -40
Lista: -15 -45 -55 -30 -40
Posição do elemento -45: 2
Posição do elemento -65: -1
Tamanho da lista: 5
Lista vazia
Lista: -70 -85 -90 -95 -80
Posição do elemento -70: 1
Posição do elemento -80: 5
Posição do elemento -85: 2
Posição do elemento -90: 3
Posição do elemento -95: 4
Lista: -70 -90 -95 -80
Lista: -70 -90 -80
Lista: -70 -80
Lista: -80
Posição do elemento -80: 1
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
-ii -10 -if -20 -if -30 -if -10 -if -40 -if -10 -if -50 -s
-r -10 -s
-b -10
-b -20
-b -30
-b -40
-b -50
-t
-s
-ii -60 -if -70 -i -50 2 -i -30 3 -i -90 4 -s
-f
```

### Saída esperada 4

```text
Lista: -10 -20 -30 -10 -40 -10 -50
Lista: -20 -30 -40 -50
Posição do elemento -10: -1
Posição do elemento -20: 1
Posição do elemento -30: 2
Posição do elemento -40: 3
Posição do elemento -50: 4
Tamanho da lista: 4
Lista: -20 -30 -40 -50
Lista: -60 -50 -30 -90 -20 -30 -40 -50 -70.
```
