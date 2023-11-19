#include "monty.h"

/**
 * push_to_stack - adds a new node to the stack.
 * @head: stack head
 * @counting: line_number
 * Return: no return
 */
void push_to_stack(stack_t **head, unsigned int counting)
{
	int num, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (!isdigit(bus.arg[j]))
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counting);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counting);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	num = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, num);
	else
		addqueue(head, num);
}

