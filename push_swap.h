/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:42:33 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 10:45:23 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./lib/ft_printf/ft_printf.h"
# include "./lib/libft/libft.h" 

# define ERROR "Error\n"

typedef struct s_stack
{
	int			*stack;
	int			size;
}				t_stack;

void	pa(t_stack *a, t_stack *b, int print);
void	pb(t_stack *b, t_stack *a, int print);
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	sort_stack(t_stack *a, t_stack *b);

void	log_error(t_stack *stack_a, t_stack *stack_b);
int		ft_isnumber(char *str);
void	end_program(t_stack *stack_a, t_stack *stack_b);
void	print_stacks(int *stack_a, int *stack_b, int *size);

int		is_valid_input(char **argv, int argc);
int		args_to_stack(int argc, char **argv, int *stack, int *size);
int		setup_second_stack(int *stack_b, int *stack_a, int *size);

#endif