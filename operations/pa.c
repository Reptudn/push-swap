/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:07:41 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 13:35:47 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pa : push a - take the first element at the top of b and
// put it at the top of a. Do nothing if b is empty.

#include "../push_swap.h"

void	pa(int *a, int *b, int *size, int print)
{
	if (b[0] == 0)
		return ;
	rb(b, size, 0);
	a[0] = b[0];
	b[0] = 0;
	if (print)
		write(1, "pa\n", 3);
}
