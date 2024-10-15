/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:02:40 by sfarren           #+#    #+#             */
/*   Updated: 2024/05/30 21:20:35 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Fills a block of memory with a specified value.
 *
 * @param mem Pointer to the memory block to be filled.
 * @param c The value to be set. It is passed as an int, but internally
 *          it is converted to an unsigned char.
 * @param len Number of bytes to be filled.
 * @return Pointer to the memory block after it has been filled.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
