/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:00:00 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 18:50:14 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <limits.h>
#include <ctype.h>

/**
 * @brief Checks the sign of a number in a string.
 *
 * @param str Pointer to the string.
 * @return int The sign of the number (1 for positive, -1 for negative).
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
 * @brief Checks for integer overflow.
 *
 * @param result The current result of the number.
 * @param sign The sign of the number.
 * @return int 1 if no overflow, 0 if overflow occurs.
 */
int	check_overflow(long result, int sign)
{
	if ((sign == 1 && result > INT_MAX) || (sign == -1 && (-result) < INT_MIN))
		return (0);
	return (1);
}

/**
 * @brief Validates if a string represents a valid integer.
 *
 * @param str The string to validate.
 * @return int 1 if the string is a valid integer, 0 otherwise.
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
