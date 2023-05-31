/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_the_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 06:48:55 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/16 15:56:46 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_the_split(char *str, char **split, int spliter)
{
	char	*res;
	int		i;

	i = -1;
	res = NULL;
	if (!split)
		split = ft_split(str, spliter);
	if (split[1] != NULL)
	{
		while (split[++i])
			res = ft_strjoin_mod(res, split[i], 0);
	}
	else
		res = ft_strdup(split[0]);
	freedom("sa", split, str);
	return (res);
}
