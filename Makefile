NAME = push_swap

SRC = src/main.c src/utils.c src/syntax_checking.c src/list_functions.c src/swap.c src/push.c src/rotate.c src/reverse_rotate.c src/sort_three.c src/find_stuff.c src/init_nodes_a.c src/move_nodes.c
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

OBJDIR = ./obj
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)
OBJS_BONUS = $(SRC_BONUS:%.c=$(OBJDIR)/%.o)

CC = cc
FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/src

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all