/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:52:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 10:48:04 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_to_stack(char *arg, long *stack, int *size)
{
	int	num;
	int	i;

	if (*size + 1 > NORMAL_SIZE)
	{
		stack = realloc(stack, ((*size) + 1) * sizeof(int));
		if (!stack)
			return (0);
	}
	num = ft_atoi(arg);
	i = -1;
	while (++i < *size)
		if (stack[i] == num)
			return (0);
	stack[(*size)++] = num;
	return (1);
}

int	args_to_stack(int argc, char **argv, long *stack, int *size)
{
	int		i;
	int		j;
	char	**contents;

	i = 0;
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
				if (!string_to_stack(contents[j], stack, size))
					return (free(contents[j]), free(contents), free(stack), 0);
				free(contents[j]);
			}
			free(contents);
		}
		else if (!string_to_stack(argv[i], stack, size))
			return (free(stack), 0);
	}
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
