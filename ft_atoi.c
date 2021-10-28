/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:52:04 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/10/28 18:55:18 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_overflow(int neg)
{
	if (neg < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{	
	int		neg;
	long	num;

	num = 0;
	neg = 1;
	while (*str == ' ' || *str == '\n'
		|| *str == '\t' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((num * 10 + (*str - '0')) / 10 != num)
			return (ft_overflow(neg));
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num * neg);
}
