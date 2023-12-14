/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:40:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 10:07:12 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (argc < 2 || !is_valid_input(argv, argc))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	write(1, "Input valid!\n", 14);
	if (!args_to_stack(argc, argv, stack_a))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!setup_second_stack(stack_b, stack_a))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_stacks(stack_a, stack_b);
	sort_stack(stack_a, stack_b);
	end_program(stack_a, stack_b);
	return (0);
}
