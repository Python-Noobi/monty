#include "monty.h"

/**
 * pop_top_element - removes the top element of the stack.
 * @head: stack head
 * @counting: line_number
 * Return: no return
 */
void pop_top_element(stack_t **head, unsigned int counting)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}

