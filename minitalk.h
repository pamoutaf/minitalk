/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:38:59 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/10/28 18:55:18 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *nptr);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);

#endif
