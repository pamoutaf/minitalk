/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:40:14 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/10/28 18:55:18 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_aff_pid(void)
{
	ft_putstr_fd("my pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	on_signal(int s, siginfo_t *sigt, void *v)
{
	static unsigned char	c = 0;
	static int				i = 0;

	(void)v;
	c |= s == SIGUSR2;
	i++;
	if (i < 8)
		c <<= 1;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
	usleep(200);
	kill(sigt->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	ac;

	ft_aff_pid();
	ac.sa_flags = SA_SIGINFO;
	ac.sa_sigaction = on_signal;
	sigaction(SIGUSR1, &ac, NULL);
	sigaction(SIGUSR2, &ac, NULL);
	while (1)
		pause();
	return (1);
}
