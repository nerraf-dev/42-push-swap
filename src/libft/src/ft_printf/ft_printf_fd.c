/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:17:50 by sfarren           #+#    #+#             */
/*   Updated: 2024/12/29 17:45:51 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_handler_fd(const char c, va_list args, int *count, int fd)
{
	if (c == 'd' || c == 'i')
		ft_printnbr_base_fd(va_arg(args, int), DECIMAL, count, fd);
	else if (c == 's')
		ft_printstr_fd(va_arg(args, char *), count, fd);
	else if (c == 'c')
		ft_printchr_fd(va_arg(args, int), count, fd);
	else if (c == '%')
		ft_printchr_fd('%', count, fd);
	else if (c == 'x')
		ft_printnbr_base_fd(va_arg(args, unsigned int), HEX_LOWER, count, fd);
	else if (c == 'X')
		ft_printnbr_base_fd(va_arg(args, unsigned int), HEX_UPPER, count, fd);
	else if (c == 'u')
		ft_printnbr_base_fd(va_arg(args, unsigned int), DECIMAL, count, fd);
	else if (c == 'p')
		ft_printptr_fd(va_arg(args, void *), count, fd);
	else
		*count = -1;
}

int	ft_printf_fd(int fd, const char *str, ...)
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
			format_handler_fd(str[i + 1], args, &print_counter, fd);
			i++;
		}
		else
			ft_printchr_fd(str[i], &print_counter, fd);
		i++;
	}
	va_end(args);
	return (print_counter);
}
