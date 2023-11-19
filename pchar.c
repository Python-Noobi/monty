#include "monty.h"

/**
 * print_char_at_top - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counting: line_number
 * Return: no return
*/
void print_char_at_top(stack_t **head, unsigned int counting)
{
	stack_t *current;

	current = *head;
	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}

