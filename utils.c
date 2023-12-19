/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:11:23 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/19 10:41:08 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_empty(long *stack, int *size)
{
	int	i;

	i = -1;
	while (++i < *size)
		if (stack[i] != NOTHING)
			return (0);
	return (1);
}

int	get_index_of_smallest_num(long *stack, int *size)
{
	int		i;
	int		index;
	long	smallest;

	smallest = 2147483648;
	i = -1;
	while (++i < *size && stack[i] != NOTHING)
	{
		if (stack[i] == NOTHING)
			continue ;
		if (stack[i] < smallest)
		{
			smallest = stack[i];
			index = i;
		}
	}
	if (index < 0)
		return (0);
	return (index);
}
