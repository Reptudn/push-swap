/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:28:26 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/09 10:30:52 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	sa(t_stacks *stacks, int print)
{
	t_stack_element	*first_a;
	t_stack_element	*second_a;

	if (!stacks->a || !stacks->a->next)
		return ;
	first_a = stack_get_first(stacks->a);
	second_a = first_a->next;
	first_a->next = second_a->next;
	second_a->next = first_a;
	second_a->previous = 0;
	first_a->previous = second_a;
	stacks->a = second_a;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks, int print)
{
	t_stack_element	*first_b;
	t_stack_element	*second_b;

	if (!stacks->b || !stacks->b->next)
		return ;
	first_b = stack_get_first(stacks->b);
	second_b = first_b->next;
	first_b->next = second_b->next;
	second_b->next = first_b;
	second_b->previous = 0;
	first_b->previous = second_b;
	stacks->b = second_b;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks)
{
	sa(stacks, 0);
	sb(stacks, 0);
	write(1, "ss\n", 3);
}
