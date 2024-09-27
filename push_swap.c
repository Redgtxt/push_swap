#include "push_swap.h"

void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

t_node	*ft_newnode(int content, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = content;
	node->index = index;
	node->next = NULL;
	return (node);
}

int	main(int argc, char *argv[])
{
	t_node	*head;
	t_node	*temp;

	head = NULL;
	if (argc - 1 <= 0)
		write_error();

    argv_convert_builder(argc,argv,&head);
	temp = head;
	while (temp)
	{
		printf("Node index: [%d], Data: %d\n", temp->index, temp->data);
		temp = temp->next;
	}
	return (0);
}
