/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:40:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/29 16:10:37 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_to_stack(char *str, t_stack *stack)
{

	return (1);
}

int	args_to_stack(char **argv, t_stack *stack, int argc)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 1;
	j = 0;

	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;

	if (argc < 2)
	{
		log_error();
		return (1);
	}
	if (argc == 2)
	{
		if (string_to_stack(argv[1], &stack_a))
		{
			log_error();
			return (1);
		}
	}
	else
	{
		stack_a.stack = malloc((argc - 1) * sizeof(int));
		if (!stack_a.stack)
		{
			log_error();
			return (1);
		}
		stack_a.size = argc - 1;
	}
	return (0);
}
