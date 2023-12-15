/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:11:23 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 09:46:38 by jkauker          ###   ########.fr       */
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
	int	i;
	int	index;
	int	smallest;

	smallest = __INT_MAX__;
	i = -1;
	while (++i < *size)
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
