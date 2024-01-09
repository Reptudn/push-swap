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

#include "push_swap.h"

int	get_stack_size(t_stack_element *stack)
{
	int				i;
	t_stack_element	*temp;

	i = 0;
	temp = stack_get_first(stack);
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
