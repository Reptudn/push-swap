/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:15:41 by jkauker           #+#    #+#             */
/*   Updated: 2023/12/14 09:25:08 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	ft_isnumber(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	is_valid_input(char **argv, int argc)
{
	int		i;
	int		j;
	char	**contents;

	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			j = -1;
			contents = ft_split(argv[i], ' ');
			if (!contents)
				return (0);
			while (contents[++j])
			{
				if (!ft_isnumber(contents[j]))
					return (free(contents[j]), 0);
				free(contents[j]);
			}
			free(contents);
		}
		else if (!ft_isnumber(argv[i]))
			return (0);
	}
	return (1);
}
