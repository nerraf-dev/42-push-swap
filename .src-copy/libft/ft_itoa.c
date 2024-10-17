/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:08:09 by sfarren           #+#    #+#             */
/*   Updated: 2024/05/18 11:00:39 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.

Return value: The string representing the integer.
NULL if the allocation fails.
*/
static int	int_length(int n);

char	*ft_itoa(int n)
{
	char		*int_str;
	int			int_len;
	int			i;
	long		num;

	int_len = int_length(n);
	num = n;
	if (n < 0)
		num *= -1;
	i = int_len -1;
	int_str = malloc(int_len + 1 * 1);
	if (!int_str)
		return (NULL);
	int_str[0] = '0';
	while (num != 0)
	{
		int_str[i] = (num % 10) + 48;
		num /= 10;
		i--;
	}
	if (n < 0)
		int_str[0] = '-';
	int_str[int_len] = '\0';
	return (int_str);
}

static int	int_length(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
