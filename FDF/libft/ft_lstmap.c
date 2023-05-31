/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:39:38 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/18 11:50:10 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	temp = NULL;
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		new = ft_lstnew((f)(lst->content));
		if (!new)
			return (NULL);
		ft_lstadd_back(&temp, new);
		if (!lst)
		{
			(del)(lst->content);
			free (lst);
		}
		lst = lst->next;
	}
	return (temp);
}
