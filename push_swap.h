#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdbool.h>
#include <limits.h>

typedef struct s_node
{
	int             value;
	int             current_position;
	int             final_index;
	int             push_price;
	bool            above_median;
	bool            cheapest;
	struct s_node   *target_node;
	struct s_node   *next;
	struct s_node   *prev;
}               t_node;

//Debug
void	print_stack(t_node *stack);
int	stacklen(t_node *head); 
bool stack_sorted(t_node *stack);
char	**ft_split_modded(char *str, char separator);
void	stack_init(t_node **a, char **argv, bool flag_argc_2);

//Parsing Related
void	free_matrix(char **argv);
void	free_stack(t_node **stack);
void	error_free(t_node **a, char **argv, bool flag_argc_2);
int	error_syntax(char *str_nbr);
int	check_duplicate(t_node *a, int nbr);
void	append_node(t_node **stack, int nbr);
t_node	*find_last_node(t_node *head);

//Value for nodes
void	set_current_position(t_node *stack);
void	set_price(t_node *a, t_node *b);
void	set_cheapest(t_node *b);
void	init_nodes(t_node *a, t_node *b);
t_node	*find_smallest(t_node *stack);
t_node	*return_cheapest(t_node *stack);
void	finish_rotation(t_node **stack,	t_node *top_node, char stack_name);
//Algoritm
void	sort_tree(t_node **a);
void	handle_five(t_node **a, t_node **b);
void	push_swap(t_node **a, t_node **b);
//Moves
void				sa(t_node **head, bool print);
void				sb(t_node **head, bool print);
void	ss(t_node **a, t_node **b, bool print);
void				pa(t_node **stack_a, t_node **stack_b, bool print);
void				pb(t_node **stack_a, t_node **stack_b, bool print);
void				ra(t_node **head, bool print);
void				rb(t_node **head, bool print);
void rr(t_node **stack_a, t_node **stack_b, bool print);
void				rra(t_node **head, bool print);
void				rrb(t_node **head, bool print);
void rrr(t_node **stack_a, t_node **stack_b, bool print);
#endif
