/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:00:42 by sfarren           #+#    #+#             */
/*   Updated: 2024/04/23 15:08:06 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_copy;
	size_t	len;

	len = ft_strlen(str);
	str_copy = (char *)malloc(len +1);
	if (!str_copy)
		return (NULL);
	ft_memcpy(str_copy, str, len);
	str_copy[len] = '\0';
	return (str_copy);
}
