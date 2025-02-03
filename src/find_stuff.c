#include "push_swap.h"
//[] Possivel edge case com os valores do int max e min
//Se der erro nas funcoes e so passar tudo para long

t_node *find_min(t_node *stack)
{
    int min;
    t_node *min_node;

    if(!stack)
        return (NULL);
    
    min = INT_MAX;
    while(stack)
    {
        if(stack->data < min)
        {
            min = stack->data;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}

t_node *find_max(t_node *stack)
{
    int max;
    t_node *max_node;

    if(!stack)
        return (NULL);

    max = INT_MIN; 
    while(stack)
    {
        if(stack->data > max)
        {
            max = stack->data;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}
