#include "push_swap.h"

// swap the first 2 elements at the top of stack b
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

// Take the first element at the top of a and put it at the top of b.
void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (*stack_a == NULL)
		return ;
	// Aponta o topo de A para temp
	temp = *stack_a;
	// Move o topo de A para o próximo elemento
	*stack_a = (*stack_a)->next;
	// Insere temp no topo de B
	temp->next = *stack_b;
	*stack_b = temp;
  printf("pb\n");
}

//Rotate the elements, the elemento on top go to the bottom
void	rb(t_node **head)
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
	    printf("rb\n");
}
// The Last element becomes the first one(StackB)
void	rrb(t_node **head)
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
    printf("rrb\n");
}
