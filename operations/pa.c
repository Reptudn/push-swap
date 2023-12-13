/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:07:41 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/13 11:32:15 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pa : push a - take the first element at the top of b and
// put it at the top of a. Do nothing if b is empty.

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b, int print)
{
	if (b->stack[0] == 0)
		return ;
	a->stack[0] = b->stack[0];
	if (print)
		write(1, "pa\n", 3);
}
