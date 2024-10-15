#include "push_swap.h"

//Swap the first 2 elements at the top of stack a
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
//swap the first 2 elements at the top of stack b
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
//Take the first element at the top of b and put it at the top of a
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

//Take the first element at the top of a and put it at the top of b.
void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	// Verifica se a stack A está vazia
	if (*stack_a == NULL)
		return ;
	// Aponta o topo de A para temp
	temp = *stack_a;
	// Move o topo de A para o próximo elemento
	*stack_a = (*stack_a)->next;
	// Insere temp no topo de B
	temp->next = *stack_b;
	*stack_b = temp;
}
