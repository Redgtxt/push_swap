#include "push_swap.h"

void sort_three(t_node **stack_a)
{
    t_node *biggest_number;

    biggest_number = find_max(*stack_a);
    if(biggest_number == *stack_a)
        ra(stack_a, true);
    else if(biggest_number == (*stack_a)->next)
        rra(stack_a, true);
    if((*stack_a)->data > (*stack_a)->next->data)
        sa(stack_a, true);
}

static void move_b_to_a(t_node **stack_a, t_node **stack_b)
{
    prep_for_push(stack_a,(*stack_b)->target_node, 'a');
    pa(stack_a, stack_b, true);
}
static void min_on_top(t_node **stack_a)
{
    while ((*stack_a)->data != find_min(*stack_a)->data)
    {
        if(find_min(*stack_a)->above_median)
            ra(stack_a, true);
        else
            rra(stack_a, true);
    }
}
void sort_stacks(t_node **stack_a,t_node **stack_b)
{
   int len_a;

    len_a = stacklen(*stack_a);
    if(len_a-- > 3 && !is_sorted(*stack_a))
        pb(stack_a, stack_b, true);
    if(len_a-- > 3 && !is_sorted(*stack_a))
        pb(stack_a, stack_b, true);
    while (len_a -- > 3 && !is_sorted(*stack_a))
    {
        init_nodes_a(*stack_a,*stack_b);
        move_a_to_b(stack_a,stack_b);
    }
    sort_three(stack_a);
    while (*stack_b)
    {
        init_nodes_b(*stack_a,*stack_b);
        move_b_to_a(stack_a,stack_b);
    }
    current_index(*stack_a);
    min_on_top(stack_a);
        
}