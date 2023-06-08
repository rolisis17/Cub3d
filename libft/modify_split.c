/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 06:48:55 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/08 16:15:40 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**modify_split(char **split, char *mod, int arg, int flag)
{
	int		i;
	int		len;
	char	**new_split;

	if (!mod)
		return (split);
	i = word_count(split);
	new_split = (char **) ft_calloc(sizeof(char *), i + 1);
	if (!new_split)
		return (0);
	i = -1;
	while (split[++i])
	{
		if ((ft_strncmp(split[i], mod, strintchr(mod, flag)) != 0))
		{
			len = ft_strlen(split[i]);
			new_split[i] = ft_calloc(len + 1, sizeof(char));
			ft_strlcpy(new_split[i], split[i], len + 1);
		}
		else
			new_split[i] = ft_strdup(mod);
	}
	if (!arg)
		freesplit(split);
	return (new_split);
}

int	strintchr(char	*str, int c)
{
	int	f;

	f = 0;
	while (str[f] && str[f] != c)
		f++;
	if (!str[f])
		f = 0;
	return (f);
}
