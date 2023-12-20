/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leakfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:06:53 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/20 11:21:38 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	clear_contents(char **contents, int i)
{
	i--;
	while (contents[++i])
		free(contents[i]);
	free(contents);
	return (0);
}

void	clear_stack(t_stack_element *stack)
{
	t_stack_element	*first;
	t_stack_element	*tmp;

	first = stack_get_first(stack);
	while (first)
	{
		tmp = first->next;
		free(first);
		first = tmp;
	}
}

void	stack_list_clear(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->a)
		clear_stack(stacks->a);
	if (stacks->b)
		clear_stack(stacks->b);
	free(stacks);
}
