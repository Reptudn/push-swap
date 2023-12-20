/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:07:56 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/20 15:20:42 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pb : push b - take the first element at the top of a
// and put it at the top of b. Do nothing if a is empty.

#include "../push_swap.h"

void	pa(t_stacks *stacks, int print)
{
	t_stack_element	*first;

	if (!stacks->b)
		return ;
	first = stack_get_first(stacks->b);
	if (!stacks->a)
	{
		stacks->b = first->next;
		if (stacks->b)
			stacks->b->previous = 0;
		else
			first->next = 0;
		stacks->a = first;
		first->previous = 0;
	}
	else
	{
		stacks->b = first->next;
		if (stacks->b)
			stacks->b->previous = 0;
		else
			first->next = 0;
		stack_get_first(stacks->a)->previous = first;
		first->next = stacks->a;
		stacks->a = stack_get_first(stacks->a);
		first->previous = 0;
	}
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks, int print)
{
	t_stack_element	*first;

	if (!stacks->a)
		return ;
	first = stack_get_first(stacks->a);
	if (!stacks->b)
	{
		stacks->a = first->next;
		if (stacks->a)
			stacks->a->previous = 0;
		else
			first->next = 0;
		stacks->b = first;
		first->previous = 0;
	}
	else
	{
		stacks->a = first->next;
		if (stacks->a)
			stacks->a->previous = 0;
		else
			first->next = 0;
		stack_get_first(stacks->b)->previous = first;
		first->next = stacks->b;
		stacks->b = stack_get_first(stacks->b);
		first->previous = 0;
	}
	if (print)
		write(1, "pb\n", 2);
}
