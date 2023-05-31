/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:58:33 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/18 11:31:55 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*dnod;

	if (!*lst)
		return ;
	while (*lst != NULL)
	{
		dnod = *lst;
		(del)((*lst)->content);
		dnod = dnod->next;
		free (*lst);
		*lst = dnod;
	}
	*lst = NULL;
}
