#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    process_file(argv[1]);

    return 0;
}

void execute_instruction(stack_t **stack, unsigned int line_number, char *opcode, char *argument)
{
    if (strcmp(opcode, "push") == 0)
    {
        push(stack, line_number, argument);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack);
    }
    else if (strcmp(opcode, "pint") == 0)
    {
        pint(stack, line_number);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
        pop(stack, line_number);
    }
    else if (strcmp(opcode, "swap") == 0)
    {
        swap(stack, line_number);
    }
    else if (strcmp(opcode, "add") == 0)
    {
        add(stack, line_number);
    }
    else if (strcmp(opcode, "nop") == 0)
    {
        nop(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

void process_file(const char *filename)
{
    FILE *file;
    char *line = NULL;
    unsigned int line_number = 0;
    char *opcode;
    stack_t *stack = NULL;
    char *argument;
    size_t len = 0;
    ssize_t read;

    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#')
            continue;

        argument = strtok(NULL, " \t\n");

        execute_instruction(&stack, line_number, opcode, argument);
    }

    free(line);
    fclose(file);
}

