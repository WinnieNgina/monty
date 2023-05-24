#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
void push(stack_t **stack, unsigned int line_number, char *argument)
{
	stack_t *new_node;
    /* Get the integer argument from the instruction */
    int value;

    /* Example: Assuming the argument is provided as the global variable 'argument' */
    if (argument == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Convert the argument to an integer */
    value = atoi(argument);

    /* Create a new stack node */
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node */
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    /* Push the new node onto the stack */
    if (*stack != NULL)
        (*stack)->prev = new_node;
    new_node->next = *stack;
    *stack = new_node;
}
void pall(stack_t **stack)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

