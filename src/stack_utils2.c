/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:08:00 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/09 14:09:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_biggest_number(t_stack_element *stack)
{
	int				biggest_num;
	t_stack_element	*temp;

	temp = stack_get_first(stack);
	biggest_num = *temp->num;
	while (temp)
	{
		if (*temp->num > biggest_num)
			biggest_num = *temp->num;
		temp = temp->next;
	}
	return (biggest_num);
}
