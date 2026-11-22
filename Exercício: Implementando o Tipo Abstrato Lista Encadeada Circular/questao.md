# Exercício: Implementando o Tipo Abstrato Lista Encadeada Circular

## Objetivo

Praticar a implementação e manipulação de estruturas de dados do tipo Lista Linear Simplesmente Encadeada Circular, utilizando um TAD (Tipo Abstrato de Dados).

## Enunciado

Especifique e implemente um Tipo Abstrato de Dados chamado TListaEncadeadaCirc, que manipule dados do tipo float e ofereça os seguintes serviços:

- Exibir todos os elementos armazenados na lista;
- Esvaziar completamente a lista;
- Inserir um novo elemento no início da lista;
- Inserir um novo elemento no final da lista;
- Inserir um novo elemento em posição específica da lista;
- Remover um elemento específico da lista pelo valor (obs.: todas as ocorrências do valor devem ser removidas);
- Remover um elemento específico da lista pela posição (obs.: a função deve retornar o valor removido);
- Buscar um elemento na lista pelo valor. A função deve retornar a posição do elemento na lista (obs.: caso ele não exista, retornar o valor `-1`);
- Obter o tamanho atual da lista.

A implementação deve utilizar ponteiros para criar e manipular os nós da lista encadeada.

O programa principal (main.c) deve ler comandos via entrada padrão (teclado) para manipular a lista. Os comandos possíveis são:

- `-s` → Exibe o estado atual da lista.
- `-c` → Esvazia a lista.
- `-ii X` → Insere o valor X no início da lista.
- `-if X` → Insere o valor X no final da lista.
- `-i X Y` → Insere o valor X na posição Y da lista (posição inicial inicia com 1).
- `-r X` → Remove o elemento X da lista.
- `-rp X` → Remove o elemento presente na posição X da lista.
- `-b X` → Busca o elemento X na lista e informa a posição do elemento.
- `-t` → Exibe o tamanho atual da lista.
- `-f` → Finaliza a execução do programa.

## Exemplo de Uso

### Entrada de dados

```text
-ii 1.1 -s
-if 2.2 -s
-i 3.3 2 -s
-b 2.2
-b 4.4
-r 1.1 -s
-rp 2 -s
-t
-c -s
-f
```

### Saída esperada

```text
Lista: 1.1
Lista: 1.1 2.2
Lista: 1.1 3.3 2.2
Elemento 2.2 encontrado na posição 3.
Elemento 4.4 não encontrado.
Lista: 3.3 2.2
Lista: 3.3
Tamanho da lista: 1
Lista vazia.
```

## Formatos aceitos

`zip`

## Instruções para entrega

Para ser corretamente corrigido, seu código, se entregue em um único arquivo ZIP/Makefile:

- deve obrigatoriamente ter um arquivo `Makefile` na raiz do arquivo ZIP;
- deve conter apenas o comando de compilação na diretiva `all` — será executado `make all` para compilar o código;
- deve conter apenas o comando de execução na diretiva `run` — será executado `make run` para executar o código.

## Entrada 1

```text
-ii 1.1 -s
-if 2.2 -s
-i 3.3 2 -s
-b 2.2
-b 4.4
-r 1.1 -s
-rp 2 -s
-t
-c -s
-f
```

### Saída esperada 1

```text
Lista: 1.1
Lista: 1.1 2.2
Lista: 1.1 3.3 2.2
Elemento 2.2 encontrado na posição 3.
Elemento 4.4 não encontrado.
Lista: 3.3 2.2
Lista: 3.3
Tamanho da lista: 1
Lista vazia.
```

## Entrada 2

```text
-ii 10.1 -if 20.2 -if 30.3 -if 40.4 -if 50.5 -s
-b 30.3
-b 60.6
-i 15.5 2 -s
-i 25.5 4 -s
-i 35.5 6 -s
-r 20.2 -s
-r 35.5 -s
-rp 3 -s
-rp 5 -s
-b 10.1
-b 50.5
-t
-c -s
-ii 5.5 -if 15.5 -i 10.1 2 -i 12.2 3 -i 13.3 4 -s
-b 5.5
-b 15.5
-b 10.1
-b 12.2
-b 13.3
-r 10.1 -s
-r 13.3 -s
-rp 2 -s
-rp 1 -s
-b 12.2
-t
-c -s
-ii 99.9 -if 88.8 -i 77.7 2 -i 66.6 3 -i 55.5 4 -s
-r 77.7 -s
-rp 2 -s
-f
```

### Saída esperada 2

```text
Lista: 10.1 20.2 30.3 40.4 50.5
Elemento 30.3 encontrado na posição 3.
Elemento 60.6 não encontrado.
Lista: 10.1 15.5 20.2 30.3 40.4 50.5
Lista: 10.1 15.5 20.2 25.5 30.3 40.4 50.5
Lista: 10.1 15.5 20.2 25.5 30.3 35.5 40.4 50.5
Lista: 10.1 15.5 25.5 30.3 35.5 40.4 50.5
Lista: 10.1 15.5 25.5 30.3 40.4 50.5
Lista: 10.1 15.5 30.3 40.4 50.5
Lista: 10.1 15.5 30.3 40.4
Elemento 10.1 encontrado na posição 1.
Elemento 50.5 não encontrado.
Tamanho da lista: 4
Lista vazia
Lista: 5.5 10.1 12.2 13.3 15.5
Elemento 5.5 encontrado na posição 1.
Elemento 15.5 encontrado na posição 5.
Elemento 10.1 encontrado na posição 2.
Elemento 12.2 encontrado na posição 3.
Elemento 13.3 encontrado na posição 4.
Lista: 5.5 12.2 13.3 15.5
Lista: 5.5 12.2 15.5
Lista: 5.5 15.5
Lista: 15.5
Elemento 12.2 não encontrado.
Tamanho da lista: 1
Lista vazia
Lista: 99.9 77.7 66.6 55.5 88.8
Lista: 99.9 66.6 55.5 88.8
Lista: 99.9 55.5 88.8.
```

## Entrada 3

```text
-s -f
```

### Saída esperada 3

```text
Lista vazia.
```

## Entrada 4

```text
-ii 5.5 -if 10.1 -if 5.5 -if 20.2 -if 5.5 -if 30.3 -if 5.5 -s
-r 5.5 -s
-i 40.4 2 -i 50.5 4 -s
-r 20.2 -s
-r 30.3 -s
-i 60.6 3 -s
-r 10.1 -s
-rp 2 -s
-r 50.5 -s
-t
-c -s
-f
```

### Saída esperada 4

```text
Lista: 5.5 10.1 5.5 20.2 5.5 30.3 5.5
Lista: 10.1 20.2 30.3
Lista: 10.1 40.4 20.2 50.5 30.3
Lista: 10.1 40.4 50.5 30.3
Lista: 10.1 40.4 50.5
Lista: 10.1 40.4 60.6 50.5
Lista: 40.4 60.6 50.5
Lista: 40.4 50.5
Lista: 40.4
Tamanho da lista: 1
Lista vazia.
```