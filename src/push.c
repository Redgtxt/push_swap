#include "push_swap.h"

static void push(t_node **dest, t_node **src)
{
    t_node *temp;

    if (!src || !(*src))
        return;

    temp = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;

    temp->next = *dest;
    if (*dest)
        (*dest)->prev = temp;

    *dest = temp;
}

void pa(t_node **headA, t_node **headB, bool print)
{
    push(headA, headB);
    if (print == true)
        ft_printf("pa\n");
}

void pb(t_node **headA, t_node **headB, bool print)
{
    push(headB, headA);
    if (print == true)
        ft_printf("pb\n");
}

