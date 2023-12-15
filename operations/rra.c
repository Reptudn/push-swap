/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:53 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 09:38:45 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rra : reverse rotate a - shift down all elements of stack a by 1. The last
void	rra(long *stack_a, int *size, int print)
{
	long	tmp;
	int		i;

	tmp = stack_a[*size - 1];
	i = *size - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[i] = tmp;
	if (print)
		write(1, "rra\n", 4);
}
