/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:12:55 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/01 13:25:52 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdint.h>

/*
int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	if (argc != 3)
		ft_putstr_fd("usage : ./client <pid> <message>\n", 1);
	pid = ft_atoi(argv[1]);
	if (!pid)
		ft_putstr_fd("Invalid PID\n", 1);
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_bit(argv[2][i], pid);
		i++;
	}
	return (0);
}
*/

/*
static void	ft_bit(unsigned char c, int pid)
{
	uint8_t	shift; // 8 bits = 1 byte
	shift = 64;
	while (shift)
	{	
		if (kill(pid, SIGUSR2) == -1)
			write(1, "error", 1); // if bit is 1
		else if (kill(pid, SIGUSR1) == -1)
			write(1, "error", 1); // if bit is 0
		pause();
		usleep(200);
		shift = shift / 2;
	}
}
*/
static int	g_global = 0;

int	ft_bit(unsigned char c, int pid)
{
	int	i;
	
	i = 7;
	while (i >= 0)
	{	
		g_global = 0;
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
		i--;
		usleep(600);
	}
	return (1);
}

void	received(int i)
{
	(void)i;
	g_global = 1;
}

void	send_char(char *str_pid, char *message)
{
	int			pid;

	pid = ft_atoi(str_pid);
	while (*message)
	{
		ft_bit(*message, pid);
		++message;
	}
	ft_bit(*message, pid);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
		ft_putstr_fd("usage : ./client <pid> <message>\n", 1);
	signal(SIGUSR1, received);
	send_char(argv[1], argv[2]);
	return (0);
}
