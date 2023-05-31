/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 06:48:55 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/16 15:46:42 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_split(char **split, int arg)
{
	int		i;
	int		len;
	char	**new_split;

	i = word_count(split);
	new_split = (char **) malloc(sizeof(char *) * (i + 1));
	if (!new_split)
		return (0);
	i = -1;
	while (split[++i])
	{
		len = ft_strlen(split[i]);
		new_split[i] = ft_calloc(len + 1, sizeof(char));
		ft_strlcpy(new_split[i], split[i], len + 1);
	}
	new_split[i] = NULL;
	if (!arg)
		freesplit(split);
	return (new_split);
}
