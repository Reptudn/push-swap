/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:42:02 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/09 10:26:30 by jkauker          ###   ########.fr       */
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
		printf("%d\t", *first_a->num);
		first_a = first_a->next;
	}
	printf("\nStack B: ");
	while (first_b)
	{
		printf("%d\t", *first_b->num);
		first_b = first_b->next;
	}
	printf("\n");
}

void	end_program(t_stacks *stacks)
{
	t_stack_element	*temp;

	temp = stack_get_first(stacks->a);
	while (temp)
	{
		free(temp->num);
		temp = temp->next;
		free(temp);
	}
	temp = stack_get_first(stacks->b);
	while (temp)
	{
		free(temp->num);
		temp = temp->next;
		free(temp);
	}
	system("leaks push_swap");
}
