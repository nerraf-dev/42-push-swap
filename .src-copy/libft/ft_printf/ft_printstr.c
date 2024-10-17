/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:42:08 by sfarren           #+#    #+#             */
/*   Updated: 2024/07/16 18:22:02 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		ft_printchr(s[i], count);
		i++;
	}
}
