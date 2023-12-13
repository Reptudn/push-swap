/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:53 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/13 11:09:52 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rra : reverse rotate a - shift down all elements of stack a by 1. The last
void	rra(t_stack *stack_a, int print)
{
	int		tmp;
	int		i;

	tmp = stack_a->stack[stack_a->size - 1];
	i = stack_a->size - 1;
	while (i > 0)
	{
		stack_a->stack[i] = stack_a->stack[i - 1];
		i--;
	}
	stack_a->stack[i] = tmp;
	if (print)
		write(1, "rra\n", 4);
}
