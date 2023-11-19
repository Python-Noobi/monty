#include "monty.h"

/**
 * mod_top_two_elements - computes the rest of the division
 * of the second top element of the stack by the top element of the stack
 * @head: stack head
 * @counting: line_number
 * Return: no return
 */
void mod_top_two_elements(stack_t **head, unsigned int counting)
{
	stack_t *current;
	int len = 0, result;

	current = *head;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = current->next->n % current->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}

