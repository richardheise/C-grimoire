#!/bin/bash

# Cores para facilitar a leitura da saída
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # Sem cor

# 1. Limpa e compila o projeto
echo "Cleaning and compiling the project..."
make clean > /dev/null 2>&1
make

# Verifica se a compilação foi bem-sucedida
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed. Aborting tests.${NC}"
    exit 1
fi

if [ ! -f main ]; then
    echo -e "${RED}'main' executable not found after compilation. Aborting.${NC}"
    exit 1
fi

echo "Compilation successful."
echo "-------------------------------------"
echo "Starting tests..."

# 2. Itera sobre os testes, executa e compara os resultados
for test_in in tests/*.in; do
    # Deriva o nome do arquivo de resultado (gabarito)
    base_name=$(basename "$test_in" .in)
    test_res="tests/${base_name}.res"

    echo -n "Running ${base_name}... "

    # Verifica se o arquivo de resultado existe
    if [ ! -f "$test_res" ]; then
        echo "Warning: Result file ${test_res} not found. Skipping test."
        continue
    fi

    # Executa o programa e captura a saída
    program_output=$(./main < "$test_in")
    
    # Lê a saída esperada do arquivo .res
    expected_output=$(cat "$test_res")

    # Compara a saída do programa com o resultado esperado
    if [ "$program_output" == "$expected_output" ]; then
        echo -e "${GREEN}PASS${NC}"
    else
        echo -e "${RED}FAIL${NC}"
        echo "  - Expected: '$expected_output'"
        echo "  - Got:      '$program_output'"
    fi
done

echo "-------------------------------------"
echo "Tests finished."
