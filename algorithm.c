/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:59 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/19 15:15:50 by jkauker          ###   ########.fr       */
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

// rra and rrb are not working cuz they reverse rotate but then put all the nbrs
// on the bottom of the stack and the nothings above instead of the nothings on
// the bottom and the numbers on top
void	sort_stack(long *a, long *b, int *size)
{
	int		index;

	if (is_sorted(a, b, size))
		return ;
	pb(b, a, size, 1);
	pb(b, a, size, 1);
	pb(b, a, size, 1);
	// rrb(b, size, 1);
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
			ra(a, size, 1);
	}
	while (!is_stack_empty(b, size))
	{
		pa(a, b, size, 1);
		rb(b, size, 1);
	}
	print_stacks(a, b, size);
}

void	k_sort(long *a, long *b, int size, int k)
{
	int i, index;

    // Push elements from a to b
    for (i = 0; i < size; i++) {
        index = get_index_of_num(a, i, &size); // assuming this function exists
        if (index <= k) {
            pb(b, a, &size, 1); // assuming pb function exists
            rb(b, &size, 1); // assuming rb function exists
        } else {
            ra(a, &size, 1); // assuming ra function exists
        }
    }

    // Push elements back from b to a
    while (!is_stack_empty(b, &size)) { // assuming is_stack_empty function exists
        pa(a, b, &size, 1); // assuming pa function exists
        rb(b, &size, 1); // assuming rb function exists
    }
}
