/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:34:54 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/23 21:00:41 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_list_length(t_dotfile	*lst)
{
	int	counter;

	counter = 0;
	if (lst)
		counter = 1;
	else
		return (0);
	while (lst->next)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

t_dotfile	*find_next_last(t_dotfile *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_dotfile	*find_down_last(t_dotfile *lst)
{
	if (!lst)
		return (lst);
	while (lst->down)
		lst = lst->down;
	return (lst);
}

int	count_list_depth(t_dotfile *lst)
{
	int	counter;

	counter = 0;
	if (lst)
		counter = 1;
	else
		return (0);
	while (lst->down)
	{
		counter++;
		lst = lst->down;
	}
	return (counter);
}
