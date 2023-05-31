/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 06:48:55 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/16 15:53:43 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*char_join(char *str, int c)
{
	char	*res;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	res = ft_calloc(sizeof(char), (len + 2));
	if (!res)
		return (NULL);
	if (str)
	{
		while (str[i])
		{
			res[i] = str[i];
			i++;
		}
		free (str);
	}
	res[i] = c;
	return (res);
}
