/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:50 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/13 11:08:39 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sawp a - swap the first 2 elements at the top of stack a. Do nothing if there
void	sa(t_stack *stack_a, int print)
{
	int		tmp;

	tmp = stack_a->stack[0];
	stack_a->stack[0] = stack_a->stack[1];
	stack_a->stack[1] = tmp;
	if (print)
		write(1, "sa\n", 3);
}
