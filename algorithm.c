/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:59 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 14:28:12 by jkauker          ###   ########.fr       */
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
			print_stacks(a, b, size);
			pb(b, a, size, 1);
			print_stacks(a, b, size);
			ra(a, size, 1);
			print_stacks(a, b, size);
			continue ;
		}
		while (index--)
		{
			print_stacks(a, b, size);
			ra(a, size, 1);
			print_stacks(a, b, size);
		}
		print_stacks(a, b, size);
	}
	i = *size;
	while (i--)
	{
		print_stacks(a, b, size);
		pa(a, b, size, 1);
		print_stacks(a, b, size);
		rb(b, size, 1);
	}
}
