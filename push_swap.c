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

// int main(int argc, char *argv[])
// {
// 	t_node *node;
// 	if(argc - 1 <= 1)
// 		write_error();
// 	node = ft_newnode();
// 	printf("Content of the node: %d\n", node->data);
// }


/* First Step Parsing

	Vou receber os inputs
X			Vou verificar a quantidade de inputs
X			Se for so 1 input vou dar erro(A mensagem de erro tem de ser feita no fd 2)
		Agora vou filtar os inputs
			Se for uma string vou dar erro
			Se for maior do que int vou dar erro
			Se os numeros forem repetidos vou dar erro
*/
