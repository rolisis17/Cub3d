/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 06:48:55 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/07 21:23:04 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**add_split(char **split, char *new)
{
	int		i;
	// int		len;
	char	**new_split;

	if (split[0] == NULL || split == NULL)
	{
		// new_split = ft_split(new, 2);
		// freedom("sa", split, new);
		return (NULL);
	}
	new_split = (char **) ft_calloc(sizeof(char *), (word_count(split) + 2));
	if (!new_split)
		return (0);
	i = -1;
	while (split[++i])
		new_split[i] = ft_strdup(split[i]);
	new_split[i] = ft_strdup(new);
	new_split[++i] = NULL;
	split = freedom("s", split);
	return (new_split);
}
