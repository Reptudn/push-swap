/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:06 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 09:40:03 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

// ra : rotate a - shift up all elements of stack a by 1. The first element
void	ra(long *stack_a, int *size, int print)
{
	long	tmp;
	int		i;

	tmp = stack_a[0];
	i = 0;
	while (i < *size - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = tmp;
	if (print)
		write(1, "ra\n", 3);
}
