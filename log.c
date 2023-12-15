/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:42:02 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/15 10:06:33 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	print_stacks(long *stack_a, long *stack_b, int *size)
{
	int		i;

	i = -1;
	printf(" a\tb\n---(%d)---\n", *size);
	while (++i < *size)
	{
		if (stack_a[i] == NOTHING)
			printf(" %s\t", "X");
		else
			printf(" %ld\t", stack_a[i]);
		if (stack_b[i] == NOTHING)
			printf("%s\n", "X");
		else
			printf("%ld\n", stack_b[i]);
	}
	write(1, "---------\n", 11);
}

void	end_program(long *stack_a, long *stack_b)
{
	free(stack_a);
	free(stack_b);
	// system("leaks push_swap");
}
