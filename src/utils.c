#include "push_swap.h"

void free_double_array(char *array[])
{
    int i;

    if (array == NULL)
        return;

    i = 0;
    while (array[i] != NULL)
    {
        free(array[i]);
        array[i] = NULL;
        i++;
    }

    free(array);
}

void    print_double_array(char *array[])
{
	int	i;

	if (!array) 
		return ;
	i = 0;
	while (array[i]) 
	{
		ft_printf("%s\n", array[i]); 
		i++;
	}
}

void    write_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void print_stack(t_node *stack)
{
    t_node *temp;

    if (!stack)
    {
        ft_printf("A stack está vazia.\n");
        return;
    }
    temp = stack;
    while (temp)
    {
        ft_printf(" Data: %d\n", temp->data);
        temp = temp->next;
    }
}

bool is_sorted(t_node *stack)
{
    if (!stack || !stack->next)
        return (true);

    while (stack->next)
    {
        if (stack->data > stack->next->data)
            return (false);
        stack = stack->next;
    }
    ft_printf("Stack está ordenada\n");
    return (true);
}