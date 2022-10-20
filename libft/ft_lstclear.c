/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:30:34 by zkasmi            #+#    #+#             */
/*   Updated: 2021/11/17 18:56:35 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;
	t_list	*temp;

	head = NULL;
	head = *lst;
	temp = head;
	while (head)
	{
		head = temp->next;
		ft_lstdelone(temp, del);
		temp = head;
	}
	*lst = NULL;
}
