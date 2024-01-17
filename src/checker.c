/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:21:09 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/17 09:38:07 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../lib/get_next_line/get_next_line.h"

void	execute_operation(t_stacks *stacks, char *line)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		sa(stacks, 0);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		sb(stacks, 0);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		ss(stacks);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		pa(stacks, 0);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		pb(stacks, 0);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		ra(stacks, 0);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		rb(stacks, 0);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		rr(stacks);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		rra(stacks, 0);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		rrb(stacks, 0);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		rrr(stacks);
	else
		write(1, "Error\n", 6);
	free(line);
}

void	checker_sort(t_stacks *stacks)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_operation(stacks, line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks || argc < 2 || !is_valid_input(argv, argc))
	{
		if (stacks)
			free(stacks);
		write(1, "Error\n", 6);
		return (1);
	}
	if (!args_to_stack(argc, argv, stacks))
	{
		stack_list_clear(stacks);
		write(1, "Error\n", 6);
		return (1);
	}
	checker_sort(stacks);
	if (is_sorted(stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_list_clear(stacks);
	return (0);
}
