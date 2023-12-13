/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:07:56 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/13 11:32:48 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pb : push b - take the first element at the top of a
// and put it at the top of b. Do nothing if a is empty.

#include "../push_swap.h"

void	pb(t_stack *b, t_stack *a, int print)
{
	if (a->stack[0] == 0)
		return ;
	b->stack[0] = a->stack[0];
	if (print)
		write(1, "pb\n", 3);
}
