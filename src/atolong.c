/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atolong.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:18:30 by jkauker           #+#    #+#             */
/*   Updated: 2024/01/08 10:23:52 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	get_num(const char *nptr, int i)
{
	long	num;

	num = 0;
	while (nptr[i] != 0)
	{
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			break ;
		num += nptr[i] - '0';
		num *= 10;
		i++;
	}
	num /= 10;
	return (num);
}

int	is_integer(const char *nptr)
{
	int		i;
	int		prefix;
	long	num;

	i = 0;
	prefix = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			prefix = -1;
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	num = get_num(nptr, i) * prefix;
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}
