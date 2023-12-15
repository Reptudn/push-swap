/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:09:14 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 14:17:57 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rrr : rra and rrb at the same time.
void	rrr(long *stack_a, long *stack_b, int *size)
{
	rra(stack_a, size, 0);
	rrb(stack_b, size, 0);
	write(1, "rrr\n", 4);
}
