/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:13:02 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/02 10:44:34 by pamoutaf         ###   ########.fr       */
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
	static char	c = 0;
	static int	shift = 0;

	(void)empty;
	(void)info;
	if (num == SIGUSR1)
		c = c | (1 << (7 - shift));
	shift++;
	if (shift == 8)
	{
		ft_putchar_fd(c, 1);
		shift = 0;
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
	ft_putstr_fd("usage : ./server <no argument!>\n", 1);
	return (0);
}
