/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:34:33 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/23 17:48:08 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PARSER_H
# define ARG_PARSER_H

# include <stdlib.h>
# include <limits.h>

int		*argument_parser(int argc, char **argv, int *arr_size);
int		*convert_to_int_array(char **split, int size);
void	free_split(char **split);
int		int_array_length(int *int_array);
int		is_valid_int(const char *str);
int		has_duplicates(int *arr, int size);
int		check_sign(const char **str);
int		check_overflow(long result, int sign);
int		split_length(char **split);

#endif
