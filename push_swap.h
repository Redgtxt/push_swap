#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
#include <stdbool.h>
#include <limits.h>

typedef struct s_node
{
	int				data;
	int				index;
	int				rank;
	struct s_node	*next;
	int chunk;
}					t_node;



#endif
