/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:05:34 by sfarren           #+#    #+#             */
/*   Updated: 2024/06/01 20:48:02 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
- Parameters
	s1:  The string to be trimmed.
	set:  The reference set of characters to trim.
- Return value
	The trimmed string.
	NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*trimmed;

	start = 0;
	len = ft_strlen(s1);
	end = len - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	len = (end + 1) - start;
	trimmed = ft_substr(s1, start, len);
	return (trimmed);
}
