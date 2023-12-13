NAME	:= push_swap
SRC		:= 	./log.c \
			./main.c \
			./check.c \
			./algorithm.c \
			./operations/pa.c \
			./operations/pb.c \
			./operations/ra.c \
			./operations/rb.c \
			./operations/rr.c \
			./operations/rra.c \
			./operations/rrb.c \
			./operations/rrr.c \
			./operations/sa.c \
			./operations/sb.c \
			./operations/ss.c
CFLAGS	:= -Wall -Wextra -Werror
CC		:= cc
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

re: fclean all name

# $@ - target (like $(SERVER) and $(CLIENT))
# $^ - all dependencies (like server.o and client.o)