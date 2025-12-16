#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"
#define MAX 50
	

int is_valid_number (char v[]) { /*verifica se a string digitada é composta somente por números. Retorna 1 se sim e 0 caso contrário.*/
	int i = 0;
	if (v[i] == '-') {
		if (strlen(v) == 1)
			return 0;
		i = 1;
	}
	while (v[i] != '\0') { 
		if (!isdigit(v[i]) && v[i] != '.' && v[i] != 'e')
			return 0;
		i++;
	}
	return 1;   
}

int is_valid_operation (char v[]) { /*verifica se a operação é valida -- soma, subtração, multiplicação e divisão -- e retorna 1 se sim e 0 se não*/
	if (v[0] == '+' || v[0] == '-' || v[0] == '*' || v[0] == '/')
		return 1;
	return 0;
}

float perform_operation (char v[], float x, float y) { /*faz a operação respectiva a entrada. O vetor só tem uma posição pois as operações binárias são só um char*/
	if (v[0] == '+')
		return (x+y);
	if (v[0] == '-')
		return (x-y);
	if (v[0] == '*')
		return (x*y);
	if (v[0] == '/')
		return (x/y);
	return 0; /*o compilador reclama se a função do tipo float não retornar valor, mesmo que seja impossível chegar nesse valor*/
} 

int main() {
	stack_t stack;             /*inicializando as variaveis*/
	char input[MAX];           /*vetor de entrada*/
	float operand1 = 0;         /*primeiro operando*/
	float operand2 = 0;         /*segundo operando*/
	float result = 0;              /*variavel de resposta*/
	initialize_stack(&stack);
	printf("Pressiona q para sair\n");
	printf("Digite os operandos e operações separadas por espaços: ");
	scanf("%s", input);
	while (input[0] != 'q') { 
		if (is_valid_number(input)) {                                       
			push(atof(input), &stack);                     /*empilha o valor da entrada validado*/
		} 
		else if (is_valid_operation(input) && strlen(input) == 1) {   /*condição feita para evitar entradas do tipo +5 -- consideradas ambíguas --, sem espaço*/
			if (is_stack_empty(stack)) 
				printf("Erro. Faltam operandos.\n");
			else {
				peek(&operand2, stack);							   /*operando2 recebe o topo*/
				pop(&stack);		
				if (is_stack_empty(stack)) {
					printf("Erro. Faltam operandos.\n");
					break;
				}
				peek(&operand1, stack);                               /*operando1 recebe o topo*/
				pop(&stack);
				push(perform_operation(input, operand1, operand2), &stack); /*verifica a operação digitada e a empilha após ser realizada*/
			}                                                                   /*consideração: a utilização de topo() e depois desempilha() somente*/	
		}																		/*para reduzir o tamanho da pilha foi necessária para corrigir bugs*/
		else 
			printf("Erro. digito inválido\n");
		scanf(" %s", input);
	}
	peek(&result, stack);
	printf("%f\n", result);	
	return 0;
} 
