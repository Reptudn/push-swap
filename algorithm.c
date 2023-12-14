/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:59 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 11:12:13 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int		i;

	i = -1;
	while (++i < stack->size - 1)
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
	return (1);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int		operations;

	operations = 0;
	// print_stacks(a, b);
	b->stack[0] = a->stack[0];
	while (!is_sorted(a))
	{
		write(1, "sa\n", 3);
		operations++;
		break ;
	}
	printf("Operations: %d\n", operations);
	// print_stacks(a, b);
}
