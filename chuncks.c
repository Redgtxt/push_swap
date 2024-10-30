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
void	move_current_chunk_to_stackB(t_node **stackA, t_node **stackB,
		int current_chunk)
{
	int		moved_count;
	t_node	*temp;

	moved_count = 0;
	temp = *stackA;
	// Contar quantos elementos pertencem ao chunk atual em StackA
	while (temp)
	{
		if (temp->chunk == current_chunk)
		{
			moved_count++;
		}
		temp = temp->next;
	}
	// Mover elementos que não pertencem ao chunk atual de StackA para StackB
	while (moved_count > 0)
	{
		if ((*stackA)->chunk == current_chunk)
		{
			// Elemento pertence ao chunk atual, mantém em StackA

			ra(stackA); // Roda apenas para o próximo elemento
            moved_count--;
		}
		else
		{
			// Elemento não pertence ao chunk atual, move para StackB
			pb(stackA, stackB);
		}
	}
}
