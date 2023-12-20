/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:09:05 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/20 11:30:25 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	get_next_val_index(long *stack, int size, int curr)
// {
// 	return (-1);
// }

// rrb : reverse rotate b - shift down all elements of stack b by 1. The last
void	rrb(long *stack_b, int *size, int print)
{
	int		i;
	long	tmp;

	i = *size + 1;
	while (--i)
	{
		if (stack_b[i] != NOTHING)
		{
			tmp = stack_b[i];
			break ;
		}
	}
	i = -1;
	while (++i < *size)
	{
		stack_b[i] = stack_b[i + 1];
	}

	if (print)
		write(1, "rrb\n", 4);
}
