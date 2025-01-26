#include "push_swap.h"

static void swap(t_node **head)
{
    t_node *first;
    t_node *second;

    if (!head || !(*head) || !((*head)->next))
        return;

    first = *head;
    second = first->next;

    first->next = second->next;
    if (second->next)
        second->next->prev = first;

    second->next = first;
    second->prev = first->prev;
    first->prev = second;

    *head = second;
}

void sa(t_node **head, bool print)
{
    swap(head);
    if (print == true)
        ft_printf("sa\n");
}

void sb(t_node **head, bool print)
{
    swap(head);
    if (print == true)
        ft_printf("sb\n");
}

void ss(t_node **headA, t_node **headB, bool print)
{
    swap(headA);
    swap(headB);
    if (print == true)
        ft_printf("ss\n");
}