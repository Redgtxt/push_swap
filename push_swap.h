#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	int				data;
	int				index;
	int				rank;
	struct s_node	*next;
}					t_node;

//Debug
void	print_stack(t_node *stack);
void	print_stack_ranks(t_node *stack);
//Input arguments
void				write_error(void);
int					is_digit_str(char *str);
int					ft_safe_atoi(char *str);
void				check_duplicate(t_node *head, int num);
void				argv_convert_builder(int argc, char *argv[], t_node **head);

//Stack Related
void				add_to_list(t_node **head, int content, int index);
t_node				*ft_newnode(int content, int index);
t_node	*create_stackA(int argc, char *argv[]);
t_node	*create_empty_stack(void);
void	move_stack(t_node **src, t_node **dest);
void	copy_stack(t_node *src, t_node **dest);

// Funcoes buble sort && Rank
void				swap_nodes(t_node *a, t_node *b);
void				assign_ranks(t_node *head);
void				sort_list(t_node *head);
void	assign_ranks_to_stackA(t_node *stackA, t_node *stackSort);
// mvoes
void				sa(t_node **head);
void				sb(t_node **head);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
#endif
