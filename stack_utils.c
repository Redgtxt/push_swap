#include "push_swap.h"

t_node	*find_last_node(t_node *head)
{
    if (NULL == head)
        return (NULL);
    while (head->next)
        head = head->next;
    return (head);
}
void	append_node(t_node **stack, int nbr)
{
    t_node	*node;
    t_node	*last_node;

    if (NULL == stack)
        return ;
    node = malloc(sizeof(t_node));
    if (NULL == node)
        return ;
    node->next = NULL;
    node->value = nbr;
    if (NULL == *stack)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}

void	print_stack(t_node *stack)
{
    t_node	*temp;

    if (!stack)
    {
        ft_printf("A stack está vazia.\n");
        return;
    }

    temp = stack;
    while (temp)
    {
        ft_printf("Value: %d\n", temp->value);
        temp = temp->next;
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

bool stack_sorted(t_node *stack)
{
    if(stack == NULL)
        return 1;
    while (stack->next)
    {
       if(stack->value > stack->next->value)
        return (false);
       stack = stack->next;
    }
    return (true);
}

