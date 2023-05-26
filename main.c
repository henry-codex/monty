#include "monty.h"
#include <stdio.h>

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Exit status
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int con = 0;
	size_t numbytes = 0;
	int bytesr = 0;

	if (argc != 2)
	{
		fputs("USAGE: monty file\n", stderr);
		exit(EXIT_FAILURE);
	}

	/* Initialize global variables */
	global.flag = 1;
	global.line = NULL;
	global.fil = fopen(argv[1], "r");

	if (global.fil == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((bytesr = getline(&global.line, &numbytes, global.fil)) != EOF)
	{
		con++;
		delete_jump(global.line);

		if (global.line[0] != '#')
		{
			global.token = strtok(global.line, " \t\n");
			global.opco = global.token;

			if (global.opco != NULL)
			{
				global.token = strtok(NULL, " \t\n");
				func(global.opco)(&stack, con);
			}
		}
	}

	free_l(&stack);
	free(global.line);
	fclose(global.fil);

	return 0;
}

