/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:26:09 by sfarren           #+#    #+#             */
/*   Updated: 2024/04/23 13:23:18 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Compares the first n bytes of memory areas pointed to by s1 and s2.
 *
 * @param s1    Pointer to the first memory area.
 * @param s2    Pointer to the second memory area.
 * @param n     Number of bytes to compare.
 * @return      Returns an integer less than, equal to, or greater than zero 
 * 				if the first n bytes of s1 are found, respectively, to be 
 * 				less than, to match or be greater than the first n bytes of s2
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
