/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:53:55 by sfarren           #+#    #+#             */
/*   Updated: 2024/06/01 11:37:28 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Allocates and returns a substring from the given string.
 *
 * The substring begins at the specified start index and has a maximum length
 * of len.
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return The substring if successful, NULL if the allocation fails.
 
Check if the start index is greater than the length of the string or not.
Check if the start plus the len is greater than the length of the whole string.
Allocate enough memory for the substring, 
Copy from s[start] until we reach len characters copied into our new string.
Finally we can return the substring.
 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = ft_calloc(len + 1, 1);
	if (!substr)
		return (0);
	i = 0;
	j = start;
	while (i < len)
	{
		substr[i] = s[j];
		i++;
		j++;
	}
	return (substr);
}
