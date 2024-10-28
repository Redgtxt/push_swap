#include "push_swap.h"

// Swap the first 2 elements at the top of stack a
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
	    printf("sa\n");
}

// Take the first element at the top of b and put it at the top of a
void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (*stack_b == NULL)
		return ;
	// Aponta o topo de B para temp
	temp = *stack_b;
	// Move o topo de B para o próximo elemento
	*stack_b = (*stack_b)->next;
	// Insere temp no topo de A
	temp->next = *stack_a;
	*stack_a = temp;
	printf("pa\n");
}

// Rotate the elements, the elemento on top go to the bottom(StacKA)
void	ra(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!(*head) || !(*head)->next)
		return ;
	first = *head;
	// Avança o head para o próximo node (o segundo elemento se torna o novo head)
	*head = (*head)->next;
	// Encontrar o último node da lista
	last = *head;
	while (last->next)
		last = last->next;
	// O último node agora aponta para o primeiro
	last->next = first;
	first->next = NULL;
    printf("ra\n");	
}
// The Last element becomes the first one(StackA)
void	rra(t_node **head)
{
	t_node	*last;
	t_node	*second_last;

	// Se a stack estiver vazia ou tiver apenas um elemento,não precisa rotacionar
	if (!(*head) || !(*head)->next)
		return ;
	// Encontra o penúltimo e o último node
	second_last = *head;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	// Move o último node para a frente da lista
	last->next = *head;
	*head = last;
	// O penúltimo node agora é o último, então aponta para NULL
	second_last->next = NULL;
	    printf("rra\n");
}
