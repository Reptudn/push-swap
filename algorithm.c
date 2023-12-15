/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:59 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 12:28:49 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Checks if stack_a is sorted and stack_b is empty.
*/
int	is_sorted(long *stack_a, long *stack_b, int *size)
{
	int		i;

	i = -1;
	while (++i < *size - 1)
		if (stack_a[i] > stack_a[i + 1])
			return (0);
	if (!is_stack_empty(stack_b, size))
		return (0);
	return (1);
}
// using laying v sort
void	sort_stack(long *a, long *b, int *size)
{
	int		index;
	int		i;

	if (is_sorted(a, b, size))
		return ;
	while (!is_stack_empty(a, size))
	{
		index = get_index_of_smallest_num(a, size);
		if (index == 0)
		{
			pb(b, a, size, 1);
			ra(a, size, 1);
			continue ;
		}
		while (index--)
			ra(a, size, 0);
	}
	i = *size;
	while (i--)
	{
		pa(a, b, size, 1);
		rb(b, size, 1);
	}
}
