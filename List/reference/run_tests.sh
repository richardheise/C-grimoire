#!/bin/bash

./test > output.txt

if diff -q reference.txt output.txt > /dev/null; then
    echo "Testes passaram!"
else
    echo "Testes falharam!"
fi
