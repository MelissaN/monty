#include "monty.h"
/**
 * swap - swap locations of previous stack with the top stack
 * @h: node to be swapped
 * @line_number: node number
 */
void swap(stack_t **h, unsigned int line_number)
{
	stack_t *tail;
	stack_t *tmp = NULL;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tail = *h;
	while (tail->next != NULL)
		tail = tail->next;
	tmp = tail->prev;
	tail->prev = tail->prev->prev;
	tail->prev->next = tmp->next;
	tmp->prev = tail;
	tmp->next = NULL;
	tail->next = tmp;
}
/**
 * add - adds the top two elements in stack
 * @h: top node
 * @line_number: node number
 */
void add(stack_t **h, unsigned int line_number)
{
	stack_t *tail;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tail = *h;
	while (tail->next !=NULL)
		tail = tail->next;
	tail->n += tail->prev->n;
	tail->prev = tail->prev->prev;
	tail->prev->next = tail;
       
}
