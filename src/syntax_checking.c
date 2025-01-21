#include "push_swap.h"

static int    is_digit_str(char *str)
{
    int    i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i + 1] == '-' || str[i + 1] == '+')
            return (-1);
        i++;
    }
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (-1);
        i++;
    }
    return (0);
}

static int    ft_safe_atoi(char *str)
{
    int    i;
    int    neg;
    long    num;

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

static int    check_duplicate(t_node *head, int num)
{
    t_node    *current;

    current = head;
    while (current)
    {
        if (current->data == num)
            return (-1);
        current = current->next;
    }
    return (0);
}

static int process_number(char *str, t_node **head)
{
    int num;

    if (is_digit_str(str) == -1)
        return (-1);
    num = ft_safe_atoi(str);
    if (check_duplicate(*head, num) == -1)
        return (-1);
    add_to_list(head, num);
    return (0);
}


static int process_split_array(char **split_argv, t_node **head)
{
    int j;

    j = 0;
    while (split_argv[j])
    {
        if (process_number(split_argv[j], head) == -1)
            return (-1);
        j++;
    }
    return (0);
}

void    argv_convert_builder(int argc, char *argv[], t_node **head)
{
    int        i;
    char    **split_argv;

    i = 1;
    while (i < argc)
    {
        split_argv = ft_split(argv[i], ' ');
        if (!split_argv || !split_argv[0])
        {
            free_double_array(split_argv);
            write_error();
        }
        if (process_split_array(split_argv, head) == -1)
        {
            deletlist(*head);
            free_double_array(split_argv);
            write_error();
        }
        free_double_array(split_argv);
        i++;
    }
}
