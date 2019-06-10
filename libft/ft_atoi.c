/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <samymone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:45:21 by samymone          #+#    #+#             */
/*   Updated: 2019/05/02 12:21:35 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	diffspaces(const char *str)
{
	if (*str == '\n' || *str == ' ' || *str == '\r' || *str == '\t' ||
	*str == '\f' || *str == '\v')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int					is_neg;
	unsigned long int	res;

	res = 0;
	is_neg = 1;
	while (diffspaces(str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
		&& *str - '0' > 7)) && is_neg == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
		&& (*str - '0') > 8)) && is_neg == -1)
			return (0);
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * is_neg);
}
