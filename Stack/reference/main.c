#include <stdio.h>
#include <stdlib.h>
#include "stack.h" // This will be updated to "stack.h" later

int get_matching_opener (char t, char *x) {
  	if ((t != ')') && (t != '}') && (t != ']'))
	  return 0;
  	if (t == ')')
	  *x = '(';
	else if (t == ']')
	  *x = '[';
	else if (t == '}')
	  *x = '{';
	return 1;
}

int main () {
	char element;
	char top_element;
	char expected_opener;
	stack_t stack;
	stack_init(&stack, sizeof(char));
	
	while (scanf(" %c", &element) == 1 && element != '0') {
	  	if (element == '(' || element == '[' || element == '{') {
			stack_push(&element, &stack);
		} else if (get_matching_opener(element, &expected_opener)) {
            if (stack_is_empty(stack)) {
                printf("NAO\n");
                return 0;
            }
            stack_top(&top_element, stack);
            if (top_element == expected_opener) {
                stack_pop(&top_element, &stack);
            } else {
                printf("NAO\n");
                return 0;
            }
        }
	}

	if (stack_is_empty(stack))
	  printf("SIM\n");
	else
	  printf("NAO\n");
	return 0;
}