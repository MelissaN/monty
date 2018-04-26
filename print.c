#include "monty.h"
/**
 * pall - print all nodes in stack
 * @h: head of list (node at the bottom of stack)
 * @line_number: bytecode line number
 */
void pall(stack_t **h, unsigned int line_number)
{
	if (!h || !*h)
		return;

	(void) line_number;

	/* traverse to top of stack */
	while ((*h)->next != NULL)
		*h = (*h)->next;
	while ((*h)->prev != NULL)
	{
		printf("%d\n", (*h)->n);
		*h = (*h)->prev;
	}
	printf("%d\n", (*h)->n);
}
/**
 * pint - print top node in stack
 * @h: head of list (node at the bottom of stack)
 * @line_number: bytecode line number
 */
void pint(stack_t **h, unsigned int line_number)
{
	stack_t *last = NULL;

	if (!h || !*h)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* traverse to top of stack */
	last = *h;
	while (last->next != NULL)
		last = last->next;
	printf("%d\n", last->n);
}
/**
 * nop - do nothing
 * @h: head of list (node at the bottom of stack)
 * @line_number: bytecode line number
 */
void nop(stack_t **h, unsigned int line_number)
{
	(void) h;
	(void) line_number;
	return;
}
