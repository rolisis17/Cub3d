/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 06:48:55 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/08 16:17:53 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**merge_split(char **og, char **new)
{
	int		len;
	int		word;
	int		i;
	char	**res;

	i = -1;
	len = word_count(og) + word_count(new);
	res = (char **) malloc(sizeof(char *) * (len + 1));
	while (og[++i])
	{
		word = ft_strlen(og[i]);
		res[i] = ft_calloc(word + 1, sizeof(char));
		ft_strlcpy(res[i], og[i], word + 1);
	}
	len = 0;
	while (new[len])
	{
		word = ft_strlen(new[len]);
		res[i] = ft_calloc(word + 1, sizeof(char));
		ft_strlcpy(res[i++], new[len++], word + 1);
	}
	res[i] = NULL;
	og = freedom("ss", og, new);
	return (res);
}
