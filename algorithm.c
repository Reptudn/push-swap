/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:59 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 16:46:55 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Checks if stack_a is sorted and stack_b is empty.
*/
int	is_sorted(int *stack_a, int *stack_b, int *size)
{
	int		i;

	i = -1;
	while (++i < *size - 1)
		if (stack_a[i] > stack_a[i + 1])
			return (0);
	i = -1;
	while (++i < *size)
		if (stack_b[i] != 0)
			return (0);
	return (1);
}

void	sort_stack(int *a, int *b, int *size)
{
	int		operations;
	int		index;
	int		tmp;

	operations = 0;
	printf("Sorting...\n");
	while (!is_sorted(a, b, size))
	{
		if (is_stack_empty(a, size))
		{
			tmp = *size;
			while (tmp--)
			{
				pa(a, b, size, 1);
				rb(b, size, 1);
				operations += 2;
			}
			break ;
		}
		index = get_index_of_smallest_num(a, size);
		if (index == 0)
		{
			pb(b, a, size, 1);
			operations++;
			continue ;
		}
		while (index--)
		{
			ra(a, size, 0);
			operations++;
		}
		pb(b, a, size, 1);
		ra(a, size, 0);
		operations += 2;
	}
	printf("Sorted with %d operations\n", operations);
}
