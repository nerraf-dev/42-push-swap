/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:34:18 by sfarren           #+#    #+#             */
/*   Updated: 2024/05/28 13:02:27 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lst_size;
	t_list	*temp;

	lst_size = 0;
	temp = lst;
	while (temp)
	{
		lst_size++;
		temp = temp->next;
	}
	return (lst_size);
}
