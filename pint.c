#include "monty.h"

/**
 * print_top_element - prints the top element of the stack.
 * @head: stack head
 * @counting: line_number
 * Return: no return
 */
void print_top_element(stack_t **head, unsigned int counting)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

