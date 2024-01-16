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

#include "../push_swap.h"
#include <stdlib.h>

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
	t_stack_element	*next;

	if (!stacks)
		return ;
	temp = stack_get_first(stacks->a);
	while (temp)
	{
		next = temp->next;
		free(temp->num);
		free(temp);
		temp = next;
	}
	temp = stack_get_first(stacks->b);
	while (temp)
	{
		next = temp->next;
		free(temp->num);
		free(temp);
		temp = next;
	}
	if (stacks)
		free(stacks);
}
