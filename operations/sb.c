/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:07:10 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/13 11:09:29 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sawp b - swap the first 2 elements at the top of stack b. Do nothing if there
void	sb(t_stack *stack_b, int print)
{
	int		tmp;

	tmp = stack_b->stack[0];
	stack_b->stack[0] = stack_b->stack[1];
	stack_b->stack[1] = tmp;
	if (print)
		write(1, "sb\n", 3);
}
