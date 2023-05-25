#include "monty.h"
/**
 * cleanup - frees memory both for the stack and the line, closes file
 * @file: pointer to the monty file we are interpreting
 * @line: buffer storing lines read from the file
 * @stack: a double pointer to the top node of the stack
 */

void cleanup(FILE *file, char *line, stack_t **stack)
{
	stack_t *current;
	stack_t *next;

	free(line);
	fclose(file);
	/* Free the stack */
	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

