#include "push_swap.h"

t_node *create_stackA(int argc, char *argv[])
{
    t_node *head;

    head = NULL;
    argv_convert_builder(argc, argv, &head);

    if (!head)
        write_error();
        
    return (head);
}

t_node	*create_empty_stack(void)
{
	t_node	*stackb;

	stackb = NULL;
	return (stackb);
}
/*  TODO
    [] Dar sort em 3
    [] Dar sort em listas de numeros
*/
int main(int argc,char *argv[])
{
    t_node *stackA;
    t_node *stackB;

    stackA = NULL;
    stackB = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);

    stackA = create_stackA(argc, argv);
    stackB = create_empty_stack();

    if(is_sorted(stackA))
    {
        deletlist(stackA);
        deletlist(stackB);
        return (0);
    }else
    {
        ft_printf("Stack A não está ordenada\n");
    }
    print_stack(stackA);
    pb(&stackA,&stackB, true);
    print_stack(stackA);
    printf("-------------- Stack B--------------\n");
	print_stack(stackB); 
    deletlist(stackA);
    return (0);
}
