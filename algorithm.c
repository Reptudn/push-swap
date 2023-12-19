/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:59 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/19 10:57:11 by jonask           ###   ########.fr       */
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
// rra and rrb are not working cuz they reverse rotate but then put all the numbers
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
    sa(a, size, 1);
    sb(b, size, 1);
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

void sort_chunk(long *stack_b, int chunk_size)
{
    int i, j;

    for (i = 0; i < chunk_size - 1; i++) {
        for (j = 0; j < chunk_size - i - 1; j++) {
            // Rotate to the jth element
            while (j-- > 0)
                rb(stack_b, &chunk_size, 1);

            // If the current element is greater than the next
            if (stack_b[0] > stack_b[1]) {
                // Swap them
                sb(stack_b, &chunk_size, 1);
            }

            // Rotate back to the start
            while (j++ < chunk_size - 1)
                rrb(stack_b, &chunk_size, 1);
        }
    }
}

void merge_chunks(long *stack_a, int size)
{
	int i = 0;
    int j = size / 2; // assuming two chunks to merge

    while (i < size / 2 && j < size) {
        // Rotate to the ith element
        while (i-- > 0)
            ra(stack_a, &size, 1);

        // Rotate to the jth element
        while (j-- > i)
            ra(stack_a, &size, 1);

        // If the current element is greater than the next
        if (stack_a[0] > stack_a[1]) {
            // Swap them
            sa(stack_a, &size, 1);
        }

        // Rotate back to the start
        while (j++ < size - 1)
            rra(stack_a, &size, 1);

        i++;
        j++;
    }
}

void k_sort(long *a, long *b, int size, int k)
{
    int chunk_size = size / k;

    // Divide the array into k chunks and sort each chunk
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < chunk_size; j++) {
            pb(b, a, &size, 1);
        }
        sort_chunk(b, chunk_size);
    }

    // Merge the chunks
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < chunk_size; j++) {
            pa(a, b, &size, 1);
        }
        merge_chunks(a, size);
    }
}
