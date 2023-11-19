#include "monty.h"

/**
 * swap_top_two_elements - swaps the top two elements of the stack.
 * @head: stack head
 * @counting: line_number
 * Return: no return
*/
void swap_top_two_elements(stack_t **head, unsigned int counting)
{
	stack_t *current;
	int len = 0, temp;

	current = *head;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}

