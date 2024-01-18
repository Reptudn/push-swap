/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:59 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/18 15:00:52 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	get_key_number(t_stack_element *stack, int call, int pack_size)
// {
// 	t_stack_element	*temp;
// 	static int		*sorted_array = 0;
// 	static int		size;
// 	int				i;
// 	int				bubble_temp;
// 	int				j;

// 	if (call > pack_size)
// 		return (-2);
// 	if (!sorted_array)
// 	{
// 		size = get_stack_size(stack);
// 		sorted_array = malloc(sizeof(int) * size);
// 		if (!sorted_array)
// 			return (-1);
// 		i = -1;
// 		temp = stack_get_first(stack);
// 		while (++i < size && temp)
// 		{
// 			sorted_array[i] = *temp->num;
// 			temp = temp->next;
// 		}
// 		i = -1;
// 		while (++i < size)
// 		{
// 			j = -1;
// 			while (++j < size - 1)
// 			{
// 				if (sorted_array[j] > sorted_array[j + 1])
// 				{
// 					bubble_temp = sorted_array[j];
// 					sorted_array[j] = sorted_array[j + 1];
// 					sorted_array[j + 1] = bubble_temp;
// 				}
// 			}
// 		}
// 	}
// 	if (call == pack_size)
// 		return (sorted_array[size - 1]);
// 	return (sorted_array[(size / pack_size) * call - 1]);
// }

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

int	select_pack_size(t_stacks *stacks)
{
	int	stack_size;

	stack_size = get_stack_size(stacks->a);
	if (stack_size == 2)
	{
		sa(stacks, 1);
		return (-1);
	}
	else if (stack_size < 4)
	{
		sort_three(stacks);
		return (-1);
	}
	else if (stack_size == 5)
	{
		sort_five(stacks);
		return (-1);
	}
	else if (stack_size <= 10)
		return (1);
	else if (stack_size <= 100)
		return (6);
	else if (stack_size <= 500)
		return (13);
	return (20);
}

void	sort_stack(t_stacks *stacks)
{
	int			key_call;
	int			pack_size;
	int			key_number;
	int stop = 0;

	if (is_sorted(stacks))
		return ;
	pack_size = select_pack_size(stacks);
	if (pack_size == -1)
		return ;
	key_call = 1;
	printf("pack_size: %d\n", pack_size);
	while (stacks->a && stop == 0)
	{
		// write(1, "key_call: ", 10);
		key_number = get_key_number(stacks->a, key_call, pack_size, &stop);
		if (stop == 1)
			break ;
		printf("key_number: %d\n", key_number);
		push_efficienlty_to_b(stacks, key_number);
		key_call++;
	}
	push_back_efficently(stacks);
}
