/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:51:15 by sfarren           #+#    #+#             */
/*   Updated: 2024/05/30 21:12:03 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Searches for the first occurrence of the character 'c' in the string 's'.
 *
 * @param s The string to be searched.
 * @param c The character to be found.
 * @return A pointer to the first occurrence of 'c' in 's', or 0 if not found.
 */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((char *)s);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
