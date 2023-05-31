/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 06:48:55 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/31 21:25:03 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**add_split(char **split, char *new)
{
	int		i;
	int		len;
	char	**new_split;

	if (split[0] == NULL || split == NULL)
		return (ft_split(new, 32));
	new_split = (char **) ft_calloc(sizeof(char *), (word_count(split) + 2));
	if (!new_split)
		return (0);
	i = -1;
	while (split[++i])
	{
		len = ft_strlen(split[i]);
		new_split[i] = ft_calloc(len + 1, sizeof(char));
		ft_strlcpy(new_split[i], split[i], len + 1);
	}
	len = ft_strlen(new);
	new_split[i] = ft_calloc(len + 1, sizeof(char));
	if (!new_split[i])
		return (0);
	if (len > 0)
		ft_strlcpy(new_split[i], new, len + 1);
	new_split[++i] = NULL;
	split = freedom("s", split);
	return (new_split);
}
