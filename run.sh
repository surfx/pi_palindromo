#!/bin/bash

# $1 - nome arquivo para analisar
# $2 - 0/1 excluir arquivo de controle

g++ main.cpp -o executaveis/main
cd executaveis
./main $1 $2