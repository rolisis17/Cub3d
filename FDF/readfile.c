/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:10:04 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/23 19:13:15 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>

void	readdotfile(t_dotfile **file, int fd)
{
	char		*line;
	t_dotfile	*new;
	char		**splited;

	new = NULL;
	line = get_next_line(fd);
	while (line)
	{
		splited = ft_split(line, 32);
		makedotlist(&new, splited);
		combinetwolist(file, new);
		free_splited(splited);
		free(line);
		line = get_next_line(fd);
		new = NULL;
		free (splited);
	}
	free (line);
}

void	free_splited(char **splited)
{
	int	f;

	f = -1;
	while (splited[++f])
		free (splited[f]);
}

void	makedotlist(t_dotfile **lst, char **splited)
{
	int	res;
	int	f;

	f = -1;
	while ((splited)[++f])
	{
		if (splited[f][0] == '\n')
			return ;
		res = ft_atoi((splited)[f]);
		if (*lst)
			find_next_last(*lst)->next = makenode(res);
		else
			(*lst) = makenode(res);
		checkdot(res, 0);
	}
}

t_dotfile	*makenode(int dot)
{
	t_dotfile	*new;

	new = (t_dotfile *)malloc(sizeof(t_dotfile));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->down = NULL;
	new->dot = dot;
	new->x = 0;
	new->y = 0;
	return (new);
}

void	combinetwolist(t_dotfile **lst1, t_dotfile *lst2)
{
	t_dotfile	*temp1;

	if (!(*lst1))
		(*lst1) = lst2;
	else
	{
		temp1 = (*lst1);
		if (temp1->down)
			temp1 = find_down_last(*lst1);
		while (temp1 && lst2)
		{
			temp1->down = lst2;
			temp1 = temp1->next;
			if (lst2->next)
				lst2 = lst2->next;
		}
	}
}
