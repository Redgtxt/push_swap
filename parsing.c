#include "push_swap.h"

//Verifica se tem alguma letra ATENCAO QUE ELE NAO VE MULTIPLOS SINAIS
int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
//continua sem checar sinais
int safe_atoi(char *str)
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
		if (num * neg > INT_MAX || num * neg < INT_MIN)
			write_error();
		i++;
	}
	return (num * neg);
}

int main(void)
{
	//printf("%d",is_digit_str("+232"));
	printf("%d",safe_atoi("++232"));
}
