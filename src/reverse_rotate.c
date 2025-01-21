#include "push_swap.h"

static void	reverse_rotate(t_node **head)
{
    t_node	*first;
    t_node	*last;

    if (!head || !(*head) || !((*head)->next))
        return ;
    first = *head;
    while (first->next)
        first = first->next;
    last = first;
    first = *head;
    *head = last;
    last->prev->next = NULL;
    last->prev = NULL;
    last->next = first;
    first->prev = last;
}

void rra(t_node **head, bool print)
{
    reverse_rotate(head);
    if (print == true)
        ft_printf("rra\n");
}
void rrb(t_node **head, bool print)
{
    reverse_rotate(head);
    if (print == true)
        ft_printf("rrb\n");
}

void rrr(t_node **headA, t_node **headB, bool print)
{
    reverse_rotate(headA);
    reverse_rotate(headB);
    if (print == true)
        ft_printf("rrr\n");
}