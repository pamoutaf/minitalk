/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:13:02 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/01 13:22:45 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_getpid(void)
{
	ft_putstr_fd("Pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	ft_what(int num, siginfo_t *info, void *empty)
{
	static char	c;
	static int	i;

	(void)empty;
	c = 0;
	i = 0;
	if (num == SIGUSR1)
		c += 1 << (7 - i);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	siga;

	(void)argv;
	if (argc == 1)
	{
		ft_getpid();
		siga.sa_flags = SA_SIGINFO;
		siga.sa_sigaction = ft_what;
		sigaction(SIGUSR1, &siga, NULL);
		sigaction(SIGUSR2, &siga, NULL);
		while (1)
			pause();
	}
	return (0);
}
