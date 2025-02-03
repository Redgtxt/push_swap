#include "push_swap.h"

static t_node	*find_last(t_node *stack) 
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
void add_to_list(t_node **head, int value)
{
    t_node *new_node;
    t_node *last_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        write_error();

    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (!*head)
    {
        *head = new_node;
    }
    else
    {
        last_node = find_last(*head);
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}

void deletlist(t_node *head)
{
    t_node *current;
    t_node *next;

    current = head;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
}


int	stacklen(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
