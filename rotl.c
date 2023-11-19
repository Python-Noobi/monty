#include "monty.h"

/**
 * rotate_left - rotates the stack to the top.
 * @head: stack head
 * @counting: line_number
 * Return: no return
 */
void rotate_left(stack_t **head, __attribute__((unused)) unsigned int counting)
{
	stack_t *temp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = aux;
}

