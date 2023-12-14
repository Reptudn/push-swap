/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:52:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 09:55:01 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"
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
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->stack = malloc(sizeof(int));
	if (!stack->stack)
		return (0);
	stack->size = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' ') && !string_to_stack(argv[i], stack))
			return (free(stack->stack), free(stack), 0);
		else if (!string_to_stack(argv[i], stack))
			return (free(stack->stack), free(stack), 0);
	}
	printf("stack a size: %d\n", stack->size);
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
	write(1, "a\n", 2);
	stack_b->stack = malloc(stack_a->size * sizeof(int));
	write(1, "b\n", 2);
	if (!stack_b->stack)
	{
		free(stack_a->stack);
		free(stack_a);
		free(stack_b);
		return (0);
	}
	ft_bzero(stack_b->stack, stack_a->size);
	stack_b->size = stack_a->size;
	return (1);
}
