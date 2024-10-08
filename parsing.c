#include "push_swap.h"

// Verifica se tem alguma letra
int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			write_error();
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			write_error();
		i++;
	}
	return (1);
}
// Atoi diferenciado ehehehe
int	ft_safe_atoi(char *str)
{
	int	i;
	int	neg;
	int	num;

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
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (str[i] - '0') + (num * 10);
		if (num * neg > 2147483647 || num * neg < -2147483647)
			write_error();
		i++;
	}
	return (num * neg);
}

void	argv_convert_builder(int argc, char *argv[], t_node **head)
{
	int		i;
	int		index;
	int		j;
	int		num;
	char	**split_argv;

	i = 1;
	index = 0;
	while (i < argc)
	{
		split_argv = ft_split(argv[i], ' ');
		j = 0;
		while (split_argv[j])
		{
			if (!is_digit_str(split_argv[j]))
				write_error();
			num = ft_safe_atoi(split_argv[j]);
			check_duplicate(*head, num);
			add_to_list(head, num, index);
			j++;
			index++;
		}
		free(split_argv);
		i++;
	}
}


void	check_duplicate(t_node *head, int num)
{
	t_node	*temp;

	temp = head;
	while (temp)
	{
		if (temp->data == num)
			write_error();
		temp = temp->next;
	}
}
void	add_to_list(t_node **head, int content, int index)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = ft_newnode(content, index);
	temp = *head;
	if (!(*head))
		*head = new_node;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}
