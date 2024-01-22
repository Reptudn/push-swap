/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:42:33 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/09 14:08:44 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./lib/ft_printf/ft_printf.h"
# include "./lib/libft/libft.h"

# define PACK_SIZE 10

typedef struct s_stack_element
{
	int						*num;
	struct s_stack_element	*next;
	struct s_stack_element	*previous;
}							t_stack_element;

typedef struct s_stacks
{
	t_stack_element	*a;
	t_stack_element	*b;
	int				*size;
}					t_stacks;

// stack utils
t_stack_element	*stack_new(int value);
void			stack_push(t_stack_element *stack, t_stack_element *new_elem);
t_stack_element	*stack_get_first(t_stack_element *stack);
t_stack_element	*stack_get_last(t_stack_element *stack);
int				get_stack_size(t_stack_element *stack);

int				clear_contents(char **contents, int i);

void			pb(t_stacks *stacks, int print);
void			pa(t_stacks *stacks, int print);
void			ra(t_stacks *stacks, int print);
void			rb(t_stacks *stacks, int print);
void			rr(t_stacks *stacks, int print);
void			rra(t_stacks *stacks, int print);
void			rrb(t_stacks *stacks, int print);
void			rrr(t_stacks *stacks, int print);
void			sa(t_stacks *stacks, int print);
void			sb(t_stacks *stacks, int print);
void			ss(t_stacks *stacks, int print);

void			sort_stack(t_stacks *stacks);

int				get_smallest_num(t_stack_element *stack);
int				get_biggest_num_index(t_stack_element *stack);
int				get_second_biggest_index(t_stack_element *stack, int biggest);
int				ft_min(int num1, int num2);
int				get_biggest_number(t_stack_element *stack);

void			log_error(long *stack_a, long *stack_b);
int				ft_isnumber(char *str);	
void			stack_list_clear(t_stacks *stacks);
void			print_stacks(t_stacks *stacks);

int				is_valid_input(char **argv, int argc);
int				args_to_stack(int argc, char **argv, t_stacks *stacks);
int				setup_second_stack(long *stack_b, long *stack_a, int *size);
int				is_integer(const char *nptr);

int				get_index_of_smallest_num(long *stack, int *size);
int				get_index_of_num(long *stack, long num, int *size);
int				get_curr_stack_height(long *stack, int *size);
int				is_stack_empty(long *stack, int *size);

int				is_sorted(t_stacks *stacks);
int				is_stack_sorted(t_stack_element *stack);

int				has_smaller_number(t_stack_element *stack, int key_number);
int				get_next_num_index(t_stack_element *stack, int key_number);
int				get_key_number(t_stack_element *stack, int call,
					int pack_size, int *stop);
void			sort_five(t_stacks *stacks);
void			sort_three(t_stacks *stacks);

#endif