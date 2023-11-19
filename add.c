#include "monty.h"

/**
 * add_top_two_elements - adds the top two elements of the stack.
 * @stack: stack head
 * @counting: line_number
 * Return: no return
 */
void add_top_two_elements(stack_t **stack, unsigned int counting)
{
	stack_t *current;
	int len = 0, sum;

	current = *stack;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	*stack = current->next;
	free(current);
}

