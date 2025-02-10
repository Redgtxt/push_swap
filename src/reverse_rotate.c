/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguerrei < hguerrei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:43:21 by hguerrei          #+#    #+#             */
/*   Updated: 2025/02/10 14:07:20 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !(*head) || !((*head)->next))
		return ;
	first = *head;
	while (first->next)
		first = first->next;
	last = first;
	first = *head;
	*head = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
}

void	rra(t_node **head, bool print)
{
	reverse_rotate(head);
	if (print == true)
		ft_printf("rra\n");
}

void	rrb(t_node **head, bool print)
{
	reverse_rotate(head);
	if (print == true)
		ft_printf("rrb\n");
}

void	rrr(t_node **headA, t_node **headB, bool print)
{
	reverse_rotate(headA);
	reverse_rotate(headB);
	if (print == true)
		ft_printf("rrr\n");
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b,
		t_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rrr(stack_a, stack_b, true);
	current_index(*stack_a);
	current_index(*stack_b);
}
