/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguerrei < hguerrei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:42:55 by hguerrei          #+#    #+#             */
/*   Updated: 2025/02/10 14:11:50 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_stacka(int argc, char *argv[])
{
	t_node	*head;

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

int	main(int argc, char *argv[])
{
	t_node	*stacka;
	t_node	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	stacka = create_stacka(argc, argv);
	stackb = create_empty_stack();
	if (!is_sorted(stacka))
	{
		if (stacklen(stacka) == 2)
		{
			sa(&stacka, true);
		}
		else if (stacklen(stacka) == 3)
		{
			sort_three(&stacka);
		}
		else
			sort_stacks(&stacka, &stackb);
	}
	deletlist(stacka);
	deletlist(stackb);
	return (0);
}
