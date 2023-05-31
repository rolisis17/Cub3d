/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 06:48:55 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/16 15:47:08 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**remove_split(char **split, char *rem, int arg)
{
	int		i;
	int		f;
	int		len;
	char	**new_split;

	i = word_count(split);
	new_split = (char **) malloc(sizeof(char *) * i);
	if (!new_split)
		return (0);
	i = -1;
	f = -1;
	while (split[++i])
	{
		if ((ft_strncmp(split[i], rem, ft_strlen(rem)) != 0))
		{
			len = ft_strlen(split[i]);
			new_split[++f] = ft_calloc(len + 1, sizeof(char));
			ft_strlcpy(new_split[f], split[i], len + 1);
		}
	}
	new_split[++f] = NULL;
	if (!arg)
		freesplit(split);
	return (new_split);
}
