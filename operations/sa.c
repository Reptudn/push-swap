/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:50 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 14:22:28 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sawp a - swap the first 2 elements at the top of stack a. Do nothing if there
void	sa(long *stack_a, int *size, int print)
{
	long	tmp;
	int		i;
	int		j;

	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
	i = 0;
	j = 0;
	while (i < *size)
	{
		if (stack_a[i] != NOTHING)
			stack_a[j++] = stack_a[i];
		i++;
	}
	while (j < *size)
		stack_a[j++] = NOTHING;
	if (print)
		write(1, "sa\n", 3);
}
