# Estrutura de Arquivos de Algoritmos de Ordenação

Este repositório contém uma coleção de algoritmos de ordenação em C, juntamente com um programa para analisar seu desempenho.

## Estrutura de Pastas e Arquivos

- **`analysis.c`**: Este arquivo contém o programa principal (`main`) que é usado para analisar e comparar o desempenho de diferentes algoritmos de ordenação. Ele mede o tempo de execução de cada algoritmo em vetores gerados aleatoriamente e previamente ordenados, imprimindo o tempo médio de execução para cada caso.

- **`sorting_lib.h`**: O arquivo de cabeçalho que define as assinaturas de todas as funções de ordenação e de utilitários. As funções declaradas aqui incluem:
  - `generate_random_vector`: Gera um vetor de números aleatórios.
  - `generate_sorted_vector`: Gera um vetor ordenado de números.
  - `shuffle_vector`: Embaralha os elementos de um vetor.
  - `print_vector`: Imprime os elementos de um vetor.
  - `swap`: Troca dois elementos de posição.
  - Funções de ordenação: `insertion_sort`, `quick_sort`, `merge_sort` e suas variações.

- **`sorting_lib.c`**: A implementação das funções declaradas em `sorting_lib.h`. Este arquivo contém a lógica para os algoritmos de ordenação, como:
  - **`insertion_sort`**: Ordenação por inserção.
  - **`quick_sort`**: Ordenação rápida (Quick Sort).
  - **`merge_sort`**: Ordenação por intercalação (Merge Sort).
  - Variações do Quick Sort e Merge Sort para otimização e análise de desempenho.

- **`.vscode/`**: Contém configurações específicas do editor Visual Studio Code.

## Como Compilar e Executar

Para compilar e executar o programa de análise, você pode usar um compilador C como o `gcc`.

### Compilando os arquivos

Você precisa compilar ambos os arquivos `.c` juntos. Abra o terminal e execute o seguinte comando:

```bash
gcc analysis.c sorting_lib.c -o analysis
```

Este comando compila os arquivos `analysis.c` e `sorting_lib.c` e cria um arquivo executável chamado `analysis`.

### Executando o programa

Após a compilação, você pode executar o programa com o seguinte comando:

```bash
./analysis
```

O programa irá executar os algoritmos de ordenação, medir seus tempos de execução e imprimir os resultados no terminal.
