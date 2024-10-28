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
	int chunk;
}					t_node;

//Debug
void	print_stack(t_node *stack);
void	print_stack_ranks(t_node *stack);
void	print_stack_chunks(t_node *stack);

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
void	deletlist(t_node *node);
int	stacklen(t_node *head);

// Funcoes buble sort && Rank
void				swap_nodes(t_node *a, t_node *b);
void				assign_ranks(t_node *head);
void				sort_list(t_node *head);
void	assign_ranks_to_stackA(t_node *stackA, t_node *stackSort);


//Algoritm Chunck sorting
int calculate_chunks(int num_elements);
void assign_chunks(t_node *head);
void   move_current_chunk_to_stackB(t_node **stackA, t_node **stackB, int current_chunk);
int find_max_position(t_node *stackB);
void transfer_chunk_to_stackA(t_node **stackA, t_node **stackB);
int is_sorted(t_node *stackA);

// moves
void				sa(t_node **head);
void				sb(t_node **head);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **head);
void	rb(t_node **head);
void	rra(t_node **head);
void	rrb(t_node **head);


#endif
