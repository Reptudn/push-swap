/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:53 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/19 11:27:43 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rra : reverse rotate a - shift down all elements of stack a by 1. The last
void	rra(long *stack_a, int *size, int print)
{
	long tmp;
    int i, j;

    tmp = stack_a[*size - 1];
    i = *size - 1;
    j = *size - 1;

    while (i > 0) {
        stack_a[i] = stack_a[i - 1];
        i--;
    }

    stack_a[0] = tmp;

    // Move all NOTHING values to the bottom of the stack
    for (i = 0; i < *size; i++) {
        if (stack_a[i] == NOTHING) {
            for (j = i; j < *size - 1; j++) {
                stack_a[j] = stack_a[j + 1];
            }
            stack_a[*size - 1] = NOTHING;
        }
    }

    if (print)
        write(1, "rra\n", 4);
}
