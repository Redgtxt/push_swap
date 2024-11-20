#include "push_swap.h"
/*
int	main(int argc, char *argv[])
{

	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

  if(argc == 1 || (argc == 2 && !argv[1][0]))
  {
  	return (1);
  }else if(argc == 2)
    argv = ft_split(argv[1], ' ');


	return (0);
}
*/
#include <stdio.h>
#include "libft/libft.h"

int main(int argc, char **argv)
{
	char **split_argv = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		split_argv = ft_split(argv[1], ' ');

	if (argc > 2) // Vários argumentos passados diretamente
	{
		for (int i = 1; i < argc; i++)
			printf("Arg %d: %s\n", i, argv[i]);
	}
	else if (split_argv) // Argumentos divididos por ft_split
	{
		for (int i = 0; split_argv[i]; i++)
			printf("Split Arg %d: %s\n", i, split_argv[i]);

		// Libere a memória alocada por ft_split, se necessário
		for (int i = 0; split_argv[i]; i++)
			free(split_argv[i]);
		free(split_argv);
	}

	return 0;
}
