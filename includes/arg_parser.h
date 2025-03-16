/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:34:33 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 11:49:11 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PARSER_H
# define ARG_PARSER_H

# include <stdlib.h>
# include <limits.h>

/**
 * @brief Parses command-line arguments into an integer array.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @param arr_size Pointer to integer where the size of the array will be stored.
 * @return Pointer to the integer array containing parsed arguments.
 */
int		*argument_parser(int argc, char **argv, int *arr_size);

/**
 * @brief Converts an array of strings to an array of integers.
 *
 * @param split The array of strings.
 * @param size The size of the resulting integer array.
 * @return Pointer to the integer array.
 */
int		*convert_to_int_array(char **split, int size);

/**
 * @brief Frees a split array of strings.
 *
 * @param split The array of strings to be freed.
 */
void	free_split(char **split);

/**
 * @brief Calculates the length of an integer array.
 *
 * @param int_array The integer array.
 * @return The length of the integer array.
 */
int		int_array_length(int *int_array);

/**
 * @brief Checks if a string represents a valid integer.
 *
 * @param str The string to be checked.
 * @return 1 if the string is a valid integer, 0 otherwise.
 */
int		is_valid_int(const char *str);

/**
 * @brief Checks if an integer array contains duplicate values.
 *
 * @param arr The integer array.
 * @param size The size of the array.
 * @return 1 if duplicates are found, 0 otherwise.
 */
int		has_duplicates(int *arr, int size);

/**
 * @brief Checks the sign of a string representing an integer.
 *
 * @param str The string to be checked.
 * @return The sign of the integer.
 */
int		check_sign(const char **str);

/**
 * @brief Checks for overflow in a long integer result.
 *
 * @param result The long integer result.
 * @param sign The sign of the integer.
 * @return 1 if overflow is detected, 0 otherwise.
 */
int		check_overflow(long result, int sign);

/**
 * @brief Calculates the length of a split array of strings.
 *
 * @param split The array of strings.
 * @return The length of the split array.
 */
int		split_length(char **split);

#endif
