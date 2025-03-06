/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:17:50 by sfarren           #+#    #+#             */
/*   Updated: 2024/07/17 13:30:02 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_handler(const char c, va_list args, int *count)
{
	if (c == 'd' || c == 'i')
		ft_printnbr_base(va_arg(args, int), DECIMAL, count);
	else if (c == 's')
		ft_printstr(va_arg(args, char *), count);
	else if (c == 'c')
		ft_printchr(va_arg(args, int), count);
	else if (c == '%')
		ft_printchr('%', count);
	else if (c == 'x')
		ft_printnbr_base(va_arg(args, unsigned int), HEX_LOWER, count);
	else if (c == 'X')
		ft_printnbr_base(va_arg(args, unsigned int), HEX_UPPER, count);
	else if (c == 'u')
		ft_printnbr_base(va_arg(args, unsigned int), DECIMAL, count);
	else if (c == 'p')
		ft_printptr(va_arg(args, void *), count);
	else
		*count = -1;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_counter;

	i = 0;
	print_counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			format_handler(str[i + 1], args, &print_counter);
			i++;
		}
		else
			ft_printchr(str[i], &print_counter);
		i++;
	}
	va_end(args);
	return (print_counter);
}
