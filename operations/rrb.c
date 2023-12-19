/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:09:05 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/19 15:20:44 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rrb : reverse rotate b - shift down all elements of stack b by 1. The last
void	rrb(long *stack_b, int *size, int print)
{
	long tmp;
    int i, j;
    int height = get_curr_stack_height(stack_b, size);

    tmp = stack_b[height - 1];
    i = height - 1;
    j = height - 1;

    while (i > 0) {
        stack_b[i] = stack_b[i - 1];
        i--;
    }

    stack_b[0] = tmp;

    // Move all NOTHING values to the bottom of the stack
    for (i = 0; i < height; i++) {
        if (stack_b[i] == NOTHING) {
            for (j = i; j < height - 1; j++) {
                stack_b[j] = stack_b[j + 1];
            }
            stack_b[height - 1] = NOTHING;
        }
    }

    if (print)
        write(1, "rrb\n", 4);
}
