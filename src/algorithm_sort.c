/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:50:37 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/17 11:56:24 by jkauker          ###   ########.fr       */
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

void	get_last_num_spot(t_stacks *stacks, int num)
{
	// while (temp)
	// {
	// 	if (index == 0)
	// 	{
	// 		printf("first: %d, %d\n", *temp->num > num, *stack_get_last(stacks->a)->num < num);
	// 		if (*temp->num > num && *stack_get_last(stacks->a)->num < num)
	// 			return (index);
	// 	}
	// 	else if (index == get_stack_size(stacks->a) - 1)
	// 	{
	// 		printf("last: %d, %d\n", *temp->num > num, *stack_get_first(temp)->num < num);
	// 		if (*temp->num > num && *stack_get_first(temp)->num < num)
	// 			return (index);
	// 	}
	// 	printf("middle: %d, %d\n", *temp->num > num, *temp->next->num < num);
	// 	if (*temp->num > num && *temp->next->num < num)
	// 		return (index);
	// 	temp = temp->next;
	// }
	// printf("%d, %d\n", *stack_get_first(stacks->a)->num >= num, *stack_get_last(stacks->a)->num <= num);
	while (1)
	{
		if (*stack_get_first(stacks->a)->num >= num && *stack_get_last(stacks->a)->num >= num)
			return ;
		rra(stacks, 1);
	}
}

void	sort_five(t_stacks *stacks)
{
	pb(stacks, 1);
	pb(stacks, 1);
	sort_three(stacks);
	if (stacks->b->num < stacks->b->next->num)
		sb(stacks, 1);
	while (*stack_get_first(stacks->a)->num < *stacks->b->num)
		ra(stacks, 1);
	pa(stacks, 1);
	// TODO: rotate stack a so that i can call pa and push the last element over so its sorted
	get_last_num_spot(stacks, *stack_get_first(stacks->b)->num);
	// while (*stack_get_first(stacks->a)->num >= *stacks->b->num && *stack_get_last(stacks->a)->num >= *stacks->b->num)
	// 	rra(stacks, 1);
	pa(stacks, 1);
	// while (!is_sorted(stacks))
	// 	ra(stacks, 1);
}
