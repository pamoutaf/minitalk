/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:39:58 by acolin            #+#    #+#             */
/*   Updated: 2021/10/26 17:37:03 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void ft_cmpt(int s)
{
	printf("%i ok\n", s);
}

void	int_dec(unsigned char c, int pid)
{
	int i;

	i = 8;
	while (i)
	{
		if((c >> (i - 1)) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		pause();
	}
}

int	main(int argc, char *argv[])
{
	int i;
	int pid;
	
	signal(SIGUSR1, ft_cmpt);
	signal(SIGUSR2, ft_cmpt);
	if (argc > 1 && argc < 4)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		if (pid != 0)
		{
			while (argv[2][i] != '\0')
			{
				int_dec((unsigned char) argv[2][i], pid);
				i++;
			}
		}
	}
	return (1);
}
