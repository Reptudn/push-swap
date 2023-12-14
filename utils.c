/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:11:23 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 15:13:40 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_empty(int *stack, int *size)
{
	int	i;

	i = -1;
	while (++i < *size)
		if (stack[i] != 0)
			return (0);
	return (0);
}

int	get_index_of_smallest_num(int *stack, int *size)
{
	int	i;
	int	index;
	int	smallest;

	smallest = __INT_MAX__;
	i = -1;
	while (++i < *size)
	{
		if (stack[i] < smallest && stack[i] != 0)
		{
			smallest = stack[i];
			index = i;
		}
	}
	return (index);
}
