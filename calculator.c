#include "monty.h"
/**
 * sub
 *
 *
 */
void _sub(stack_t **h, unsigned int line_number)
{
	stack_t *tail;

	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tail = *h;
	while (tail->next != NULL)
		tail = tail->next;
	tail->prev->n -= tail->n;
	tail->n = tail->prev->n;
	tail->prev = tail->prev->prev;
	tail->prev->next = tail;
}
/**
 *
 *
 *
 */
void _mul(stack_t **h, unsigned int line_number)
{
	stack_t *tail;

	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tail = *h;
	while (tail->next != NULL)
		tail = tail->next;
	tail->n *= tail->prev->n;
	tail->prev = tail->prev->prev;
	tail->prev->next = tail;
}
/**
 *
 *
 *
 */
void _div(stack_t **h, unsigned int line_number)
{
	stack_t *tail;

	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tail = *h;
	if (tail->n / tail->prev->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}
	while (tail->next != NULL)
		tail = tail->next;
	tail->n /= tail->prev->n;
	tail->prev = tail->prev->prev;
	tail->prev->next = tail;
}
/**
 *
 *
 *
 */
void _mod(stack_t **h, unsigned int line_number)
{
	stack_t *tail;

	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tail->n / tail->prev->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}
	tail = *h;
	while (tail->next != NULL)
		tail = tail->next;
	tail->n %= tail->prev->n;
	tail->prev = tail->prev->prev;
	tail->prev->next = tail;
}
