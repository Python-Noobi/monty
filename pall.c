#include "monty.h"

/**
 * print_all_elements - prints all elements in the stack.
 * @head: stack head
 * @counting: not used
 * Return: no return
 */
void print_all_elements(stack_t **head, unsigned int counting)
{
	stack_t *current;
	(void)counting;

	current = *head;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

