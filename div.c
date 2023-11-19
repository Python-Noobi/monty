#include "monty.h"

/**
 * divide_top_two_elements - divides the top two elements of the stack.
 * @stack: stack head
 * @counting: line_number
 * Return: no return
 */
void divide_top_two_elements(stack_t **stack, unsigned int counting)
{
	stack_t *current;
	int len = 0, result;

	current = *stack;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	result = current->next->n / current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}

