/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 06:48:55 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/16 15:50:02 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*freedom(const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == 's')
			freesplit(va_arg(args, char **));
		else if (str[i] == 'l')
			freelist(va_arg(args, t_store *));
		else if (str[i] == 'a')
			free_check(va_arg(args, void *));
		i++;
	}
	va_end(args);
	return (NULL);
}

void	freelist(t_store *list)
{
	t_store	*temp;
	
	while(list)
	{
		temp = list;
		list = list->next;
		if (temp->content)
			free(temp->content);
		if (temp->name)
			free(temp->name);
		free(temp);
	}
	list = NULL;
}

void	free_check(void *freeable)
{
	if (freeable)
	{
		free(freeable);
		freeable = NULL;
	}
}
