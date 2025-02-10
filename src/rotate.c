/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguerrei < hguerrei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:43:28 by hguerrei          #+#    #+#             */
/*   Updated: 2025/02/10 13:43:29 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !(*head) || !((*head)->next))
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_node **head, bool print)
{
	rotate(head);
	if (print == true)
		ft_printf("ra\n");
}

void	rb(t_node **head, bool print)
{
	rotate(head);
	if (print == true)
		ft_printf("rb\n");
}

void	rr(t_node **headA, t_node **headB, bool print)
{
	rotate(headA);
	rotate(headB);
	if (print == true)
		ft_printf("rr\n");
}

void	rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rr(stack_a, stack_b, true);
	current_index(*stack_a);
	current_index(*stack_b);
}
