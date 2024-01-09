NAME	:= push_swap
SRC		:= 	./log.c \
			./main.c \
			./check.c \
			./algorithm.c \
			./utils.c \
			./leakfree.c \
			./stack_utils.c \
			./args_to_stack.c \
			./operations/push.c \
			./operations/rotate.c \
			./operations/reverse_rotate.c \
			./operations/swap.c
CFLAGS	:= -Wall -Wextra -Werror
CC		:= cc
INCLUDE	:= -I./lib/libft/libft.a -I./lib/ft_printf/libftprintf.a 
LIBS	:= -L./lib/libft -L./lib/ft_printf -lft -lftprintf

.PHONY: all clean fclean

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(SRC:.c=.o)
	@make -C ./lib/libft
	@make -C ./lib/ft_printf
	@$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIBS) -o $@

clean:
	@make -C ./lib/libft clean
	@make -C ./lib/ft_printf clean
	@rm -rf ./*.o ./operations/*.o

fclean: clean
	@make -C ./lib/libft fclean
	@make -C ./lib/ft_printf fclean
	@rm -rf $(NAME)

re: fclean all name

# $@ - target
# $^ - all dependencies