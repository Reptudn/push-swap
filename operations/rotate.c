/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra <intra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:03:15 by intra             #+#    #+#             */
/*   Updated: 2024/01/08 14:50:57 by intra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rb : rotate b - shift up all elements of stack b by 1. The first element
void	rb(t_stacks *stacks, int print)
{
	t_stack_element	*first;
	t_stack_element	*last;

	first = stack_get_first(stacks->b);
	last = first;
	while (last->next)
		last = last->next;
	last->next = first;
	first->previous = last;
	stacks->b = first->next;
	if (print)
		write(1, "rb\n", 3);
}

// ra : rotate a - shift up all elements of stack a by 1. The first element
void	ra(t_stacks *stacks, int print)
{
	t_stack_element	*first;
	t_stack_element	*last;

	first = stack_get_first(stacks->a);
	last = first;
	while (last->next)
		last = last->next;
	last->next = first;
	first->previous = last;
	stacks->a = first->next;
	if (print)
		write(1, "ra\n", 3);
}

// rr : ra and rb at the same time.
void	rr(t_stacks *stacks)
{
	ra(stacks, 0);
	rb(stacks, 0);
	write(1, "rr\n", 3);
}
