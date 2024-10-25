#include "push_swap.h"

t_node	*create_stackA(int argc, char *argv[])
{
	t_node	*head;

	head = NULL;
	if (argc - 1 <= 0)
		write_error();
	argv_convert_builder(argc, argv, &head);
	ft_printf("Antes da ordenação e atribuição de ranks:\n");
	print_stack(head);
	return (head);
}

t_node	*create_empty_stack(void)
{
	t_node	*stackb;

	stackb = NULL;
	return (stackb);
}

int	main(int argc, char *argv[])
{
	t_node	*stackA;
	t_node	*stackB;
	t_node	*stackSort;

	stackA = create_stackA(argc, argv);
	stackB = create_empty_stack();
	stackSort = create_empty_stack();
	// Transfere os nodes de A para Sort (sem alterar a ordem)
	copy_stack(stackA, &stackSort);
	// Ordena e atribui ranks na stackSort
	assign_ranks(stackSort);
	// Copia os ranks da stackSort para a stackA (sem alterar a ordem de stackA)
	assign_ranks_to_stackA(stackA, stackSort);
	// Vou apagar a stackSort
	deletlist(stackSort);
	// Lista apos atribuição dos ranks
	printf("-------------- Stack A After --------------\n");
	print_stack_ranks(stackA);
	printf("-------------- RA Test--------------\n");
	pb(&stackA,&stackB);
	pb(&stackA,&stackB);
	pb(&stackA,&stackB);
	printf("-------------- Stack A--------------\n");
	print_stack_ranks(stackA);
	printf("-------------- Stack B--------------\n");
	print_stack_ranks(stackB);
	return (0);
}
