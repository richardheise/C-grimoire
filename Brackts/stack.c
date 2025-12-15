#include "stack.h"
#include <string.h>
#include <stdlib.h>

void stack_init (stack_t *p, int element_size) {
	p->top = -1;
    p->element_size = element_size;
}

int stack_is_empty (stack_t p) {
	if (p.top == -1)
		return 1;
	return 0;
}

int stack_push (void *x, stack_t *p) {
	if (p->top == MAX-1)
		return 0;
	p->top = p->top + 1;
    p->v[p->top] = malloc(p->element_size);
	memcpy(p->v[p->top], x, p->element_size);
	return 1;
}

int stack_pop (void *t, stack_t *p) {
	if (stack_is_empty(*p))
		return 0;
    memcpy(t, p->v[p->top], p->element_size);
    free(p->v[p->top]);
	p->top = p->top - 1;
  return 1;
}

int stack_top (void *t, stack_t p) {
	if (stack_is_empty(p))
		return 0;
	memcpy(t, p.v[p.top], p.element_size);
	return 1;
}
int stack_size(stack_t p) {
	return (p.top+1);
}
