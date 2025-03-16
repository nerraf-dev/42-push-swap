/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:08:10 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 12:08:14 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALISATION_H
# define INITIALISATION_H

# include "stack.h"

// Stack Initialisation Functions
t_stack_node	*initialise_stack(int *arr, int size);
void			initialise_b_nodes(t_stack_node *stack_a,
					t_stack_node *stack_b);
void			initialise_nodes_a(t_stack_node *stack_a,
					t_stack_node *stack_b);

#endif
