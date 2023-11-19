#include "monty.h"

/**
 * subtract_top_two_elements - subtracts the top element
 * from the second top element of the stack.
 * @head: stack head
 * @counting: line_number
 * Return: no return
 */
void subtract_top_two_elements(stack_t **head, unsigned int counting)
{
	stack_t *temp;
	int diff, nodes;

	temp = *head;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	diff = temp->next->n - temp->n;
	temp->next->n = diff;
	*head = temp->next;
	free(temp);
}

