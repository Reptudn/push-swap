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

#include "../push_swap.h"

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
