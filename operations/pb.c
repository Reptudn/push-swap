/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:07:56 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/18 15:09:50 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pb : push b - take the first element at the top of a
// and put it at the top of b. Do nothing if a is empty.

#include "../push_swap.h"

void	pb(long *b, long *a, int *size, int print)
{
	if (a[0] == NOTHING)
	{
		if (print)
			write(1, "pb\n", 3);
		return ;
	}
	rrb(b, size, 0);
	b[0] = a[0];
	a[0] = NOTHING;
	ra(a, size, 0);
	if (print)
		write(1, "pb\n", 3);
}
