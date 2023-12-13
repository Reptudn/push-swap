/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:06 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/13 11:13:42 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

// ra : rotate a - shift up all elements of stack a by 1. The first element
void	ra(t_stack *stack_a, int print)
{
	int		tmp;
	int		i;

	tmp = stack_a->stack[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->stack[i] = stack_a->stack[i + 1];
		i++;
	}
	stack_a->stack[i] = tmp;
	if (print)
		write(1, "ra\n", 3);
}
