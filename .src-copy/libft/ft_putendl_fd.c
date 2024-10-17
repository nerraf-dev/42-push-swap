/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:11:38 by sfarren           #+#    #+#             */
/*   Updated: 2024/05/18 11:27:15 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Writes the string `s` followed by a newline character ('\n') to the file
 * associated with the file descriptor `fd`.
 *
 * @param s The string to be written.
 * @param fd The file descriptor of the file to write to.
 */
void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	nl;

	i = 0;
	nl = '\n';
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &nl, 1);
}
