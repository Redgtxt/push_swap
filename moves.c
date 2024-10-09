#include "push_swap.h"

void sa(t_node **head)
{
    t_node *first;
    t_node *second;


    if (!head || !(*head) || !((*head)->next))
        return;

    first = *head;        
    second = (*head)->next; 


    first->next = second->next;
    second->next = first;
    *head = second;  
}



