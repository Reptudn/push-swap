/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:09:05 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 09:38:50 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rrb : reverse rotate b - shift down all elements of stack b by 1. The last
void	rrb(long *stack_b, int *size, int print)
{
	long	tmp;
	int		i;

	tmp = stack_b[*size - 1];
	i = *size - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[i] = tmp;
	if (print)
		write(1, "rrb\n", 4);
}
