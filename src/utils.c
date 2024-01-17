/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:11:23 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/19 15:07:21 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index_of_num(long *stack, long num, int *size)
{
	int	i;

	i = 0;
	while (i < *size)
	{
		if (stack[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int	get_biggest_num_index(t_stack_element *stack)
{
	int				i;
	int				biggest_num;
	int				biggest_num_index;
	t_stack_element	*temp;

	i = 0;
	biggest_num_index = 0;
	temp = stack_get_first(stack);
	biggest_num = *temp->num;
	while (temp)
	{
		if (*temp->num > biggest_num)
		{
			biggest_num = *temp->num;
			biggest_num_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (biggest_num_index);
}

int	is_stack_sorted(t_stack_element *stack)
{
	t_stack_element	*temp;

	temp = stack_get_first(stack);
	while (temp && temp->next)
	{
		if (*temp->num > *temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
