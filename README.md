# C-Grimoire

Este repositório é uma coleção de projetos e implementações de estruturas de dados e algoritmos em C. Cada subdiretório contém um projeto distinto com seu próprio conjunto de arquivos, testes e documentação.

## Conteúdo do Repositório

### 1. `Brackts/`

Este diretório contém uma implementação de uma pilha genérica em C, utilizada para verificar o balanceamento de parênteses (`[]`), chaves (`{}`) e colchetes (`()`) em uma expressão de entrada.

- **`main.c`**: Lógica principal que lê a entrada e utiliza a pilha para checar o balanceamento.
- **`stack.c` / `stack.h`**: Implementação da estrutura de dados de pilha.
- **`run_tests.sh`**: Script para compilar e executar um conjunto de testes automatizados.

### 2. `List/`

Este projeto é uma implementação de uma lista encadeada em C, com funções para criar, destruir, inserir, remover e manipular elementos.

- **`list.c` / `list.h`**: Implementação da lista encadeada.
- **`test.c`**: Programa de exemplo que demonstra o uso das funções da lista.
- **`run_tests.sh`**: Script que executa o programa de teste e compara a saída com um resultado de referência (`reference.txt`).

### 3. `Polish_calc/`

Aqui se encontra uma calculadora que opera com base na **Notação Polonesa Inversa (RPN)**. Em vez de `2 + 2`, a expressão é escrita como `2 2 +`.

- **`polish.c`**: Lógica principal da calculadora RPN.
- **`stack.c` / `stack.h`**: Implementação de pilha para auxiliar nos cálculos.
- **`run_tests.sh`**: Script para rodar os testes automatizados.

### 4. `Sorting_analysis/`

Este diretório contém implementações de vários algoritmos de ordenação e um programa para analisar e comparar o desempenho entre eles.

- **`sorting_lib.c` / `sorting_lib.h`**: Biblioteca com as implementações dos algoritmos de ordenação, como `Insertion Sort`, `Quick Sort` e `Merge Sort`.
- **`analysis.c`**: Programa principal que executa as análises de desempenho, medindo o tempo de execução dos algoritmos em diferentes cenários (vetores aleatórios, ordenados, etc.).
- **`Makefile`**: Facilita a compilação do projeto de análise.