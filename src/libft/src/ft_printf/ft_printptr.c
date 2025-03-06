/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:25:53 by sfarren           #+#    #+#             */
/*   Updated: 2024/12/29 18:01:46 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printptr(void *ptr, int *count)
{
	unsigned long long	n;

	n = (unsigned long long)ptr;
	if (ptr == NULL)
	{
		ft_printstr(NULL_PTR_STR, count);
	}
	else
	{
		ft_printstr("0x", count);
		if (n >= 16)
		{
			ft_printnbr_base(n / 16, HEX_LOWER, count);
			ft_printnbr_base(n % 16, HEX_LOWER, count);
		}
		else
		{
			ft_printchr(HEX_LOWER[n], count);
		}
	}
}

void	ft_printptr_fd(void *ptr, int *count, int fd)
{
	unsigned long long	n;

	n = (unsigned long long)ptr;
	if (ptr == NULL)
	{
		ft_printstr_fd(NULL_PTR_STR, count, fd);
	}
	else
	{
		ft_printstr_fd("0x", count, fd);
		if (n >= 16)
		{
			ft_printnbr_base_fd(n / 16, HEX_LOWER, count, fd);
			ft_printnbr_base_fd(n % 16, HEX_LOWER, count, fd);
		}
		else
		{
			ft_printchr_fd(HEX_LOWER[n], count, fd);
		}
	}
}
