#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	int				len;

	len = stacklen(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

// The Last element becomes the first one(StackB)
void	rrb(t_node **head, bool print)
{
    reverse_rotate(head);
	if (!print)
		ft_printf("rrb\n");
}

// The Last element becomes the first one(StackA)
void	rra(t_node **head, bool print)
{
	reverse_rotate(head);
	if (!print)
		ft_printf("rra\n");
}

void rrr(t_node **stack_a, t_node **stack_b, bool print)
{
    rra(stack_a, true);
    rrb(stack_b, true);

    if (!print)
        ft_printf("rrr\n");
}