#include "monty.h"
/**
 * main - Entry point of the monty program
 * @argc: argument count
 * @argv:- argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	/*monty interpreter and the file*/
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	process_file(argv[1]);
	return (0);
}
/**
 * exec - executes the opcode provided
 * @stack: pointer to the linked list for the stack
 * @line_number: line number of the opcode being executed
 * @opcode: string containing the opcode
 * @args: value of integer passed to push function
 */
void exec(stack_t **stack, unsigned int line_number, char *opcode, char *args)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, args);
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
	else if (strcmp(opcode, "sub") == 0)
	{
		sub(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
/**
 * process_file - prepares the file for execution
 * @filename: a pointer to the file being interpreted,
 */
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
	  /* Open the Monty byte code file */
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n\r");
		/* Tokenize the line to get the opcode and its argument (if any) */
		if (opcode == NULL)
			/*check if opcode is an empty line*/
		{
			free(opcode);
			continue;/* Skip empty lines or comments */
		}
		else if (opcode[0] == '#')
			/*check if opcode contains a comment*/
			continue;
		argument = strtok(NULL, " \t\n\r");
		exec(&stack, line_number, opcode, argument);
		/* Execute the corresponding opcode function */
	}
	cleanup(file, line, &stack);
	/*free memory allocated for line, stack and close the file*/
}

