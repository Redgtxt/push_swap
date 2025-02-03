#include "push_swap.h"

void current_index(t_node *stack)
{
    int i;
    int median;

    i = 0;
    if(!stack)
        return;
    median = stacklen(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if(i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        i++;
    }    
}
static void set_target_a(t_node *stack_a,t_node *stack_b)
{
    t_node *current_b;
    t_node *target_node;
    long best_match_index;

    while (stack_a)
    {
        best_match_index = INT_MIN;
        current_b  = stack_b;
        while (current_b)
        {
            if(current_b->data < stack_a->data && current_b->data > best_match_index)
            {
                best_match_index = current_b->data;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if(best_match_index == INT_MIN)
            stack_a->target_node = find_max(stack_b);
        else
            stack_a->target_node = target_node;
        stack_a = stack_a->next;   
    } 
}
static void cost_analysis_a(t_node *stack_a,t_node *stack_b)
{
    int len_a;
    int len_b;

    len_a = stacklen(stack_a);
    len_b = stacklen(stack_b);
    while (stack_a)
    {
        stack_a->push_cost = stack_a->index;
        if(!(stack_a->above_median))
            stack_a->push_cost = len_a - (stack_a->index);
        if(stack_a->target_node->above_median)
            stack_a->push_cost += stack_a->target_node->index;
        else
            stack_a->push_cost += len_b - stack_a->target_node->index;
        stack_a = stack_a->next;
    }
}
void set_cheapest(t_node *stack)
{
    int  cheapest_value;
    t_node *cheapest_node;

    if(!stack)
        return;
    
    cheapest_value = INT_MAX;
    while (stack)
    {
        if(stack->push_cost < cheapest_value)
        {
            cheapest_value = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    cheapest_node->cheapest = true;
}
void init_nodes_a(t_node *stack_a,t_node *stack_b)
{
    current_index(stack_a);
    current_index(stack_b);
    set_target_a(stack_a,stack_b);
    cost_analysis_a(stack_a,stack_b);
    set_cheapest(stack_a);
}