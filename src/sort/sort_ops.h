/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:48:28 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/15 15:30:17 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_OPS_H
# define SORT_OPS_H

// # include "../push_swap.h"
# include "../stack.h"

char	*sort_two(t_stack *stack, int *arr);
char	*sort_three(t_stack *stack, int *arr, int min, int max);

#endif
