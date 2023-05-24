#include "monty.h"

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

