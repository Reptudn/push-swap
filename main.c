/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:40:08 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/19 10:35:47 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	long		*stack_a;
	long		*stack_b;
	int			size;

	stack_a = malloc(NORMAL_SIZE * sizeof(long));
	stack_b = malloc(NORMAL_SIZE * sizeof(long));
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
	// k_sort(stack_a, stack_b, size, 2);
	print_stacks(stack_a, stack_b, &size);
	end_program(stack_a, stack_b);
	return (0);
}
