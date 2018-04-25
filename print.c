#include "monty.h"
/**
 * pall - print all stacks
 * @h: node at the top of stack
 * @n: node number
 */
void pall(stack_t **h, unsigned int n)
{
	if (!h || !*h)
		return;
	n = (*h)->n;
	while (h)
	{
		printf("%d\n", n);
		*h = (*h)->prev;
	}
}
/**
 * pint - print top stack
 * @h: node at the top of the stack
 * @n: node number
 */
void pint(stack_t **h, unsigned int n)
{
	n = (*h)->n;
	if (!h || !*h)
	{
		printf("L%d: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", n);
}
