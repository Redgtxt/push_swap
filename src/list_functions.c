#include "push_swap.h"

void    add_to_list(t_node **head, int value)
{
    t_node    *new_node;
    t_node    *current;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        write_error();
        
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (!*head)
    {
        *head = new_node;
        return;
    }
    
    current = *head;
    while (current->next)
        current = current->next;
        
    current->next = new_node;
    new_node->prev = current;
}
void    deletlist(t_node *head)
{
    t_node    *current;
    t_node    *next;

    current = head;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
