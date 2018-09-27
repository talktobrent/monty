#include "monty.h"

/**
 * builtins - cycles through builtins struct, compares the first argument in
 * token array with each opcode, and calls associated function when there is a
 * match.
 *
 * @stack: stack passed in according to struct prototype
 *
 * Return: void
 *
*/
void builtins(stack_t **stack)
{
	instruction_t builtins[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};

	int count;

	for (count = 0; builtins[count].opcode != NULL; count++)
	{
		if ((strcmp(all.arr[0], builtins[count].opcode)) == 0)
		{
			builtins[count].f(stack, all.line_number);
			return;
		}
	}
	all.errorcode = 4;
}
