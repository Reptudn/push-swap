/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra <intra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:40:08 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/08 14:45:13 by intra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (argc < 2 || !is_valid_input(argv, argc))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!args_to_stack(argc, argv, stacks))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_stacks(stacks);
	pb(stacks, 0);
	pb(stacks, 0);
	pb(stacks, 0);
	printf("---------\n");
	rb(stacks, 0);
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
