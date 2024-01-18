/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:50:37 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/18 10:04:37 by jkauker          ###   ########.fr       */
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

void	rotate(t_stacks *stacks, int a)
{
	if (a > get_stack_size(stacks->a) / 2)
	{
		a = get_stack_size(stacks->a) - a;
		while (a--)
			rra(stacks, 1);
	}
	else
	{
		while (a--)
			ra(stacks, 1);
	}
}

int	get_biggest_or_second_biggest_index(t_stacks *stacks)
{
	int				biggest_index;
	int				to_end_biggest;
	int				to_end_second_biggest;
	int				second_biggest_index;
	int				stack_size;

	stack_size = get_stack_size(stacks->a);
	biggest_index = get_biggest_num_index(stacks->a);
	second_biggest_index = get_second_biggest_index(stacks->a,
			get_biggest_number(stacks->a));
	to_end_biggest = stack_size - biggest_index;
	to_end_second_biggest = stack_size - second_biggest_index;
	if (biggest_index == 0 || second_biggest_index == 0)
		return (0);
	else if (biggest_index == stack_size - 1
		|| second_biggest_index == stack_size - 1)
		return (stack_size - 1);
	if (ft_min(to_end_biggest, biggest_index) <= ft_min(to_end_second_biggest,
			second_biggest_index))
		return (biggest_index);
	else
		return (second_biggest_index);
}

void	sort_five(t_stacks *stacks)
{
	rotate(stacks, get_biggest_or_second_biggest_index(stacks));
	pb(stacks, 1);
	rotate(stacks, get_biggest_num_index(stacks->a));
	pb(stacks, 1);
	sort_three(stacks);
	if (*stacks->b->num < *stacks->b->next->num)
		sb(stacks, 1);
	pa(stacks, 1);
	pa(stacks, 1);
	ra(stacks, 1);
	ra(stacks, 1);
}
