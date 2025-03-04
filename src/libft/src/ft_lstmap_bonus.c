/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:38:16 by sfarren           #+#    #+#             */
/*   Updated: 2024/06/01 19:29:10 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Applies the function `f` to each element of the linked list `lst` and creates
 * a new list resulting from the successive applications of `f`. The `del`
 * function is used to delete the content of an element if needed.
 *
 * @param lst The pointer to the first element of the list.
 * @param f The function to apply to each element of the list.
 * @param del The function used to delete the content of an element.
 * @return The new list created by applying `f` to each element of `lst`.
 *         Returns NULL if an allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = 0;
	while (lst)
	{
		new_node = ft_lstnew(0);
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		new_node->content = f(lst->content);
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
