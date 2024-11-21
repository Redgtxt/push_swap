#include "push_swap.h"


int	main(int argc, char *argv[])
{

	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

  if(argc == 1 || (argc == 2 && !argv[1][0]))
  	return (1);
  else if(argc == 2)
    argv = ft_split_modded(argv[1], ' ');
stack_init(&a,argv + 1,2 ==  argc);
if (!stack_sorted(a))
	{
		if (stacklen(a) == 2)
			sa(&a, false);
		else if (stacklen(a) == 3)
			sort_tree(&a);
		else
			push_swap(&a, &b);
	}
    print_stack(a);
	free_stack(&a);
	return (0);
}