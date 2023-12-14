/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:42:33 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 14:26:43 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./lib/ft_printf/ft_printf.h"
# include "./lib/libft/libft.h"

# define ERROR "Error\n"
# define NORMAL_SIZE 500

typedef struct s_stack
{
	int			*stack;
	int			size;
}				t_stack;

void	pa(int *a, int *b, int *size, int print);
void	pb(int *b, int *a, int *size, int print);
void	ra(int *stack_a, int *size, int print);
void	rb(int *stack_b, int *size, int print);
void	rr(int *stack_a, int *stack_b, int *size);
void	rra(int *stack_a, int *size, int print);
void	rrb(int *stack_b, int *size, int print);
void	rrr(int *stack_a, int *stack_b, int *size);
void	sa(int *stack_a, int print);
void	sb(int *stack_b, int print);
void	ss(int *stack_a, int *stack_b);

void	sort_stack(int *a, int *b, int *size);

void	log_error(int *stack_a, int *stack_b);
int		ft_isnumber(char *str);
void	end_program(int *stack_a, int *stack_b);
void	print_stacks(int *stack_a, int *stack_b, int *size);

int		is_valid_input(char **argv, int argc);
int		args_to_stack(int argc, char **argv, int *stack, int *size);
int		setup_second_stack(int *stack_b, int *stack_a, int *size);

int		get_index_of_smallest_num(int *stack, int *size);
int		is_stack_empty(int *stack, int *size);

#endif