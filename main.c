#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
    unsigned int line_number = 0;
    char *opcode;
    stack_t *stack = NULL;
    char *argument;
    size_t line_length;

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
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        line_number++;
        line_length = strlen(line);

        /* Remove trailing newline character */
        if (line_length > 0 && line[line_length - 1] == '\n')
            line[line_length - 1] = '\0';

        /* Tokenize the line to get the opcode and its argument (if any) */
        opcode = strtok(line, " \t");
        if (opcode == NULL || opcode[0] == '#')
            continue; /* Skip empty lines or comments */

        argument = strtok(NULL, " \t");

        /* Execute the corresponding opcode function */
        if (strcmp(opcode, "push") == 0)
        {
            push(&stack, line_number, argument);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            pint(&stack, line_number);
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            pop(&stack, line_number);
        }
        else if (strcmp(opcode, "swap") == 0)
        {
            swap(&stack, line_number);
        }
        else if (strcmp(opcode, "add") == 0)
        {
            add(&stack, line_number);
        }
        else if (strcmp(opcode, "nop") == 0)
        {
            nop(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    /* Clean up */
    fclose(file);
    /* Free the stack (if necessary) */
    /* Return success */
    return 0;
}

