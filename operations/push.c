/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:07:56 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/09 10:00:34 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pb : push b - take the first element at the top of a
// and put it at the top of b. Do nothing if a is empty.

#include "../push_swap.h"

void	pa(t_stacks *stacks, int print)
{
	t_stack_element	*first_b;

	if (!stacks->b)
		return ;
	first_b = stack_get_first(stacks->b);
	if (first_b->next)
		first_b->next->previous = 0;
	stacks->b = first_b->next;
	first_b->next = stacks->a;
	if (stacks->a)
		stacks->a->previous = first_b;
	stacks->a = first_b;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks, int print)
{
	t_stack_element	*first_a;

	if (!stacks->a)
		return ;
	first_a = stack_get_first(stacks->a);
	if (first_a->next)
		first_a->next->previous = 0;
	stacks->a = first_a->next;
	first_a->next = stacks->b;
	if (stacks->b)
		stacks->b->previous = first_a;
	stacks->b = first_a;
	if (print)
		write(1, "pb\n", 3);
}
