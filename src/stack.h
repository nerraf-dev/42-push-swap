/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:01:36 by sfarren           #+#    #+#             */
/*   Updated: 2024/10/15 15:22:43 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H
# include <stdlib.h>

typedef struct s_node
{
    int             value;
	int             rank;
    struct s_node   *next;
} t_node;

typedef struct s_stack
{
    t_node  *top;
} t_stack;

#endif // STACK_H
