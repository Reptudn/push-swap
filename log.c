/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:42:02 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 10:51:05 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	print_stacks(int *stack_a, int *stack_b, int *size)
{
	int		i;

	i = -1;
	ft_printf("a\tb\n-\t-\n");
	while (++i < *size)
		ft_printf("%d\t%d\n", stack_a[i], stack_b[i]);
}

void	log_error(t_stack *stack_a, t_stack *stack_b)
{
	write(2, "Error\n", 7);
	end_program(stack_a, stack_b);
}

void	end_program(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->stack)
		free(stack_a->stack);
	if (stack_a)
		free(stack_a);
	if (stack_b && stack_b->stack)
		free(stack_b->stack);
	if (stack_b)
		free(stack_b);
}
