/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:08:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/09 10:25:03 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// shift elements down by one

void	rra(t_stacks *stacks, int print)
{
	t_stack_element	*last_a;

	if (!stacks->a || !stacks->a->next)
		return ;
	last_a = stack_get_last(stacks->a);
	last_a->previous->next = 0;
	last_a->previous = 0;
	last_a->next = stacks->a;
	stacks->a = last_a;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks, int print)
{
	t_stack_element	*last_b;

	if (!stacks->b || !stacks->b->next)
		return ;
	last_b = stack_get_last(stacks->b);
	last_b->previous->next = NULL;
	last_b->previous = NULL;
	last_b->next = stacks->b;
	stacks->b = last_b;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stacks)
{
	rra(stacks, 0);
	rrb(stacks, 0);
	write(1, "rrr\n", 4);
}