Exercício: Implementando o Tipo Abstrato Lista Duplamente Encadeada
Objetivo
Praticar a implementação e manipulação de estruturas de dados do tipo Lista Linear Duplamente Encadeada, utilizando um TAD (Tipo Abstrato de Dados).

Enunciado
Especifique e implemente um Tipo Abstrato de Dados chamado TListaDup, que manipule dados do tipo char e ofereça os seguintes serviços:

Exibir todos os elementos armazenados na lista;
Esvaziar completamente a lista;
Inserir um novo elemento no início da lista;
Inserir um novo elemento no final da lista;
Inserir um novo elemento em posição específica da lista;
Remover um elemento específico da lista pelo valor (obs: todas as ocorrências do valor devem ser removidas);
Remover um elemento específico da lista pela posição (obs: a função deve retornar o valor removido);
Buscar um elemento na lista pelo valor. A função deve retornar a posição do elemento na lista (obs: caso ele não exista, retornar o valor -1);
Obter o tamanho atual da lista.
A implementação deve utilizar ponteiros para criar e manipular os nós da lista encadeada.

O programa principal (main.c) deve ler comandos via entrada padrão (teclado) para manipular a lista. Os comandos possíveis são:

-s → Exibe o estado atual da lista.
-c → Esvazia a lista.
-ii X → Insere o valor X no início da lista.
-if X → Insere o valor X no final da lista.
-i X Y → Insere o valor X na posição Y da lista (posição inicial inicia com 1).
-r X → Remove o elemento X da lista.
-rp X → Remove o elemento presente na posição X da lista.
-b X → Busca o elemento X na lista e informa a posição do elemento.
-t → Exibe o tamanho atual da lista.
-f → Finaliza a execução do programa.
Exemplo de Uso
Entrada de dados
-ii A -if B -if C -s
-b B
-i D 3 -s
-r A -s
-rp 2 -s
-t
-c -s
-f
Saída esperada
Lista: A B C
Posição do elemento B: 2
Lista: A B D C
Lista: B D C
Lista: B C
Tamanho da lista: 2
Lista vazia.
Formatos aceitos: zip

Atenção: Para ser corretamente corrigido, seu código, se entregue em um único arquivo ZIP/Makefile:
deve obrigatoriamente ter um arquivo Makefile na raiz do arquivo ZIP;
deve conter apenas o comando de compilação na diretiva all — será executado make all para compilar o código;
deve conter apenas o comando de execução na diretiva run — será executado make run para executar o código.
Entrada 1
-ii A -if B -if C -s
-b B
-i D 3 -s
-r A -s
-rp 2 -s
-t
-c -s
-f
Saída esperada 1
Lista: A B C
Posição do elemento B: 2
Lista: A B D C
Lista: B D C
Lista: B C
Tamanho da lista: 2
Lista vazia.
Entrada 2
-ii A -if B -if C -if D -if E -s
-b C
-b Z
-i F 2 -s
-i G 4 -s
-r B -s
-r E -s
-rp 3 -s
-rp 1 -s
-b A
-b X
-t
-i H 2 -s
-i I 3 -s
-i J 4 -s
-i K 5 -s
-s
-rp 2 -s
-rp 4 -s
-b I
-b K
-t
-c -s
-ii M -if N -i O 2 -i P 3 -i Q 4 -s
-b M
-b N
-b O
-b P
-b Q
-r O -s
-r Q -s
-rp 2 -s
-rp 1 -s
-b N
-t
-c -s
-f
Saída esperada 2
Lista: A B C D E
Posição do elemento C: 3
Posição do elemento Z: -1
Lista: A F B C D E
Lista: A F B G C D E
Lista: A F G C D E
Lista: A F G C D
Lista: A F C D
Lista: F C D
Posição do elemento A: -1
Posição do elemento X: -1
Tamanho da lista: 3
Lista: F H C D
Lista: F H I C D
Lista: F H I J C D
Lista: F H I J K C D
Lista: F H I J K C D
Lista: F I J K C D
Lista: F I J C D
Posição do elemento I: 2
Posição do elemento K: -1
Tamanho da lista: 5
Lista vazia
Lista: M O P Q N
Posição do elemento M: 1
Posição do elemento N: 5
Posição do elemento O: 2
Posição do elemento P: 3
Posição do elemento Q: 4
Lista: M P Q N
Lista: M P N
Lista: M N
Lista: N
Posição do elemento N: 1
Tamanho da lista: 1
Lista vazia.
Entrada 3
-s -f
Saída esperada 3
Lista vazia.
Entrada 4
-ii A -if B -if C -if A -if D -if A -if E -s
-r A -s
-b A
-b B
-b C
-b D
-b E
-t
-s
-c
-ii N -if O -i E 2 -i C 3 -i I 4 -s
-f
Saída esperada 4
Lista: A B C A D A E
Lista: B C D E
Posição do elemento A: -1
Posição do elemento B: 1
Posição do elemento C: 2
Posição do elemento D: 3
Posição do elemento E: 4
Tamanho da lista: 4
Lista: B C D E
Lista: N E C I O.