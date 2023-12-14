/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:52:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 11:30:05 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	string_to_stack(char *arg, int *stack, int *size)
{
	printf("arg: %s\tsize: %d\n", arg, *size);
	stack = realloc(stack, ((*size) + 1) * sizeof(int));
	if (!stack)
		return (0);
	stack[(*size)] = ft_atoi(arg);
	(*size)++;
	return (1);
}

int	args_to_stack(int argc, char **argv, int *stack, int *size)
{
	int		i;
	int		j;
	char	**contents;

	i = 0;
	*size = 0;
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
	write(1, "done\n", 5);
	return (1);
}

int	setup_second_stack(int *stack_b, int *stack_a, int *size)
{
	stack_b = malloc(*size * sizeof(int));
	if (!stack_b)
	{
		free(stack_a);
		return (0);
	}
	ft_bzero(stack_b, *size);
	return (1);
}
