#include "push_swap.h"



int	main(int argc, char *argv[])
{
	t_node	*head;
	t_node	*temp;

	head = NULL;
	if (argc - 1 <= 0)
		write_error();

    argv_convert_builder(argc, argv, &head);
    
    // Exibe a lista antes da ordenação
    ft_printf("Antes da ordenação e atribuição de ranks:\n");
	temp = head;
	while (temp)
	{
		ft_printf("Node index: [%d], Data: %d\n", temp->index, temp->data);
		temp = temp->next;
	}
    
    // Ordena a lista e atribui os ranks
    assign_ranks(head);

    // Exibe a lista após a ordenação 
    ft_printf("\nDepois da ordenação e atribuição de ranks:\n");
	temp = head;
	while (temp)
	{
		ft_printf("Node index: [%d], Data: %d, Rank: %d\n", temp->index, temp->data, temp->rank);
		temp = temp->next;
	}

	return (0);
}
