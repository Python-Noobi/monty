#include "monty.h"

/**
 * execute_opcode - executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counting: line_counting
 * @file: pointer to monty file
 * Return: no return
 */
int execute_opcode(char *content, stack_t **stack, unsigned int counting, FILE *file)
{
	instruction_t opcodes[] = {
		{"push", push_function}, {"pall", pall_function}, {"pint", pint_function},
		{"pop", pop_function},
		{"swap", swap_function},
		{"add", add_top_two_elements},
		{"nop", nop_function},
		{"sub", sub_function},
		{"div", divide_top_two_elements},
		{"mul", mul_function},
		{"mod", mod_function},
		{"pchar", pchar_function},
		{"pstr", pstr_function},
		{"rotl", rotl_function},
		{"rotr", rotr_function},
		{"queue", queue_function},
		{"stack", stack_function},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return 0;
	bus.arg = strtok(NULL, " \n\t");
	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, counting);
			return 0;
		}
		i++;
	}
	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counting, opcode);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return 1;
}

