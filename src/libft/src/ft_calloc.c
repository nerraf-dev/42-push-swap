/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:19:38 by sfarren           #+#    #+#             */
/*   Updated: 2024/06/02 14:15:54 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The calloc() function allocates memory for an array of nmemb elements of 
size bytes each and returns a pointer to the allocated memory. The memory is
 set to zero. If nmemb or size is 0, then calloc() returns either NULL, or a
  unique pointer value that can later be successfully passed to free().
  */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
