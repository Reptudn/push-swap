/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:40:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/20 11:31:19 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			size;

	stacks = 0;
	size = 0;
	if (argc < 2 || !is_valid_input(argv, argc))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!args_to_stack(argc, argv, stacks, &size))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_stacks(stacks);
	// if (!setup_second_stack(stack_b, stack_a, &size))
	// {
	// 	write(1, "Error\n", 6);
	// 	return (1);
	// }
	// sort_stack(stack_a, stack_b, &size);
	// k_sort(stack_a, stack_b, size, ft_sqrt(size) * 1.6);
	// print_stacks(stack_a, stack_b, &size);
	// end_program(stack_a, stack_b);
	return (0);
}
