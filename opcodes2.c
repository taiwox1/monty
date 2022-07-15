#include "monty.h"

/**
 * _add - adds the top 2 elements on the stack
 * @dbly: head of the linked list
 * @count_line: line number
 * Return: void.
 */
void _add(stack_t **dbly, unsigned int count_line)
{
	int i = 0;
	stack_t *curr = NULL;

	curr = *dbly;
	for (; curr != NULL; curr = curr->next, i++)
		;
	if (i < 2)
	{
		dprintf(2, "L%u: ", count_line);
		dprintf(2, "can't add, stack too short\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	curr = (*dbly)->next;
	curr->n += (*dbly)->n;
	_pop(dbly, count_line);
}

/**
 * _nop - does nothing
 * @dbly: head of linked lst
 * @count_line: line number
 * Return: void.
 */
void _nop(stack_t **dbly, unsigned int count_line)
{
	(void)dbly;
	(void)count_line;
}

/**
 * _sub - subtracts the top element of the stack
 * from the second top element of the stack
 * @dbly: head of the linked list
 * @count_line: line number
 * Return: void.
 */
void _sub(stack_t **dbly, unsigned int count_line)
{
	int i = 0;
	stack_t *curr = NULL;

	curr = *dbly;
	for (; curr != NULL; curr = curr->next, i++)
		;
	if (i < 2)
	{
		dprintf(2, "L%u: ", count_line);
		dprintf(2, "can't sub, stack too short\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	curr = (*dbly)->next;
	curr->n -= (*dbly)->n;
	_pop(dbly, count_line);
}
/**
 * _div - divides the second top element of the stack by
 * the top element of the stack
 * @dbly: head of the linked list
 * @count_line: line number
 * Return: void.
 */
void _div(stack_t **dbly, unsigned int count_line)
{
	int i = 0;
	stack_t *curr = NULL;

	curr = *dbly;
	for (; curr != NULL; curr = curr->next, i++)
		;
	if (i < 2)
	{
		dprintf(2, "L%u: ", count_line);
		dprintf(2, "can't div, stack too short\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*dbly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", count_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	curr = (*dbly)->next;
	curr->n /= (*dbly)->n;
	_pop(dbly, count_line);
}
