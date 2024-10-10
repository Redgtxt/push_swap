#include "push_swap.h"

// int	main(int argc, char *argv[])
// {
// 	t_node	*head;
// 	t_node	*temp;

// 	head = NULL;
// 	if (argc - 1 <= 0)
// 		write_error();
// 	argv_convert_builder(argc, argv, &head);
// 	ft_printf("Antes da ordenação e atribuição de ranks:\n");
// 	temp = head;
// 	while (temp)
// 	{
// 		ft_printf("Node index: [%d], Data: %d\n", temp->index, temp->data);
// 		temp = temp->next;
// 	}
// 	// Ordena a lista e atribui os ranks
// 	assign_ranks(head);
// 	//Lista apos ordenacao
// 	ft_printf("\nDepois da ordenação e atribuição de ranks:\n");
// 	temp = head;
// 	while (temp)
// 	{
// 		ft_printf("Node index: [%d], Data: %d, Rank: %d\n", temp->index,
// 			temp->data, temp->rank);
// 		temp = temp->next;
// 	}
// 	return (0);
// }
int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*temp;

	stack_a = NULL;
	stack_b = NULL;
	if (argc - 1 <= 0)
		write_error();
	// Converte os argumentos para nós na stack_b
	argv_convert_builder(argc, argv, &stack_b);
	// Testando a função pa
	printf("Antes de mover o topo de B para A:\n");
	// Mostra stack_b
	temp = stack_b;
	while (temp)
	{
		printf("Stack B - Node index: [%d], Data: %d\n", temp->index,
			temp->data);
		temp = temp->next;
	}
	// Executa pa (move do topo de B para A)
	pa(&stack_a, &stack_b);
	// Mostra stack_a
	printf("\nDepois de mover o topo de B para A:\n");
	temp = stack_a;
	while (temp)
	{
		printf("Stack A - Node index: [%d], Data: %d\n", temp->index,
			temp->data);
		temp = temp->next;
	}
	return (0);
}
