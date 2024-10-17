/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:14:22 by sfarren           #+#    #+#             */
/*   Updated: 2024/04/23 15:52:40 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function name: ft_strjoin
** Prototype: char *ft_strjoin(char const *s1, char const *s2);
** Parameters:
**     s1: The prefix string.
**     s2: The suffix string.
** Return value:
**     The new string.
**     NULL if the allocation fails.
** External functs: malloc
** Description:
**     Allocates (with malloc(3)) and returns a new string,
**     which is the result of the concatenation of ’s1’ and ’s2’.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*s3;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = malloc(s1_len + s2_len + 1);
	if (!s3)
		return (0);
	i = 0;
	while (i < s1_len)
	{
		s3[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		s3[i] = *s2++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
