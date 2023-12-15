/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:07:10 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 14:24:56 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sawp b - swap the first 2 elements at the top of stack b. Do nothing if there
void	sb(long *stack_b, int *size, int print)
{
	long	tmp;
	int		i;
	int		j;

	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
	i = 0;
	j = 0;
	while (i < *size)
	{
		if (stack_b[i] != NOTHING)
			stack_b[j++] = stack_b[i];
		i++;
	}

	while (j < *size)
		stack_b[j++] = NOTHING;
	if (print)
		write(1, "sb\n", 3);
}
