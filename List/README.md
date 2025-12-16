# Lista Encadeada em C

Este repositório contém uma implementação de uma lista encadeada em C, com funções para criar, destruir, inserir, remover e manipular listas.

## Arquivos

*   `list.h`: Arquivo de cabeçalho com as definições de tipo e protótipos de função para a lista encadeada.
*   `list.c`: Implementação das funções da lista encadeada.
*   `test.c`: Programa de teste que demonstra o uso das funções da lista encadeada.
*   `Makefile`: Arquivo para compilar o projeto.
*   `.gitignore`: Arquivo para ignorar arquivos gerados pela compilação e outros arquivos desnecessários.

## Como usar

Para compilar o projeto, execute o seguinte comando:

```bash
make
```

Isso irá gerar um executável chamado `test`. Para executá-lo, use o seguinte comando:

```bash
./test
```

O programa de teste irá executar uma série de operações na lista encadeada e imprimir os resultados na tela.

Para limpar os arquivos gerados pela compilação, execute o seguinte comando:

```bash
make clean
```

## Testando

Este repositório também inclui um script para testar a saída do programa `test`. O script `run_tests.sh` executa o programa `test`, salva a saída em um arquivo `output.txt` e a compara com o arquivo `reference.txt`.

Para executar os testes, use o seguinte comando:

```bash
./run_tests.sh
```
