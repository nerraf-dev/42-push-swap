/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:00:15 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/21 15:03:07 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "stack.h"
# include "../src/libft/libft.h"
# include <stdbool.h>
# include <stddef.h>

// Initialisation functions
//  Arg validation and checking
int		*validate_args(int argc, char **argv);
int		*parse_string(char **argv);
void	parse_arguments(int argc, char **argv, int **dst_arr);
bool	is_valid_integer(const char *str);
int		check_duplicates(int *arr, int size);
bool	stack_sorted(t_stack_node	*stack);
int		array_length(int *arr);



#endif
