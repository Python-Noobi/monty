#include "monty.h"

/**
 * switch_to_queue - switches the stack to a queue.
 * @head: stack head
 * @counting: line_number
 * Return: no return
 */
void switch_to_queue(stack_t **head, unsigned int counting)
{
	(void)head;
	(void)counting;
	bus.lifi = 1;
}

/**
 * add_to_queue - adds a new node to the end of the stack (queue).
 * @num: new_value
 * @head: stack head
 * Return: no return
 */
void add_to_queue(stack_t **head, int num)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->next = NULL;

	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}

