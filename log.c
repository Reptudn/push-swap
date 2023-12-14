/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:42:02 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 13:51:56 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	print_stacks(int *stack_a, int *stack_b, int *size)
{
	int		i;

	i = -1;
	ft_printf(" a\tb\n---(%d)---\n", *size);
	while (++i < *size)
		ft_printf(" %d\t%d\n", stack_a[i], stack_b[i]);
}

void	end_program(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
	// system("leaks push_swap");
}
