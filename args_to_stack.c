/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:52:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/20 11:54:41 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	string_to_stack(char *arg, t_stacks *stacks, int *size)
{
	t_stack_element	*elem;

	elem = 0;
	if (!stacks)
	{
		stacks = (t_stacks *)malloc(sizeof(t_stacks));
		if (!stacks)
			return (0);
		stacks->a = 0;
		stacks->b = 0;
	}
	if (!stacks->a)
	{
		stacks->a = stack_new(ft_atoi(arg));
		if (!stacks->a)
			return (0);
		(*size)++;
		printf("%d\n", elem->num);
	}
	else
	{
		elem = stack_new(ft_atoi(arg));
		if (!elem)
			return (0);
		stack_push(stacks->a, elem);
		(*size)++;
		printf("%d\n", elem->num);
	}
	return (1);
}

int	args_to_stack(int argc, char **argv, t_stacks *stacks, int *size)
{
	int		i;
	int		j;
	char	**contents;

	i = 0;
	stacks = malloc(sizeof(t_stacks));
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			j = -1;
			contents = ft_split(argv[i], ' ');
			if (!contents)
				return (0);
			while (contents[++j])
			{
				if (!string_to_stack(contents[j], stacks, size))
					return (clear_contents(contents, i));
			}
			clear_contents(contents, 0);
		}
		else if (!string_to_stack(argv[i], stacks, size))
			return (0);
	}
	write(1, "t\n", 2);
	return (1);
}

int	setup_second_stack(long *stack_b, long *stack_a, int *size)
{
	int		i;

	i = 0;
	if (!stack_b)
	{
		free(stack_a);
		return (0);
	}
	while (i < *size)
		stack_b[i++] = NOTHING;
	return (1);
}
