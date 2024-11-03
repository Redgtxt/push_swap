#include "push_swap.h"

void	deletlist(t_node *node)
{
	if (node == NULL)
		return ;
	deletlist(node->next);
	free(node);
}
int	stacklen(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	print_stack_chunks(t_node *stack)
{
	t_node	*temp;

	if (!stack)
	{
		ft_printf("A stack está vazia.\n");
		return;
	}

	temp = stack;
	while (temp)
	{
		ft_printf("Node index: [%d], Data: %d, Rank: %d, Chunks: %d.\n", temp->index, temp->data, temp->rank, temp->chunk);
		temp = temp->next;
	}
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		// Verifica se o elemento atual é maior que o próximo
		if (stack->rank > stack->next->rank)
		{
			return (0); // Não está ordenado
		}
		stack = stack->next;
	}
	return (1); // Está ordenado
}
