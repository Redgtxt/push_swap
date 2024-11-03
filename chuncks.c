#include "push_swap.h"

// Calcula o número de chunks com base na quantidade de elementos
int	calculate_chunks(int num_elements)
{
	int	divisor;
	int	chunks;

	if (num_elements <= 20)
	{
		divisor = 5; // Menos chunks para listas pequenas
	}
	else if (num_elements <= 100)
	{
		divisor = 20;
	}
	else
	{
		divisor = 40; // Mais chunks para listas grandes
	}
	chunks = num_elements / divisor;
	if (num_elements % divisor != 0)
	{
		chunks += 1; // Arredonda para cima se houver sobra na divisão
	}
	if (chunks == 0)
	{
		chunks = 1;
	}
	return (chunks);
}

// Função para atribuir chunks com base nos ranks
void	assign_chunks(t_node *head)
{
	int		num_elements;
	int		chunks;
	int		chunk_size;
	t_node	*temp;

	num_elements = stacklen(head);
	chunks = calculate_chunks(num_elements);
	chunk_size = num_elements / chunks;
	// Atribuir chunks baseados nos ranks
	temp = head;
	while (temp != NULL)
	{
		temp->chunk = temp->rank / chunk_size;
		if (temp->chunk >= chunks)
		{
			temp->chunk = chunks - 1; // Pode ter um a mais
		}
		temp = temp->next;
	}
}
//Movo todos os chunks menos o menor
void	move_all_but_smallest_chunk(t_node **stackA, t_node **stackB)
{
	int		min_chunk;
	int		total_count;
	t_node	*temp;

	// Encontrar o menor chunk na StackA
	min_chunk = (*stackA)->chunk;
	temp = *stackA;
	while (temp)
	{
		if (temp->chunk < min_chunk)
		{
			min_chunk = temp->chunk;
		}
		temp = temp->next;
	}

	// Contar o número total de elementos na StackA
	total_count = stacklen(*stackA);

	// Loop para mover os elementos
	while (total_count > 0)
	{
		if ((*stackA)->chunk == min_chunk)
		{
			// Elemento pertence ao menor chunk, mantém em StackA
			ra(stackA);
		}
		else
		{
			// Elemento não pertence ao menor chunk, move para StackB
			pb(stackA, stackB);
		}
		total_count--;
	}
}

int find_min_rank(t_node *stackA)
{
    int min_rank = stackA->rank;
    t_node *temp = stackA;

    while (temp)
    {
        if (temp->rank < min_rank)
        {
            min_rank = temp->rank;
        }
        temp = temp->next;
    }
    return min_rank;
}
// Função para ordenar a stackA usando movimentos
void sort_with_moves(t_node **stackA) {
    int stack_len = stacklen(*stackA);

    if (stack_len < 2) return;

    while (stack_len > 1) {
        t_node *min_node = *stackA;
        t_node *current = min_node->next;

        // Encontrar o menor elemento
        while (current) {
            if (current->rank < min_node->rank) {
                min_node = current;
            }
            current = current->next;
        }

        // Rotacionar para colocar o menor elemento no topo
        int rotations = min_node->index;
        if (rotations <= stack_len / 2) {
            while (rotations--) {
                ra(stackA);
            }
        } else {
            while (stack_len - rotations--) {
                rra(stackA);
            }
        }

        // Mover o menor elemento para a posição correta
        if ((*stackA)->rank > (*stackA)->next->rank) {
            sa(stackA);
        }

        stack_len--; // Um elemento a menos para ordenar
    }
}




