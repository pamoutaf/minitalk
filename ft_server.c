/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:40:14 by acolin            #+#    #+#             */
/*   Updated: 2021/10/26 22:21:54 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_aff_pid()
{
	ft_putstr_fd("my pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	ft_aff_char(unsigned char *c, int *size)
{
	if (*c == '\0')
	{
		ft_putstr_fd("\nreçu : ", 1);
		ft_putnbr_fd(*size, 1);
		ft_putstr_fd(" bytes\n", 1);
		*size = 0;
	}
	else
       	ft_putchar_fd(*c, 1);
}

void	on_signal(int s, siginfo_t *sigt, void *v)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static int				size = 0;

	c |= s == SIGUSR2;
	i++;
	size++;
    if (i < 8)
        c <<= 1;
    if (i == 8)
	{
		ft_aff_char(&c, &size);
		i = 0;
		c = 0;
	}
	if (s == SIGUSR1)
		kill(sigt->si_pid, SIGUSR2);
	else
		kill(sigt->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	ac;
	
	ft_aff_pid();
	ac.sa_flags = SA_SIGINFO;
	ac.sa_sigaction = on_signal;
	sigaction(SIGUSR1, &ac, NULL);
	sigaction(SIGUSR2, &ac, NULL);
	while(1)
	{
   		pause();
		usleep(200);
	}
	return (1);
}