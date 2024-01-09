/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leakfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:06:53 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/09 10:27:12 by jkauker          ###   ########.fr       */
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

void	stack_list_clear(t_stacks *stacks)
{
	t_stack_element	*temp;

	if (!stacks)
		return ;
	temp = stack_get_first(stacks->a);
	while (temp)
	{
		free(temp->num);
		temp = temp->next;
		free(temp);
	}
	temp = stack_get_first(stacks->b);
	while (temp)
	{
		free(temp->num);
		temp = temp->next;
		free(temp);
	}
	free(stacks);
}
