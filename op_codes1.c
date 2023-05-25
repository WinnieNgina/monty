#include "monty.h"
/**
 * push - adds an element to the stack
 * @stack: pointer to the linked list top node
 * @line_number: line being executed
 * @argument: the value of the node being added
 */
void push(stack_t **stack, unsigned int line_number, char *argument)
{
	stack_t *new_node;
	/* store the argument after its conerted from str to int*/
	int value;

	if (argument == NULL || !is_integer(argument))
		/* if argument doesn't point to a valid address*/
		/*or argument is not a valid interger*/
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Convert the argument to an integer */
	value = atoi(argument);
	/* Assign memry for the new stack node */
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
	{
		(*stack)->prev = new_node;
	}
	new_node->next = *stack;
	*stack = new_node;
}
/**
 * pall - prints all the values stored in the stack
 * @stack: a pointer to the stack linked list
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - prints the value at the top of the stack
 * @stack: a pointer to the linked list of the stack
 * @line_number: line being executed
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the value at the top of the stack
 * @stack: a pointer to the linked list of the stack
 * @line_number: line being executed
 */
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
/**
 * swap -  swaps the top two elements of the stack.
 * @stack: a pointer to the top node of linked list of the stack
 * @line_number: line being executed
 */
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
