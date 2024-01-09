/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:03:15 by intra             #+#    #+#             */
/*   Updated: 2024/01/09 10:13:50 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rb : rotate b - shift up all elements of stack b by 1. The first element
void	rb(t_stacks *stacks, int print)
{
	t_stack_element	*first_b;
	t_stack_element	*last_b;

	if (!stacks->b)
		return ;
	first_b = stack_get_first(stacks->b);
	if (!first_b->next)
		return ;
	stacks->b = first_b->next;
	stacks->b->previous = 0;
	last_b = stack_get_last(stacks->b);
	last_b->next = first_b;
	first_b->previous = last_b;
	first_b->next = 0;
	if (print)
		write(1, "rb\n", 3);
}

// ra : rotate a - shift up all elements of stack a by 1. The first element
void	ra(t_stacks *stacks, int print)
{
	t_stack_element	*first_a;
	t_stack_element	*last_a;

	if (!stacks->a)
		return ;
	first_a = stack_get_first(stacks->a);
	if (!first_a->next)
		return ;
	stacks->a = first_a->next;
	stacks->a->previous = 0;
	last_a = stack_get_last(stacks->a);
	last_a->next = first_a;
	first_a->previous = last_a;
	first_a->next = 0;
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
