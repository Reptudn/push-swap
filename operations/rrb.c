/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra <intra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:09:05 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/08 13:45:50 by intra            ###   ########.fr       */
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
	// long	tmp;

	i = *size + 1;
	while (--i)
	{
		if (stack_b[i] != NOTHING)
		{
			// tmp = stack_b[i];
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
