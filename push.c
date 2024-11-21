#include "push_swap.h"

static void	push(t_node **dest, t_node **src)
{
    t_node	*node_to_push;

    if (NULL == *src)
        return ;
    node_to_push = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    node_to_push->prev = NULL;
    if (NULL == *dest)
    {
        *dest = node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = *dest;
        node_to_push->next->prev = node_to_push;
        *dest = node_to_push;
    }
}
// Take the first element at the top of b and put it at the top of a
void	pa(t_node **stack_a, t_node **stack_b, bool print)
{
    push(stack_a, stack_b);
    if (!print)
        ft_printf("pa\n");
}


// Take the first element at the top of a and put it at the top of b.
void	pb(t_node **stack_a, t_node **stack_b, bool print)
{
    push(stack_b, stack_a);
    if (print == false)
        ft_printf("pb\n");
}