/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguerrei < hguerrei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:43:00 by hguerrei          #+#    #+#             */
/*   Updated: 2025/02/10 14:14:58 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_chepeast(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

void	move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*chepeast_node;

	chepeast_node = get_chepeast(*stack_a);
	if (chepeast_node->above_median && chepeast_node->target_node->above_median)
		rotate_both(stack_a, stack_b, chepeast_node);
	else if (!(chepeast_node->above_median)
		&& !(chepeast_node->target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, chepeast_node);
	prep_for_push(stack_a, chepeast_node, 'a');
	prep_for_push(stack_b, chepeast_node->target_node, 'b');
	pb(stack_a, stack_b, true);
}

static void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_a;
	t_node	*target_node;
	int		best_match_index;

	while (stack_b)
	{
		best_match_index = INT_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->data > stack_b->data
				&& current_a->data < best_match_index)
			{
				best_match_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MAX)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_nodes_b(t_node *stack_a, t_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
