/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:31:16 by sfarren           #+#    #+#             */
/*   Updated: 2024/05/28 13:35:15 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Applies the function `f` to each element of the linked list `lst`.
 *
 * @param lst The linked list to iterate over.
 * @param f   The function to apply to each element of the linked list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == 0 || f == 0)
		return ;
	while (lst != 0)
	{
		f(lst->content);
		lst = lst->next;
	}
}
