/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:53 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 14:15:31 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rra : reverse rotate a - shift down all elements of stack a by 1. The last
void	rra(long *stack_a, int *size, int print)
{
	long	tmp;
	int		i;
	int		j;

	tmp = stack_a[*size - 1];
	i = *size - 1;
	j = *size - 1;
	while (i > 0)
	{
		if (stack_a[i - 1] != NOTHING)
			stack_a[j--] = stack_a[i - 1];
		i--;
	}
	if (tmp != NOTHING)
		stack_a[j--] = tmp;
	while (j >= 0)
		stack_a[j--] = NOTHING;
	if (print)
		write(1, "rra\n", 4);
}
