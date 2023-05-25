#include "monty.h"
/**
 * sub - subtracts the top element from the 2nd element of the stack.
 * @stack: a pointer to the top node of linked list of the stack
 * @line_number: line being executed
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int sub_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub_result = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number); /*Remove the top element*/
	(*stack)->n = sub_result; /* Update the second top element with the result*/
}
/**
 * add - add adds the top two elements of the stack.
 * @stack: a pointer to the top node of linked list of the stack
 * @line_number: line being executed
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	next = (*stack)->next;
	next->n += top->n;
	*stack = next;
	(*stack)->prev = NULL;
	free(top);
}
/**
 * nop - doesn’t do anything.
 * @stack: a pointer to the top node of linked list of the stack
 * @line_number: line being executed
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
    /* Do nothing */
}
