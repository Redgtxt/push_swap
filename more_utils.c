#include "push_swap.h"

void	deletlist(t_node *node)
{
	if (node == NULL)
		return ;
	deletlist(node->next);
	free(node);
}
