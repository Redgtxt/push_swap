#include "push_swap.h"

void write_error(void)
{
	write(2,"Error\n",6);
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
    t_node *head = NULL;
    int i;
    int num;

    if (argc - 1 <= 1)
        write_error();

    i = 1;
    while (i < argc)
    {
        if (!is_digit_str(argv[i]))
            write_error();
        num = ft_safe_atoi(argv[i]);
        check_duplicate(head, num);
        add_to_list(&head, num, i - 1);  // Passa o índice i - 1 para começar do zero
        i++;
    }
    t_node *temp = head;
    while (temp)
    {
        printf("Node data: %d, Index: %d\n", temp->data, temp->index);
        temp = temp->next;
    }
    return (0);
}


