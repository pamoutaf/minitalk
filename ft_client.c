/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:12:55 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/10/30 17:16:34 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_exit(int s)
{
	if (s == SIGUSR2)
		exit(1);
}

int	ft_isPid(int pid)
{
	int	i;

	if (pid <= 0)
		return (0);
	i = 8;
	while (i-- && kill(pid, SIGUSR1) == 0)
	{
		pause();
		usleep(200);
	}
	if (i == -1)
		return (1);
	return (0);
}

static void	ft_bit(unsigned char c, int pid)
{
	int	i;
	int	shift;
	i = 0;
	shift = -1;
	while (i < 8)
	{
		while (++shift < 8)
		{	
			if ((c & 1) >> shift)
			kill(pid, SIGUSR2); // if bit is 1
		else
			kill(pid, SIGUSR1); // if bit is 0
		pause();
		usleep(200);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	signal(SIGUSR1, ft_exit);
	signal(SIGUSR2, ft_exit);
	if (argc > 1 && argc < 4)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		if (ft_isPid(pid))
		{
			while (argv[2][i] != '\0')
			{
				ft_bit((unsigned char) argv[2][i], pid);
				i++;
			}
		}
		else
			ft_putstr_fd("Invalid PID\n", 1);
	}
	else
		ft_putstr_fd("usage : ./client <pid> <message>\n", 1);
	return (1);
}
