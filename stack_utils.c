/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:14:39 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/20 11:45:09 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack_element	*stack_new(int value)
{
	t_stack_element	*new;

	new = (t_stack_element *)malloc(sizeof(t_stack_element));
	if (!new)
		return (0);
	new->num = value;
	new->next = 0;
	new->previous = 0;
	return (new);
}

void	stack_push(t_stack_element *stack, t_stack_element *new_elem)
{
	t_stack_element	*last;

	last = stack_get_last(stack);
	last->next = new_elem;
	new_elem->previous = last;
}

t_stack_element	*stack_get_first(t_stack_element *stack)
{
	t_stack_element	*first;

	first = stack;
	while (first && first->previous)
		first = first->previous;
	return (first);
}

t_stack_element	*stack_get_last(t_stack_element *stack)
{
	t_stack_element	*last;

	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}

int	get_stack_size(t_stack_element *stack)
{
	int				size;
	t_stack_element	*first;

	size = 0;
	first = stack_get_first(stack);
	while (first)
	{
		size++;
		first = first->next;
	}
	return (size);
}
