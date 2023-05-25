#include "monty.h"

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

