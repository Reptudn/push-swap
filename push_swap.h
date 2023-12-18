/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:42:33 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/18 15:27:03 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./lib/ft_printf/ft_printf.h"
# include "./lib/libft/libft.h"

# define NOTHING 5000000000
# define NORMAL_SIZE 500

void	pa(long *a, long *b, int *size, int print);
void	pb(long *b, long *a, int *size, int print);
void	ra(long *stack_a, int *size, int print);
void	rb(long *stack_b, int *size, int print);
void	rr(long *stack_a, long *stack_b, int *size);
void	rra(long *stack_a, int *size, int print);
void	rrb(long *stack_b, int *size, int print);
void	rrr(long *stack_a, long *stack_b, int *size);
void	sa(long *stack_a, int *size, int print);
void	sb(long *stack_b, int *size, int print);
void	ss(long *stack_a, int *size, long *stack_b);

void	sort_stack(long *a, long *b, int *size);
void	k_sort(long *a, long *b, int size, int k);

void	log_error(long *stack_a, long *stack_b);
int		ft_isnumber(char *str);
void	end_program(long *stack_a, long *stack_b);
void	print_stacks(long *stack_a, long *stack_b, int *size);

int		is_valid_input(char **argv, int argc);
int		args_to_stack(int argc, char **argv, long *stack, int *size);
int		setup_second_stack(long *stack_b, long *stack_a, int *size);

int		get_index_of_smallest_num(long *stack, int *size);
int		is_stack_empty(long *stack, int *size);

#endif