#include "push_swap.h"

t_node	*create_stackA(int argc, char *argv[])
{
	t_node	*head;

	head = NULL;
	if (argc - 1 <= 0)
		write_error();
	argv_convert_builder(argc, argv, &head);
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

	//Vou dividir os meus elementos em grupos
	assign_chunks(stackA);

	move_current_chunk_to_stackB(&stackA,&stackB,2);
	transfer_chunk_to_stackA(&stackA,&stackB);
	
	move_current_chunk_to_stackB(&stackA,&stackB,1);
	transfer_chunk_to_stackA(&stackA,&stackB);
	
	move_current_chunk_to_stackB(&stackA,&stackB,0);
	transfer_chunk_to_stackA(&stackA,&stackB);
	printf("-------------- Stack A--------------\n");
	print_stack_ranks(stackA);
	printf("-------------- Stack B--------------\n");
	print_stack_chunks(stackB);
	printf("--------------Stack A--------------\n");
	print_stack_chunks(stackA);
	if(is_sorted(stackA))
	{
		printf("Estamos em um bom caminho\n");
	}
	deletlist(stackA);
	deletlist(stackB);

	return (0);
}
