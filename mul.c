#include "monty.h"

/**
 * multiply_top_two_elements - multiplies the top two elements of the stack.
 * @head: stack head
 * @counting: line_number
 * Return: no return
 */
void multiply_top_two_elements(stack_t **head, unsigned int counting)
{
	stack_t *current;
	int len = 0, product;

	current = *head;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	product = current->next->n * current->n;
	current->next->n = product;
	*head = current->next;
	free(current);
}


