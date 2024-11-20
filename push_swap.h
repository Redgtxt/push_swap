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

#endif
