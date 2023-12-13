/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:23 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/13 11:11:05 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rb : rotate b - shift up all elements of stack b by 1. The first element
void	rb(t_stack *stack_b, int print)
{
	int		tmp;
	int		i;

	tmp = stack_b->stack[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->stack[i] = stack_b->stack[i + 1];
		i++;
	}
	stack_b->stack[i] = tmp;
	if (print)
		write(1, "rb\n", 3);
}
