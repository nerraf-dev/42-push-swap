/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:33:24 by sfarren           #+#    #+#             */
/*   Updated: 2024/07/17 10:11:09 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_printnbr_base(long long n, char *base, int *count)
{
	int	base_len;

	if (!is_valid_base(base))
		*count = -1;
	base_len = ft_strlen(base);
	if (*count != -1)
	{
		if (n < 0)
		{
			ft_printchr('-', count);
			n *= -1;
		}
		if (n >= base_len)
		{
			ft_printnbr_base(n / base_len, base, count);
			ft_printnbr_base(n % base_len, base, count);
		}
		else
			ft_printchr(base[n], count);
	}
}
