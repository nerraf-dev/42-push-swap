/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:13:50 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/17 14:34:42 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPS_H
# define STACK_OPS_H

// # include "../stack.h"
# include "../push_swap.h"


void			append_node(t_stack_node **stack, int value);
t_stack_node	*get_last_node(t_stack_node *stack);
void			free_stack(t_stack_node *stack);
void			print_stack(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
// Validation
int				check_duplicates(int *arr, int size);
bool			is_valid_integer(const char *str);
bool			stack_sorted(t_stack_node *stack);
// Parsing
int				*parse_arguments(int argc, char **argv);



#endif
