/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:59 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 10:26:24 by jkauker          ###   ########.fr       */
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

void	sort_stack(long *a, long *b, int *size)
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
				printf("%d\n", tmp);
				pa(a, b, size, 1);
				rb(b, size, 1);
				print_stacks(a, b, size);
				operations += 2;
			}
			break ;
		}
		index = get_index_of_smallest_num(a, size);
		if (index == 0)
		{
			pb(b, a, size, 1);
			ra(a, size, 1);
			operations = operations + 2;
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
