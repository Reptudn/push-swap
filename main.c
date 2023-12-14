/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:40:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 16:45:46 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	int		size;

	stack_a = malloc(NORMAL_SIZE * sizeof(int));
	stack_b = malloc(NORMAL_SIZE * sizeof(int));
	size = 0;
	if (argc < 2 || !is_valid_input(argv, argc))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!args_to_stack(argc, argv, stack_a, &size))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!setup_second_stack(stack_b, stack_a, &size))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	sort_stack(stack_a, stack_b, &size);
	print_stacks(stack_a, stack_b, &size);
	end_program(stack_a, stack_b);
	return (0);
}
