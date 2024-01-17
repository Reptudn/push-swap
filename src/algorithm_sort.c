/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:50:37 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/17 14:15:20 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three2(t_stacks *stacks, int a, int b, int c)
{
	if (a < b && a < c && b > c)
	{
		sa(stacks, 1);
		ra(stacks, 1);
	}
	else if (a > b && a < c && b < c)
		rra(stacks, 1);
	else
	{
		if (!is_stack_sorted(stacks->a))
			rra(stacks, 1);
	}
}

void	sort_three(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = *stack_get_first(stacks->a)->num;
	b = *stack_get_first(stacks->a)->next->num;
	c = *stack_get_last(stacks->a)->num;
	if (a > b && a > c && b < c)
		ra(stacks, 1);
	else if (a > b && a > c && b > c)
	{
		sa(stacks, 1);
		rra(stacks, 1);
	}
	else if (a > b && a < c)
		sa(stacks, 1);
	else
		sort_three2(stacks, a, b, c);
}

void	to_num_spot(t_stacks *stacks)
{
	t_stack_element	*above;
	t_stack_element	*below;

	above = stack_get_last(stacks->a);
	below = stack_get_first(stacks->a);
	if (*above->num < *stacks->b->num && *below->num > *stacks->b->num)
	{
		pa(stacks, 1);
		return ;
	}
	while (*above->num > *stacks->b->num || *below->num < *stacks->b->num)
	{
		if (*above->num > *stacks->b->num)
			rra(stacks, 1);
		else if (*below->num < *stacks->b->num)
			ra(stacks, 1);
		above = stack_get_last(stacks->a);
		below = stack_get_first(stacks->a);
	}
}

void	sort_five(t_stacks *stacks)
{
	pb(stacks, 1);
	pb(stacks, 1);
	sort_three(stacks);
	if (stacks->b->num < stacks->b->next->num)
		sb(stacks, 1);
	to_num_spot(stacks);
	pa(stacks, 1);
	to_num_spot(stacks);
	pa(stacks, 1);
	// while (!is_sorted(stacks))
	// 	ra(stacks, 1);
}
