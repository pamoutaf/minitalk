/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:39:58 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/10/28 18:55:18 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exit(int s)
{
	if (s == SIGUSR2)
		exit(1);
}

int	ft_verif_pid(int pid)
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

void	int_dec(unsigned char c, int pid)
{
	int	i;

	i = 8;
	while (i)
	{
		if ((c >> (i - 1)) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		pause();
		usleep(200);
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
		if (ft_verif_pid(pid))
		{
			while (argv[2][i] != '\0')
			{
				int_dec((unsigned char) argv[2][i], pid);
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
