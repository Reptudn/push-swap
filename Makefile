NAME	:= push_swap
SRC_DIR	:= ./src/
OPERATIONS :=	operations/push.c \
				operations/rotate.c \
				operations/reverse_rotate.c \
				operations/swap.c
SRC		:= 	$(SRC_DIR)log.c \
			$(SRC_DIR)main.c \
			$(SRC_DIR)check.c \
			$(SRC_DIR)algorithm.c \
			$(SRC_DIR)algorithm_new.c \
			$(SRC_DIR)utils.c \
			$(SRC_DIR)leakfree.c \
			$(SRC_DIR)stack_utils.c \
			$(SRC_DIR)args_to_stack.c \
			$(SRC_DIR)atolong.c \
			$(OPERATIONS)
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
	@rm -rf $(SRC_DIR)*.o ./operations/*.o

fclean: clean
	@make -C ./lib/libft fclean
	@make -C ./lib/ft_printf fclean
	@rm -rf $(NAME)

re: fclean all

# $@ - target
# $^ - all dependencies