/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:40:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/13 13:47:31 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_to_stack(char *str, t_stack *stack)
{
	int		i;
	char	**content;

	i = -1;
	content = ft_split(str, ' ');
	while (content[++i])
	{
		if (!ft_isnumber(content[i]))
			return (0);
		stack->stack[i] = ft_atoi(content[i]);
		stack->size++;
	}
	return (1);
}

int	args_to_stack(char **argv, t_stack *stack, int argc)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		stack->stack[i] = ft_atoi(argv[i]);
		stack->size++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a = NULL;
	t_stack	*stack_b = NULL;

	if (argc < 2)
	{
		log_error(stack_a, stack_b);
		return (1);
	}
	if (argc == 2)
	{
		stack_a->stack = malloc(ft_strlen(argv[1]) * sizeof(int));
		if (!string_to_stack(argv[1], stack_a))
		{
			log_error(stack_a, stack_b);
			return (1);
		}
	}
	else
	{
		stack_a->stack = malloc((argc - 1) * sizeof(int));
		if (!stack_a->stack)
		{
			log_error(stack_a, stack_b);
			return (1);
		}
		if (!args_to_stack(argv, stack_a, argc))
		{
			log_error(stack_a, stack_b);
			return (1);
		}
		stack_a->size = argc - 1;
	}
	stack_b = malloc(sizeof(t_stack) * stack_a->size);
	if (!stack_b)
	{
		log_error(stack_a, stack_b);
		return (1);
	}
	stack_b->stack = malloc(sizeof(int) * stack_a->size);
	sort_stack(stack_a, stack_b);
	end_program(stack_a, stack_b);
	return (0);
}
