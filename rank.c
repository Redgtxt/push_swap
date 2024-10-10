#include "push_swap.h"

void	swap_nodes(t_node *a, t_node *b)
{
	int	temp_data;
	int	temp_index;

	temp_data = a->data;
	temp_index = a->index;
	a->data = b->data;
	a->index = b->index;
	b->data = temp_data;
	b->index = temp_index;
}

void	sort_list(t_node *head)
{
	t_node	*current;
	int		swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = head;
		while (current->next != NULL)
		{
			if (current->data > current->next->data)
			{
				swap_nodes(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
	}
}

void	assign_ranks(t_node *head)
{
	t_node *current;
	int rank = 0;

	// Ordena a lista
	sort_list(head);

	// Atribui os ranks
	current = head;
	while (current != NULL)
	{
		current->rank = rank++;
		current = current->next;
	}
}
