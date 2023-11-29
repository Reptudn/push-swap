NAME	:= push_swap
SRC		:= ./log.c \
			main.c
CFLAGS	:= -Wall -Wextra -Werror
CC		:= gcc
INCLUDE	:= -I./lib/libft/libft.a -I./lib/ft_printf/libftprintf.a 
LIBS	:= -L./lib/libft -L./lib/ft_printf -lft -lftprintf

.PHONY: all clean fclean

all: $(NAME)

%.o: %.c
	@make -C ./lib/libft
	@make -C ./lib/ft_printf
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ && printf "Compiled $<\n"

$(NAME): $(SRC:.c=.o)
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIBS) -o $@ && printf "Compiled $@\n"

clean:
	@make -C ./lib/libft clean
	@make -C ./lib/ft_printf clean
	rm -f *.o && printf "Cleaned\n"

fclean: clean
	@make -C ./lib/libft fclean
	@make -C ./lib/ft_printf fclean
	rm -f $(SERVER) $(CLIENT) && printf "Cleaned everything\n"

re: fclean all

# $@ - target (like $(SERVER) and $(CLIENT))
# $^ - all dependencies (like server.o and client.o)