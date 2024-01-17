/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keynumbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:46:10 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/17 10:41:41 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_arr(int *sorted_array, int size)
{
	int	i;
	int	j;
	int	bubble_temp;

	write(1, "sort_arr\n", 9);
	i = 0;
	while (i < size)
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
		i++;
	}
}

void	fill_array(int *sorted_arr, t_stack_element *stack, int size)
{
	int				i;
	t_stack_element	*temp;

	i = -1;
	temp = stack_get_first(stack);
	while (++i < size && temp)
	{
		sorted_arr[i] = *temp->num;
		temp = temp->next;
	}
}

int	get_key_number(t_stack_element *stack, int call, int pack_size)
{
	static int		*sorted_array = 0;
	static int		size;
	int				i;

	if (call > pack_size)
		return (-2);
	if (!sorted_array)
	{
		write(1, "make sorted arr\n", 17);
		size = get_stack_size(stack);
		sorted_array = malloc(sizeof(int) * size);
		if (!sorted_array)
			return (-1);
		i = -1;
		fill_array(sorted_array, stack, size);
		sort_arr(sorted_array, size);
	}
	if (call == pack_size)
		return (sorted_array[size - 1]);
	return (sorted_array[(size / pack_size) * call - 1]);
}
