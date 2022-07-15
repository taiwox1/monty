#include "monty.h"
#include <string.h>

/**
 * _push - pushes element to the stack
 *
 * @dbly: head of a double linked list
 * @cline: line number
 * Return: no return
 */
void _push(stack_t **dbly, unsigned int cline)
{
	int n, j;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(dbly, n);
	else
		add_dnodeint_end(dbly, n);
}

/**
 * _pall - prints all element from top of stack
 * @dbly: head of double linked list
 * @count_line: line number
 * Return: void.
 */
void _pall(stack_t **dbly, unsigned int count_line)
{
	stack_t *temp;
	(void)count_line;

	temp = *dbly;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of stack
 * @dbly: head of double linked list
 * @count_line: line number
 * Return: void.
 */
void _pint(stack_t **dbly, unsigned int count_line)
{
	stack_t *temp;

	temp = *dbly;
	if (temp == NULL)
	{
		dprintf(2, "L%u: ", count_line);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}
/**
 * pop - removes the top element of the stack
 * @dbly: head of double linked list
 * @count_line: line number
 * Return: void.
 */
void _pop(stack_t **dbly, unsigned int count_line)
{
	stack_t *temp;

	temp = *dbly;
	if (temp == NULL)
	{
		dprintf(2, "L%u: ", count_line);
		dprintf(2, "can't pop an empty stack\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	*dbly = (*dbly)->next;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @dbly: head of double linked list
 * @count_line: line number
 * Return: void.
 */
void _swap(stack_t **dbly, unsigned int count_line)
{
	int i = 0;
	stack_t *curr;

	curr = *dbly;
	for (; curr != NULL; curr = curr->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: ", count_line);
		dprintf(2, "can't swap, stack too short\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	curr = *dbly;
	*dbly = (*dbly)->next;
	curr->next = (*dbly)->next;
	curr->prev = *dbly;
	(*dbly)->next = curr;
	(*dbly)->prev = NULL;
}
