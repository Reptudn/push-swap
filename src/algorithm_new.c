/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:59 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/16 14:37:27 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	get_key_number(t_stack_element *stack, int call, int pack_size)
{
	t_stack_element	*temp;
	static int		*sorted_array = 0;
	static int		size;
	int				i;
	int				bubble_temp;
	int				j;

	if (call > pack_size)
		return (-2);
	if (!sorted_array)
	{
		size = get_stack_size(stack);
		sorted_array = malloc(sizeof(int) * size);
		if (!sorted_array)
			return (-1);
		i = -1;
		temp = stack_get_first(stack);
		while (++i < size && temp)
		{
			sorted_array[i] = *temp->num;
			temp = temp->next;
		}
		i = -1;
		while (++i < size)
		{
			j = -1;
			while (++j < size - 1)
			{
				if (sorted_array[j] > sorted_array[j + 1])
				{
					bubble_temp = sorted_array[j];
					sorted_array[j] = sorted_array[j + 1];
					sorted_array[j + 1] = bubble_temp;
				}
			}
		}
	}
	if (call == pack_size)
		return (sorted_array[size - 1]);
	return (sorted_array[(size / pack_size) * call - 1]);
}

int	has_smaller_number(t_stack_element *stack, int key_number)
{
	t_stack_element	*temp;

	temp = stack_get_first(stack);
	while (temp)
	{
		if (*temp->num < key_number)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	get_next_num_index(t_stack_element *stack, int key_number)
{
	t_stack_element	*temp_front;
	t_stack_element	*temp_back;
	int				size;
	int				i;

	i = -1;
	size = get_stack_size(stack);
	temp_front = stack_get_first(stack);
	temp_back = stack_get_last(stack);
	while (++i < (size / 2) && temp_front && temp_back)
	{
		if (*temp_front->num < key_number)
			return (i);
		else if (*temp_back->num < key_number)
			return (size - i - 1);
		temp_front = temp_front->next;
		temp_back = temp_back->previous;
	}
	return (-1);
}

void	push_efficienlty_to_b(t_stacks *stacks, int key_number)
{
	int	a;

	while (has_smaller_number(stacks->a, key_number))
	{
		a = get_next_num_index(stacks->a, key_number);
		if (a == -1)
			return ;
		if (a > get_stack_size(stacks->a) / 2)
		{
			a = get_stack_size(stacks->a) - a;
			while (a--)
				rra(stacks, 1);
		}
		else
			while (a--)
				ra(stacks, 1);
		pb(stacks, 1);
	}
}

void	push_back_efficently(t_stacks *stacks)
{
	int	a;

	while (stacks->b)
	{
		a = get_biggest_num_index(stacks->b);
		if (a == 0)
		{
			pa(stacks, 1);
			continue ;
		}
		if (a > get_stack_size(stacks->b) / 2)
		{
			a = get_stack_size(stacks->b) - a;
			while (a--)
				rrb(stacks, 1);
		}
		else
			while (a--)
				rb(stacks, 1);
		pa(stacks, 1);
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
	else if (a < b && a < c && b > c)
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
	pa(stacks, 1);
	while (!is_sorted(stacks))
		ra(stacks, 1);
}

void	sort_stack_new(t_stacks *stacks)
{
	int			key_call;
	int			stack_size;
	int			pack_size;
	int			key_number;

	if (is_sorted(stacks))
		return ;
	stack_size = get_stack_size(stacks->a);
	if (stack_size == 2)
	{
		sa(stacks, 1);
		return ;
	}
	else if (stack_size < 4)
	{
		sort_three(stacks);
		return ;
	}
	else if (stack_size == 5)
	{
		sort_five(stacks);
		return ;
	}
	else if (stack_size <= 10)
		pack_size = 2;
	else if (stack_size <= 100)
		pack_size = 6;
	else if (stack_size <= 500)
		pack_size = 13;
	else
		pack_size = 20;
	key_call = 1;
	while (stacks->a)
	{
		key_number = get_key_number(stacks->a, key_call, pack_size);
		push_efficienlty_to_b(stacks, get_key_number(stacks->a,
				key_call, pack_size));
		if (key_number < 0)
			break ;
		key_call++;
	}
	push_back_efficently(stacks);
}
