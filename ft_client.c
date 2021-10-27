/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:39:58 by acolin            #+#    #+#             */
/*   Updated: 2021/10/27 19:44:40 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_aff_nbbytes(int size)
{
	ft_putstr_fd("envoyer : ", 1);
	ft_putnbr_fd(size, 1);
	ft_putstr_fd(" bytes\n", 1);
}

void	ft_cmpt(int s)
{
	if (s == SIGUSR2)
		exit();
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
		usleep(600);
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	size;
	int	pid;

	signal(SIGUSR1, ft_cmpt);
	signal(SIGUSR2, ft_cmpt);
	if (argc > 1 && argc < 4)
	{
		i = 0;
		size = 0;
		pid = ft_atoi(argv[1]);
		if (pid != 0)
		{
			while (argv[2][i] != '\0')
			{
				int_dec((unsigned char) argv[2][i], pid);
				i++;
				size += 8;
			}
			int_dec((unsigned char) '\0', pid);
			size += 8;
			ft_aff_nbbytes(size);
		}
	}
	return (1);
}
