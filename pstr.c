#include "monty.h"

/**
 * print_string - prints the string starting at the top of the stack.
 * @head: stack head
 * @counting: line_number
 * Return: no return
 */
void print_string(stack_t **head, unsigned int counting)
{
	stack_t *current;
	(void)counting;

	current = *head;
	while (current && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

