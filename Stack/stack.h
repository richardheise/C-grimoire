// GRR20191053 Richard Fernando Heise Ferreira 
// Definição e operações em uma pilha genérica.

#ifndef STACK_H
#define STACK_H

#define MAX 50

//------------------------------------------------------------------------------
// estrutura de uma pilha genérica.
typedef struct stack_t {
   int top;
   int element_size;
   void* v[MAX];
} stack_t;

//------------------------------------------------------------------------------
// Inicializa uma pilha.
void stack_init(stack_t *p, int element_size);

//------------------------------------------------------------------------------
// Verifica se a pilha está vazia.
// Retorno: 1 se vazia, 0 se não.
int stack_is_empty(stack_t p);

//------------------------------------------------------------------------------
// Insere um elemento no topo da pilha.
// Retorno: 1 se sucesso, 0 se falha.
int stack_push(void *x, stack_t *p);

//------------------------------------------------------------------------------
// Remove um elemento do topo da pilha.
// Retorno: 1 se sucesso, 0 se falha.
int stack_pop(void *t, stack_t *p);

//------------------------------------------------------------------------------
// Retorna o elemento no topo da pilha sem remover.
// Retorno: 1 se sucesso, 0 se falha.
int stack_top(void *t, stack_t p);

//------------------------------------------------------------------------------
// Retorna o número de elementos na pilha.
int stack_size(stack_t p);

#endif
