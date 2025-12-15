#ifndef STACK_H
#define STACK_H

#define MAX 50

typedef struct stack_t {
   int top;
   int element_size;
   void* v[MAX];
} stack_t;

void stack_init (stack_t *p, int element_size);
int stack_is_empty (stack_t p);
int stack_push (void *x, stack_t *p);
int stack_pop (void *t, stack_t *p);
int stack_top (void *t, stack_t p);
int stack_size(stack_t p);

#endif
