/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:59 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/09 14:13:29 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Checks if stack_a is sorted and stack_b is empty.
*/
int	is_sorted(t_stacks *stacks)
{
	t_stack_element	*temp;
	int				last_num;

	if (stacks->b || !stacks->a)
		return (0);
	temp = stack_get_first(stacks->a);
	last_num = *temp->num;
	while (temp)
	{
		if (*temp->num < last_num)
			return (0);
		temp->next = temp->next;
		temp = temp->next;
	}
	return (1);
}

int	get_smallest_num(t_stack_element *stack)
{
	int				smallest_num;
	int				smallest_num_index;
	int				i;
	t_stack_element	*temp;

	temp = stack_get_first(stack);
	smallest_num = *temp->num;
	i = 0;
	while (temp)
	{
		if (*temp->num < smallest_num)
		{
			smallest_num = *temp->num;
			smallest_num_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (smallest_num_index);
}

void	sort_stack(t_stacks *stacks)
{
	int				operations;
	int				a;

	operations = 0;
	while (stacks->a && !is_sorted(stacks))
	{
		a = get_smallest_num(stacks->a);
		printf("a: %d\n", a);
		if (a > get_stack_size(stacks->a) / 2)
		{
			a = get_stack_size(stacks->a) - a;
			while (a--)
			{
				rra(stacks, 1);
				operations++;
			}
		}
		else
		{
			while (a--)
			{
				ra(stacks, 1);
				operations++;
			}
		}
		pb(stacks, 0);
		printf("%p", (void *)&stacks->a);
		// return; // TODO: there is an error when checking if the stack is empty
	}
	while (stacks->b && !is_sorted(stacks))
	{
		pa(stacks, 1);
		operations++;
	}
	print_stacks(stacks);
}
