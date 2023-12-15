/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:23 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 09:37:55 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rb : rotate b - shift up all elements of stack b by 1. The first element
void	rb(long *stack_b, int *size, int print)
{
	int		tmp;
	int		i;

	tmp = stack_b[0];
	i = 0;
	while (i < *size - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = tmp;
	if (print)
		write(1, "rb\n", 3);
}
