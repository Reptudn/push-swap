/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:49:20 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/17 10:10:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		last_num = *temp->num;
		temp = temp->next;
	}
	return (1);
}
