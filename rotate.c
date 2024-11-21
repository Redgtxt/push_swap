#include "push_swap.h"

// Swap the first 2 elements at the top of stack a


static void	rotate(t_node **stack)
{
	t_node	*last_node;
	int				len;

	len = stacklen(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}	

// Rotate the elements, the elemento on top go to the bottom(StacKA)
void	ra(t_node **head, bool print)
{
	rotate(head);
	if (!print)
		ft_printf("ra\n");
}
// Rotate the elements, the elemento on top go to the bottom
void	rb(t_node **head, bool print)
{
	rotate(head);
	if (!print)
		ft_printf("rb\n");
}

void rr(t_node **stack_a, t_node **stack_b, bool print)
{
    ra(stack_a, true);
    rb(stack_b, true);

    if (!print)
        ft_printf("rr\n");
}


