/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:52:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 09:32:22 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_to_stack(char *arg, t_stack *stack)
{
	stack->stack = realloc(stack->stack, (stack->size + 1) * sizeof(int));
	if (!stack->stack)
		return (0);
	stack->stack[++stack->size] = ft_atoi(arg);
	return (1);
}

int	args_to_stack(int argc, char **argv, t_stack *stack)
{
	int		i;

	i = 0;
	stack->stack = malloc(argc * sizeof(int));
	if (!stack->stack)
		return (0);
	stack->size = 0;
	write(1, "args_to_stack\n", 14);
	while (++i < argc)
	{
		ft_printf("%d\n", i);
		if (ft_strchr(argv[i], ' ') && !string_to_stack(argv[i], stack))
			return (free(stack->stack), free(stack), 0);
		else if (!string_to_stack(argv[i], stack))
			return (free(stack->stack), free(stack), 0);
		printf("Stack size: %d\n", stack->size);
	}
	return (1);
}

int	setup_second_stack(t_stack *stack_b, t_stack *stack_a)
{
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
	{
		free(stack_a->stack);
		free(stack_a);
		return (0);
	}
	stack_b->stack = ft_calloc(stack_a->size, sizeof(int));
	if (!stack_b->stack)
	{
		free(stack_a->stack);
		free(stack_a);
		free(stack_b);
		return (0);
	}
	stack_b->size = stack_a->size;
	return (1);
}
