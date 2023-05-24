#include "monty.h"
void push(stack_t **stack, unsigned int line_number, char *argument)
{
	stack_t *new_node;
    /* Get the integer argument from the instruction */
    int value;

    /* Example: Assuming the argument is provided as the global variable 'argument' */
    if (argument == NULL || !is_integer(argument))
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
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
void pop(stack_t **stack, unsigned int line_number)
{
	 stack_t *temp;
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
}
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *next;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    next = (*stack)->next;

    top->prev = next;
    top->next = next->next;

    next->prev = NULL;
    next->next = top;

    if (top->next != NULL)
        top->next->prev = top;

    *stack = next;
}
