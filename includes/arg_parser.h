/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:34:33 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/25 12:11:35 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PARSER_H
# define ARG_PARSER_H

# include "../src/libft/libft.h"

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
 * @brief Parses command-line arguments into an integer array.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @param arr_size Pointer to integer where the size of the array will be stored.
 * @return Pointer to the integer array containing parsed arguments.
 */
int		*parse_arguments(int argc, char **argv, int *arr_size);

/**
 * @brief Parses a single command-line argument into an integer array.
 *
 * @param argv The array of command-line arguments.
 * @param arr_size Pointer to integer where the size of the array will be stored.
 * @return Pointer to the integer array containing parsed arguments.
 */
int		*parse_single_arg(char **argv, int *arr_size);

/**
 * @brief Handles errors by printing a message and freeing allocated memory.
 *
 * @param message The error message to be printed.
 * @param split The array of strings to be freed.
 * @param int_array The integer array to be freed.
 */
void	handle_error(const char *message, char **split, int *int_array);

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
 * @brief Converts an array of strings to an array of integers.
 *
 * @param split The array of strings.
 * @param size The size of the resulting integer array.
 * @return Pointer to the integer array.
 */
int		*convert_to_int_array(char **split, int size);

/**
 * @brief Checks if an integer array contains duplicate values.
 *
 * @param arr The integer array.
 * @param size The size of the array.
 * @return 1 if duplicates are found, 0 otherwise.
 */
int		has_duplicates(int *arr, int size);

#endif
