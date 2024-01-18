NAME	:= push_swap
NAME_BON := checker
SRC_DIR	:= ./src/
OPERATIONS :=	operations/push.c \
				operations/rotate.c \
				operations/reverse_rotate.c \
				operations/swap.c
SRC		:= 	$(SRC_DIR)log.c \
			$(SRC_DIR)main.c \
			$(SRC_DIR)check.c \
			$(SRC_DIR)algorithm.c \
			$(SRC_DIR)utils.c \
			$(SRC_DIR)leakfree.c \
			$(SRC_DIR)stack_utils.c \
			$(SRC_DIR)stack_utils2.c \
			$(SRC_DIR)args_to_stack.c \
			$(SRC_DIR)atolong.c \
			$(SRC_DIR)algorithm_sort.c \
			$(SRC_DIR)algorithm_utils.c \
			$(SRC_DIR)keynumbers.c \
			$(OPERATIONS)
SRC_BON	:= 	$(OPERATIONS) \
			$(SRC_DIR)checker.c \
			$(SRC_DIR)log.c \
			$(SRC_DIR)check.c \
			$(SRC_DIR)utils.c \
			$(SRC_DIR)leakfree.c \
			$(SRC_DIR)stack_utils.c \
			$(SRC_DIR)stack_utils2.c \
			$(SRC_DIR)args_to_stack.c \
			$(SRC_DIR)atolong.c \
			$(SRC_DIR)log.c \
			$(SRC_DIR)check.c \
			$(SRC_DIR)algorithm.c \
			$(SRC_DIR)utils.c \
			$(SRC_DIR)leakfree.c \
			$(SRC_DIR)stack_utils.c \
			$(SRC_DIR)stack_utils2.c \
			$(SRC_DIR)args_to_stack.c \
			$(SRC_DIR)atolong.c \
			$(SRC_DIR)algorithm_sort.c \
			$(SRC_DIR)algorithm_utils.c \
			$(SRC_DIR)keynumbers.c \
			$(OPERATIONS)
CFLAGS	:= -Wall -Wextra -Werror
CC		:= cc
INCLUDE	:= -I./lib/libft/libft.a -I./lib/ft_printf/libftprintf.a
BONUS_LIBS	:= ./lib/get_next_line/get_next_line.a ./lib/libft/libft.a
LIBS	:= -L./lib/libft -L./lib/ft_printf -lft -lftprintf

.PHONY: all clean fclean

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(SRC:.c=.o)
	@make -C ./lib/libft
	@make -C ./lib/ft_printf
	@make -C ./lib/get_next_line
	@$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIBS) -o $@

bonus: $(SRC_BON:.c=.o)
	@make -C ./lib/libft
	@make -C ./lib/ft_printf
	@make -C ./lib/get_next_line
	@$(CC) $(CFLAGS) $(INCLUDE) $(BONUS_LIBS) $^ $(LIBS) -o $(NAME_BON)

clean:
	@make -C ./lib/libft clean
	@make -C ./lib/ft_printf clean
	@make -C ./lib/get_next_line clean
	@rm -rf $(SRC_DIR)*.o ./operations/*.o

fclean: clean
	@make -C ./lib/libft fclean
	@make -C ./lib/ft_printf fclean
	@make -C ./lib/get_next_line fclean
	@rm -rf $(NAME_BON)
	@rm -rf $(NAME)

re: fclean all

# $@ - target
# $^ - all dependencies