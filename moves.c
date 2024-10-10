#include "push_swap.h"

void	sa(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!head || !(*head) || !((*head)->next))
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}
void	sb(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!head || !(*head) || !((*head)->next))
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}
void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	// Verifica se a stack B está vazia
	if (*stack_b == NULL)
		return ;
	// Aponta o topo de B para temp
	temp = *stack_b;
	// Move o topo de B para o próximo elemento
	*stack_b = (*stack_b)->next;
	// Insere temp no topo de A
	temp->next = *stack_a;
	*stack_a = temp;
}
