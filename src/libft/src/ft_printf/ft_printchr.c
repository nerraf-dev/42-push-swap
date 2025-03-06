/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:18:46 by sfarren           #+#    #+#             */
/*   Updated: 2024/12/29 17:42:56 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchr(char c, int *count)
{
	if (*count == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*count = -1;
	else
		*count += 1;
}

void	ft_printchr_fd(char c, int *count, int fd)
{
	if (*count == -1)
		return ;
	if (write(fd, &c, 1) == -1)
		*count = -1;
	else
		*count += 1;
}
