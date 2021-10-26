/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:36:32 by acolin            #+#    #+#             */
/*   Updated: 2021/10/25 15:57:44 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * Écrit la chaine de caractères ’s’ sur le file
 * descriptor donné.
 *
 * \param	*s	La chaine de caractères à écrire.
 * \param	fd	Le file descriptor sur lequel écrire.
 * \return		None
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}
