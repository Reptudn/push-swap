/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:07:41 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 10:12:47 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pa : push a - take the first element at the top of b and
// put it at the top of a. Do nothing if b is empty.

#include "../push_swap.h"

void	pa(long *a, long *b, int *size, int print)
{
	if (b[0] == NOTHING)
		return ;
	rra(b, size, 0);
	a[0] = b[0];
	b[0] = NOTHING;
	if (print)
		write(1, "pa\n", 3);
}
