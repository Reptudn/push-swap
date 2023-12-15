/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:43 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 09:39:02 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rr : ra and rb at the same time.
void	rr(long *stack_a, long *stack_b, int *size)
{
	ra(stack_a, size, 0);
	rb(stack_b, size, 0);
	write(1, "rr\n", 3);
}
