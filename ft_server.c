/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:13:02 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/10/30 15:38:36 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_getpid(void)
{
	ft_putstr_fd("Pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	ft_signal(int user, siginfo_t *info, void *empty)
{
	static unsigned char	c = 0;
	static int				i = 0;

	(void)empty;
	c |= user == SIGUSR2;
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
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	siga;

	ft_getpid();
	siga.sa_flags = SA_SIGINFO;
	siga.sa_sigaction = ft_signal;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		pause();
	return (1);
}
