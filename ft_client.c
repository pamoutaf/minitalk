/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:12:55 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/02 10:52:33 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdint.h>

static int g_lock;

int	ft_sendchar(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_lock = 0;
		if (c >> i & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				write(2, "error\n", 6);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				write(2, "error\n", 6);
		}
		while (g_lock == 0)
		{
		}
		i--;
	}
	return (1);
}

void	received(int i)
{
	(void)i;
	g_lock = 1;
}

void	send_str(char *str_pid, char *message)
{
	int			pid;

	pid = ft_atoi(str_pid);
	if (pid <= 0)
		write(1, "Invalid PID\n", 13);
	while (*message)
	{
		ft_sendchar(*message, pid);
		++message;
	}
	ft_sendchar(*message, pid);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
		ft_putstr_fd("usage : ./client <pid> <message>\n", 1);
	signal(SIGUSR1, received);
	send_str(argv[1], argv[2]);
	return (0);
}
