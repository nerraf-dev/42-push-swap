/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:00:00 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/07 09:46:32 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <limits.h>
#include <ctype.h>

int	check_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

int	check_overflow(long result, int sign)
{
	if ((sign == 1 && result > INT_MAX) || (sign == -1 && (-result) < INT_MIN))
		return (0);
	return (1);
}

int	is_valid_int(const char *str)
{
	long	result;
	int		sign;

	if (*str == '\0')
		return (0);
	sign = check_sign(&str);
	if (*str == '\0')
		return (0);
	result = 0;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		result = result * 10 + (*str - '0');
		if (!check_overflow(result, sign))
			return (0);
		str++;
	}
	return (1);
}
