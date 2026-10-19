/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguerrei < hguerrei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:42:39 by hguerrei          #+#    #+#             */
/*   Updated: 2025/02/10 14:07:38 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_node *stack)
{
	int		min;
	t_node	*min_node;

	if (!stack)
		return (NULL);
	min = stack->data;
	min_node = stack;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_node	*find_max(t_node *stack)
{
	int		max;
	t_node	*max_node;

	if (!stack)
		return (NULL);
	max = stack->data;
	max_node = stack;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

static void	check_empty_str(t_node *head, char **all_str, char *str, int i)
{
	if (!str[i])
	{
		deletlist(head);
		free_double_array(all_str);
		write_error();
	}
}

static void	check_num_limits(long num, int neg, t_node *head, char **all_str)
{
	if (num * neg > INT_MAX || num * neg < INT_MIN)
	{
		deletlist(head);
		free_double_array(all_str);
		write_error();
	}
}

int	ft_safe_atoi(t_node *head, char **all_str, char *str)
{
	int		i;
	int		neg;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	check_empty_str(head, all_str, str, i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (str[i] - '0') + (num * 10);
		check_num_limits(num, neg, head, all_str);
		i++;
	}
	return (num * neg);
}
