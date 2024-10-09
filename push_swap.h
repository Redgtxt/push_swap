#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft/libft.h"
#include <stdio.h>

typedef	struct s_node
{
  int data;
  int index;
  int rank;
  struct s_node *next;
}	t_node;

void	write_error(void);
t_node	*ft_newnode(int content, int index);
int	is_digit_str(char *str);
int ft_safe_atoi(char *str);
void	check_duplicate(t_node *head, int num);
void add_to_list(t_node **head, int content, int index);
void	argv_convert_builder(int argc, char *argv[], t_node **head);
void sa(t_node **head);


void swap_nodes(t_node *a, t_node *b);
void assign_ranks(t_node *head);
void sort_list(t_node *head);
#endif

