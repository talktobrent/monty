#include "monty.h"

/**
 * main - function that initializes the program
 *
 * @argc: number of arguments given to the executable
 * @argv: array of arguments
 *
 * Description: Checks the argument count when running the program,
 * attempts to find file, opens the file with fopen, passes file stream to
 * parseAndExec for executing the parsed command or catching an error if the
 * parsed line has any issues, and frees the stack once monty stream reaches
 * EOF.
 *
 * Return: -1 if any error condition was met. 0, if no errors were met.
*/
int main(int argc, char **argv)
{
	FILE *monty = NULL;
	stack_t *stack;
	all.argv = argv;

	if (argc != 2 || access(argv[1], F_OK) == -1)
	{
		all.errorcode = 9;
	}
	else
	{
		monty = fopen(argv[1], "r");
		if (monty == NULL)
			all.errorcode = 8;
	}

	if (all.errorcode == 0)
		stack = parseAndExec(monty);
	else
		errprint();

	if (stack != NULL)
		freeStack(stack);

	return (all.errorcode);
}
