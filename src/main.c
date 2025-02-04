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

    if(!is_sorted(stackA))
    {
        if(stacklen(stackA) == 2)
        {
            sa(&stackA, true);
        }else if(stacklen(stackA) == 3)
        {
            sort_three(&stackA);
        }else
            sort_stacks(&stackA, &stackB);
    }

    deletlist(stackA);
    deletlist(stackB);
    return (0);
}
