/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra <intra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:59 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/11 12:37:25 by intra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// pre-sorts the stack and divides it into 4 parts and then returns
// the number of the stack size / 4 of the sorted array
// so that i cna push all numbers over that are lower than that number
// TODO: handle error when malloc fails
int	get_key_number(t_stack_element *stack, int call)
{
	t_stack_element	*temp;
	static int		*sorted_array = 0;
	static int		size;
	int				i;
	int				bubble_temp;
	int				j;

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
	if (call == 0)
		return (sorted_array[size / 4]);
	return (sorted_array[(size / 4) * call]);
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
	while (++i < (size / 2))
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
		a = get_smallest_num(stacks->b);
		if (a > get_stack_size(stacks->b) / 2)
		{
			a = get_stack_size(stacks->b) - a;
			while (a--)
				rrb(stacks, 1);
		}
		else
			while (a--)
				ra(stacks, 1);
		pa(stacks, 1);
	}
}

void	sort_stack_new(t_stacks *stacks)
{
	static int	key_call = 0;

	while (stacks->a) //get_stack_size(stacks->a) > 3
	{
		push_efficienlty_to_b(stacks, get_key_number(stacks->a, key_call));
		key_call++;
	}
	push_back_efficently(stacks);
}
