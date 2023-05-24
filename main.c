#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
    unsigned int line_number = 0;
      char *opcode;
    stack_t *stack = NULL;
    char *argument;
    size_t len = 0;
    ssize_t read;
    /* Check if the correct number of arguments is provided */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the Monty byte code file */
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Read the file line by line and execute the instructions */

     while ((read = getline(&line, &len, file)) != -1)
     {
        line_number++;
        /* Tokenize the line to get the opcode and its argument (if any) */
        opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#')
            continue; /* Skip empty lines or comments */

        argument = strtok(NULL, " \t\n");

        /* Execute the corresponding opcode function */
        if (strcmp(opcode, "push") == 0)
        {
            push(&stack, line_number, argument);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            free(line);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    /* Clean up */
    free(line);
    fclose(file);
    /* Free the stack (if necessary) */
    /* Return success */
    return 0;
}

