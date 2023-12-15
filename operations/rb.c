/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:23 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 14:12:03 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rb : rotate b - shift up all elements of stack b by 1. The first element
void	rb(long *stack_b, int *size, int print)
{
	long	tmp;
	int		i;
	int		j;

	tmp = stack_b[0];
	i = 0;
	j = 0;
	while (i < *size - 1)
	{
		if (stack_b[i + 1] != NOTHING)
			stack_b[j++] = stack_b[i + 1];
		i++;
	}
	if (tmp != NOTHING)
		stack_b[j++] = tmp;
	while (j < *size)
		stack_b[j++] = NOTHING;
	if (print)
		write(1, "rb\n", 3);
}
