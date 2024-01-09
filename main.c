/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:40:08 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/09 14:11:42 by jkauker          ###   ########.fr       */
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
	sort_stack(stacks);
	print_stacks(stacks);
	// stack_list_clear(stacks);
	return (0);
}
