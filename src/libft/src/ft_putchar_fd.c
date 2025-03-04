/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:59:04 by sfarren           #+#    #+#             */
/*   Updated: 2024/04/29 13:43:22 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Outputs the character 'c' to the given file descriptor.
 *
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 * @return None
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
