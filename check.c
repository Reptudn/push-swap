/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbornn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:15:41 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/09 11:16:15 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	is_integer(char *str)
{
	if (ft_strlen(str) > 11)
		return (0);
	if (ft_strlen(str) == 11 && (str[0] != '-' || str[0] != '+'))
		return (0);
	// other checks if integer
	return (1);
}

int	ft_isnumber(char *str)
{
	int		i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	if (!is_integer(str))
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
