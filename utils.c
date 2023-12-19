/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:11:23 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/19 15:07:21 by jkauker          ###   ########.fr       */
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

int	ft_sqrt(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		return (0);
	while (i * i < num)
		i++;
	return (i);
}

int	get_curr_stack_height(long *stack, int *size)
{
	int	i;

	i = 0;
	while (i < *size)
	{
		if (stack[i] == NOTHING)
			return (i);
		i++;
	}
	return (*size);
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

int	get_index_of_num(long *stack, long num, int *size)
{
	int	i;

	i = 0;
	while (i < *size)
	{
		if (stack[i] == num)
			return (i);
		i++;
	}
	return (-1);
}
