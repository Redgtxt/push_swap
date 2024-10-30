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
	int		num_elements;
	int		chunks;
    int i;
	stackA = create_stackA(argc, argv);
	stackB = create_empty_stack();
	stackSort = create_empty_stack();
	num_elements = stacklen(stackA);
	chunks = calculate_chunks(num_elements) - 1;
	// Copia e ordena os ranks de StackA em StackSort
	copy_stack(stackA, &stackSort);
	assign_ranks(stackSort);
	assign_ranks_to_stackA(stackA, stackSort);
	deletlist(stackSort);
	// Divide os elementos em grupos (chunks)
	assign_chunks(stackA);

    print_stack_chunks(stackA);
    
    i = 0;
    while (i <= chunks)
    {

    move_current_chunk_to_stackB(&stackA,&stackB,i);
    i++;
    }

	// Loop para processar e mover cada chunk para StackB e então de volta para StackA
	// Exibe o estado final das pilhas
	 printf("-------------- Stack A--------------\n");
	 print_stack_chunks(stackA);
	printf("-------------- Stack B--------------\n");
	 print_stack_chunks(stackB);
	deletlist(stackA);
	deletlist(stackB);
	return (0);
}
