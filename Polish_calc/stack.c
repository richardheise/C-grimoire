#include "stack.h"

void initialize_stack (stack_t *p) {
	p->top = -1;
}

int is_stack_empty (stack_t p) {
	if (p.top == -1) 
		return 1;
	return 0;
}

int push (float x, stack_t *p) {
	if (p->top == MAX-1) 
		return 0;
	p->top = p->top + 1;
	p->values[p->top] = x;
	return 1;
}

int pop (stack_t *p) {
	if (is_stack_empty(*p)) 
		return 0;
	p->top = p->top - 1;
  return 1;
}

int peek (float *t, stack_t p) {
	if (is_stack_empty(p))
		return 0;
	*t = (p.values[p.top]);
	return 1;
}
int stack_size(stack_t p) {
	return (p.top+1);
}
