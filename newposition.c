#include "monty.h"
/**
 * swap - swap locations of previous stack with the top stack
 * @h: node to be swapped
 * @line_number: node number
 */
void swap(stack_t **h, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*h)->next;
	(*h)->next = tmp->next;
	(*h)->next->prev = *h;
	tmp->prev = NULL;
	tmp->next = *h;
	(*h) = tmp;
}
/**
 * _add - adds the top two elements in stack
 * @h: top node
 * @line_number: node number
 */
void _add(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n += (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
