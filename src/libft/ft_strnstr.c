/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:08:54 by sfarren           #+#    #+#             */
/*   Updated: 2024/06/01 19:27:50 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Searches for the first occurrence of a substring within a given string,
 * but limits the search to a specified length.
 *
 * @param content The string to search within.
 * @param search_str The substring to search for.
 * @param len The maximum number of characters to search within the content.
 * @return A pointer to the first occurrence of the substring within the content,
 *         or NULL if the substring is not found.
 */
char	*ft_strnstr(const char *content, const char *search_str, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	if (search_str[0] == '\0')
		return ((char *)content);
	while (content[i] != '\0' && i < len)
	{
		start = i;
		while (content[i] == search_str[j])
		{
			i++;
			j++;
			if (search_str[j] == '\0')
				return ((char *)&content[start]);
			if (i == len)
				return (0);
		}
		i = start + 1;
		j = 0;
	}
	return (0);
}
