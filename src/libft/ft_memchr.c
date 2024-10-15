/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:05:26 by sfarren           #+#    #+#             */
/*   Updated: 2024/04/17 13:51:57 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
	 memchr -- locate byte in byte string

SYNOPSIS
	 void * memchr(const void *s, int c, size_t n);

DESCRIPTION
	 The memchr() function locates the first occurrence of c (converted to an
	 unsigned char) in string s.

RETURN VALUES
	 The memchr() function returns a pointer to the byte located, or NULL if
	 no such byte exists within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
