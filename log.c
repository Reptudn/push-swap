/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:42:02 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/13 11:02:49 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int		i;

	i = -1;
	while (++i < stack_a->size)
		printf("%d\t%d", stack_a->stack[i], stack_b->stack[i]);
}

void	log_error(t_stack *stack_a, t_stack *stack_b)
{
	write(2, "Error\n", 7);
	end_program(stack_a, stack_b);
}

void	end_program(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stack);
	free(stack_a);
	free(stack_b->stack);
	free(stack_b);
}
