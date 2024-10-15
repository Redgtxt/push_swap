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
void	assign_ranks_to_stackA(t_node *stackA, t_node *stackSort)
{
	t_node	*tempA;
	t_node	*tempSort;

	tempA = stackA;
	while (tempA)
	{
		tempSort = stackSort;
		while (tempSort)
		{
			// Compara os valores de 'data' das duas listas
			if (tempA->data == tempSort->data)
			{
				// Copia o rank de stackSort para stackA
				tempA->rank = tempSort->rank;
				break;
			}
			tempSort = tempSort->next;
		}
		tempA = tempA->next;
	}
}
