#include "monty.h"

/**
 * add_node_to_stack - adds a new node to the head of the stack
 * @stack: head of the stack
 * @n: new_value
 * Return: no return
 */
void add_node_to_stack(stack_t **stack, int n)
{
	stack_t *new_node, *current;

	current = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (current)
		current->prev = new_node;
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

