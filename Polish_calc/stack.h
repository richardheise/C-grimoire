#define MAX 50

typedef struct stack_t {
   int top;
   float values[MAX];
} stack_t; 
 
void initialize_stack (stack_t *p); /*inicializa pilha com -1 no topo*/

int is_stack_empty (stack_t p); /*se a pilha eh vazia retorna 1, caso contrario retorna 0*/

int push (float x, stack_t *p);  /*empilha o elemento x no topo, se funcionar retorna 1, se não funcionar -- pilha cheia -- retorna 0*/

int pop (stack_t *p); /*desempilha o elemento do topo, se funcionar retorna 1, caso contrario -- pilha vazia -- retorna 0*/

int peek (float *t, stack_t p); /*retorna o elemento do topo, se funcionar retorna 1, caso contrário -- pilha vazia -- retorna 0*/

int stack_size(stack_t p); /*retorna o tamanho da pilha*/
