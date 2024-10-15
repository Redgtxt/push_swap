#include "push_swap.h"

t_node	*create_stackA(int argc, char *argv[])
{
	t_node	*head;

	// t_node	*temp;
	head = NULL;
	if (argc - 1 <= 0)
		write_error();
	argv_convert_builder(argc, argv, &head);
	ft_printf("Antes da ordenação e atribuição de ranks:\n");
	print_stack(head);
	// Ordena a lista e atribui os ranks
	// assign_ranks(head);
	return (head);
}

t_node	*create_empty_stack(void)
{
	t_node	*stackb;

	stackb = NULL; // Inicializa a stack vazia
	return (stackb);
}

int	main(int argc, char *argv[])
{
	t_node	*head;
	t_node	*stackb;
	t_node	*stackSort;

	head = create_stackA(argc, argv); // Cria stackA com os dados do argv
	stackb = create_empty_stack();    // Cria stackB vazia
	stackSort = create_empty_stack(); // Cria stackSort vazia
	// Transfere os nodes de A para Sort (sem alterar a ordem)
	copy_stack(head, &stackSort);
	// Ordena e atribui ranks na stackSort
	assign_ranks(stackSort);
	printf("-------------- Stack Sort --------------\n");
	print_stack_ranks(stackSort);
	// Copia os ranks da stackSort para a stackA (sem alterar a ordem de stackA)
	assign_ranks_to_stackA(head, stackSort);
	// Lista apos atribuição dos ranks
	printf("-------------- Stack A After --------------\n");
	print_stack_ranks(head);
		printf("-------------- PB Test--------------\n");
	pb(&head,&stackb);
	print_stack_ranks(stackb);
	print_stack_ranks(head);
	return (0);
}
