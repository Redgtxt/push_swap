#include "push_swap.h"

void write_error(void)
{
	write(2,"Error\n",6);
	exit(0);
}

t_node	*ft_newnode(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = content;
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
		is_digit_str(argv[i]);
		num = ft_safe_atoi(argv[i]);
		check_duplicate(head, num);
		add_to_list(&head, num);
		i++;
	}

	// Teste para verificar os valores adicionados na lista
	t_node *temp = head;
	while (temp)
	{
		printf("Content of the node: %d\n", temp->data);
		temp = temp->next;
	}
	return (0);
}



/* First Step Parsing

	Vou receber os inputs
X			Vou verificar a quantidade de inputs
X			Se for so 1 input vou dar erro(A mensagem de erro tem de ser feita no fd 2)
		Agora vou filtar os inputs
			Se for uma string vou dar erro
			Se for maior do que int vou dar erro
			Se os numeros forem repetidos vou dar erro
*/
