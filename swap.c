#include "push_swap.h"

static void	swap(t_node **head)
{
	int	len;

	len = stacklen(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_node **head, bool print)
{
	swap(head);
	if (!print)
		ft_printf("sa\n");
}
// swap the first 2 elements at the top of stack b
void	sb(t_node **head, bool print)
{
    swap(head);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}