/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:00:00 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/18 11:19:44 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <limits.h>
#include <ctype.h>

/**
 * Checks the sign of a number and advances the string pointer.
 * @param str The string to check.
 * @return 1 if positive, -1 if negative.
 */
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

/**
 * Checks for integer overflow.
 * @param result The current result.
 * @param sign The sign of the number.
 * @return 1 if no overflow, 0 otherwise.
 */
int	check_overflow(long result, int sign)
{
	if ((sign == 1 && result > INT_MAX) || (sign == -1 && (-result) < INT_MIN))
		return (0);
	return (1);
}

/**
 * Validates if a string represents a valid integer.
 * @param str The string to validate.
 * @return 1 if valid, 0 otherwise.
 */
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
