/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:54:59 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/09 12:01:44 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Checks if stack_a is sorted and stack_b is empty.
*/
int	is_sorted(t_stacks *stacks)
{
	t_stack_element	*temp;
	int				last_num;

	if (stacks->b || !stacks->a)
		return (0);
	temp = stack_get_first(stacks->a);
	last_num = *temp->num;
	while (temp)
	{
		if (*temp->num < last_num)
			return (0);
		temp->next = temp->next;
		temp = temp->next;
	}
	return (1);
}

void	sort_stack(t_stacks *stacks)
{
	int				operations;
    t_stack_element	*temp;
    int				swapped;

    operations = 0;
    do
    {
        swapped = 0;
        temp = stack_get_first(stacks->a);
        while (temp && temp->next)
        {
            if (*temp->num > *temp->next->num)
            {
                sa(stacks, 1);
                operations++;
                swapped = 1;
            }
            ra(stacks, 1);
            operations++;
            temp = temp->next;
        }
        rra(stacks, 1);
        operations++;
    } while (swapped);
	print_stacks(stacks);
	printf("operations: %d\n", operations);
}
