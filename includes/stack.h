/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:18:12 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/16 12:07:50 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					cost;
	bool				lowest_cost;
	bool				above_median;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}	t_stack_node;

#endif
