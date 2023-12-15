/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:06 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 14:12:27 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

// ra : rotate a - shift up all elements of stack a by 1. The first element
void	ra(long *stack_a, int *size, int print)
{
	long	tmp;
	int		i;
	int		j;

	tmp = stack_a[0];
	i = 0;
	j = 0;

	while (i < *size - 1)
	{
		if (stack_a[i + 1] != NOTHING)
			stack_a[j++] = stack_a[i + 1];
		i++;
	}
	if (tmp != NOTHING)
		stack_a[j++] = tmp;
	while (j < *size)
		stack_a[j++] = NOTHING;

	if (print)
		write(1, "ra\n", 3);
}
