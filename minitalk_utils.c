/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:10:50 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/10/30 14:13:17 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s++)
		ft_putchar_fd(*s, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n && n >= -2147483647 && n <= 2147483647)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n >= 10)
			ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd(((n % 10) + '0'), fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_atoi(const char *str)
{
	unsigned long	res;
	int				sign;
	int				i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i++] == 45)
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
		if ((i >= 19 || res > (1ull << 63) - 1) && sign > 0)
			return (-1);
	}
	if ((i >= 19 || res > 1ull << 63) && sign < 0)
		return (0);
	return (sign * res);
}
