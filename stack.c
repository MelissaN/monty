#include "monty.h"
/**
 * push - adds node to the end of dlinkedlist
 * @h: node at the top of stack
 * @n: node number
 */
void push(stack_t **h, unsigned int n)
{
	stack_t *new, *last;

	if (!head)
		return (NULL);

	/* malloc and set new node data */
	new = malloc(sizeof(struct stack_s));
	if (!new)
		return (NULL);
	new->n = n;

	/* account for empty linked list */
	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		new->prev = NULL;
		return (new);
	}

	/* traverse to last node and insert */
	last = *head;
	while (last->next != NULL)
		last = last->next;
	new->next = NULL;
	new->prev = last;
	last->next = new;

	return (new);
}
/**
 * pop - removes node at end of dlinkedlist
 * @h: node at the top of stack
 * @n: node number
 */
void pop(stack_t **h, unsigned int n):
{
	stack_t *del = NULL;

	/* do nothing if nothing to delete */
	if (head == NULL || *head == NULL)
		return (-1);

	del = *head;

	/* delete first node */
	if (index == 0)
	{
		*head = (*head)->next;
		free(del);
		if (*head != NULL)
			(*head)->prev = NULL;
		return (1);
	}

	/* delete nth node as long as within range of list */
	while ((index != 0) && (del->next != NULL))
	{
		index -= 1;
		del = del->next;
	}
	if (index == 0)
	{
		del->prev->next = del->next;
		if (del->next != NULL)
			del->next->prev = del->prev;
		free(del);
		return (1);
	}
	return (-1);
}
