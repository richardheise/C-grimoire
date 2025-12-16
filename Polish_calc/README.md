# Calculadora Polonesa Inversa

Esta é uma implementação de uma calculadora que utiliza a notação polonesa inversa (RPN).

## O que é Notação Polonesa Inversa?

Na notação polonesa inversa, os operandos precedem os operadores. Por exemplo, a expressão `2 + 2` se torna `2 2 +`.

## Arquivos

*   `polish.c`: O arquivo principal que contém a lógica da calculadora.
*   `stack.c`: Implementação de uma estrutura de dados de pilha.
*   `stack.h`: Arquivo de cabeçalho para a pilha.
*   `Makefile`: Arquivo para compilar o projeto.
*   `calculator`: O executável da calculadora.
*   `tests/`: Diretório com os testes.
*   `run_tests.sh`: Script para rodar os testes.
*   `.gitignore`: Arquivo para ignorar arquivos do git.

## Como Compilar e Rodar

Para compilar o projeto, use o comando:

```bash
make
```

Para rodar a calculadora:

```bash
./calculator
```

## Como Rodar os Testes

Para rodar os testes, use o seguinte comando:

```bash
./run_tests.sh
```
