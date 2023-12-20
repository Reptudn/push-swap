/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:42:02 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/20 11:32:01 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	print_stacks(t_stacks *stacks)
{
	t_stack_element	*first_a;
	t_stack_element	*first_b;

	first_a = stack_get_first(stacks->a);
	first_b = stack_get_first(stacks->b);
	printf("Stack A: ");
	while (first_a)
	{
		printf("%d ", first_a->num);
		first_a = first_a->next;
	}
	printf("\nStack B: ");
	while (first_b)
	{
		printf("%d ", first_b->num);
		first_b = first_b->next;
	}
	printf("\n");
}

void	end_program(long *stack_a, long *stack_b)
{
	free(stack_a);
	free(stack_b);
	// system("leaks push_swap");
	// printf("Sort Success\n");
}
