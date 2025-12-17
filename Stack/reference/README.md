
# Brackts

This project contains a C implementation of a generic stack used to check for balanced brackets in a given input.

## Como Executar e Testar

Para compilar e executar o código, siga estes passos:

1.  Use o comando `make` para compilar o projeto.
2.  Execute o programa com `./main` e insira uma sequência de brackets.
3.  Para finalizar a entrada, digite `0`.

O programa exibirá `SIM` se os brackets estiverem balanceados e `NAO` caso contrário.

### Script de Teste

O projeto inclui um script de automação para os testes. Para usá-lo, execute:

```bash
./run_tests.sh
```

Este script irá automaticamente limpar, compilar e verificar o programa contra todos os casos de teste presentes na pasta `tests/`.

## Descrição dos Arquivos

*   `main.c`: Arquivo principal com a lógica para ler a entrada e verificar o balanceamento de brackets.
*   `stack.h`: Arquivo de cabeçalho (header) para a implementação da pilha genérica. Os identificadores da API da pilha estão em inglês (ex: `stack_t`, `stack_push`, `stack_is_empty`).
*   `stack.c`: Arquivo de código-fonte para a pilha genérica.
*   `Makefile`: Makefile para compilar o projeto.
*   `run_tests.sh`: Script de teste automatizado.
*   `tests/`: Diretório contendo os arquivos de caso de teste (`.in`) e seus respectivos resultados esperados (`.res`).

