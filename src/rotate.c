#include "push_swap.h"

static void rotate(t_node **head)
{
    t_node *first;
    t_node *last;

    if (!head || !(*head) || !((*head)->next))
        return;

    first = *head;
    last = *head;

    while (last->next)
        last = last->next;

    *head = first->next;
    (*head)->prev = NULL;

    first->next = NULL;
    first->prev = last;
    last->next = first;
}

void ra(t_node **head, bool print)
{
    rotate(head);
    if (print == true)
        ft_printf("ra\n");
}

void rb(t_node **head, bool print)
{
    rotate(head);
    if (print == true)
        ft_printf("rb\n");
}

void rr(t_node **headA, t_node **headB, bool print)
{
    rotate(headA);
    rotate(headB);
    if (print == true)
        ft_printf("rr\n");
}