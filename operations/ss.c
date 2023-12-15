/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:07:26 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 14:26:24 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ss : sa and sb at the same time.
void	ss(long *stack_a, int *size, long *stack_b)
{
	sa(stack_a, size, 0);
	sb(stack_b, size, 0);
	write(1, "ss\n", 3);
}
