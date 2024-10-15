#include "push_swap.h"

void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
//Cria node
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
//Printa uma stack
void	print_stack(t_node *stack)
{
	t_node	*temp;

	if (!stack)
	{
		ft_printf("A stack está vazia.\n");
		return;
	}

	temp = stack;
	ft_printf("Conteúdo da stack:\n");
	while (temp)
	{
		ft_printf("Node index: [%d], Data: %d\n", temp->index, temp->data);
		temp = temp->next;
	}
}

void	print_stack_ranks(t_node *stack)
{
	t_node	*temp;

	if (!stack)
	{
		ft_printf("A stack está vazia.\n");
		return;
	}

	temp = stack;
	ft_printf("Conteúdo da stack Rank:\n");
	while (temp)
	{
		ft_printf("Node index: [%d], Data: %d, Rank: %d\n", temp->index, temp->data,temp->rank);
		temp = temp->next;
	}
}
//Passa o conteudo de uma stack para outra(a src vai ficar vazia)
void	move_stack(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!(*src))
	{
		ft_printf("A stack de origem está vazia.\n");
		return;
	}

	while (*src)
	{
		// Armazena temporariamente o próximo node
		temp = (*src)->next;

		// Move o node atual de src para dest
		(*src)->next = *dest;
		*dest = *src;

		// Atualiza src para o próximo node
		*src = temp;
	}

	ft_printf("Todas as nodes foram movidas com sucesso.\n");
}
//Vai copiar uma stack
void	copy_stack(t_node *src, t_node **dest)
{
	t_node	*temp;
	t_node	*new_node;

	temp = src;
	while (temp)
	{
		// Cria um novo node para a stack de destino
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			write_error();  // Lida com erro de alocação de memória
		new_node->data = temp->data;
		new_node->index = temp->index;
		new_node->next = *dest;

		*dest = new_node;

		temp = temp->next;
	}

	ft_printf("A stack foi copiada com sucesso.\n");
}
