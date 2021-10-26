/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:40:14 by acolin            #+#    #+#             */
/*   Updated: 2021/10/26 17:40:27 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"



void on_signal(int s, siginfo_t *sigt, void *v)
{
	static unsigned char	c;
	static int				i = 0;

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
	if (s == SIGUSR2)
		kill(sigt->si_pid, SIGUSR1);
	else
		kill(sigt->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction action;

	ft_putstr_fd("my pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = on_signal;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while(1)
	{
   		pause();
	}
	return (1);
}