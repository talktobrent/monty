#include "monty.h"

int main(int argc, char **argv)
{
	char *buffer = NULL;
	stack_t *stack = NULL;
	size_t n = 0;
	int line = 0, error = 0, check = 0;
	FILE *monty = NULL;

	if (argc != 2 || access(argv[1], F_OK) == -1)
		error = 9;
	else
	{
		monty = fopen(argv[1], "r");
		if (monty == NULL)
			error = 8;
	}

	if (error == 0)
	{
		do {
			buffer = NULL;
			n = 0;
			arr[0] = NULL;
			arr[1] = NULL;
			check = getline(&buffer, &n, monty);
			if (buffer == NULL)
				all.errorcode = 7;
			if (check != -1 && all.errorcode == 0)
			{
				all.line_number++;
				buildarray(buffer);
				builtins(&stack);
			}
		} while (check != -1 && all.errorcode == 0);
	}
	errprint();
	/**
	if (list != NULL)
		free(list);
	if (buffer != NULL)
		free(buffer);
	**/
	return (error);
}
