/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:36:32 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/14 14:36:08 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*scp;
	size_t	f;

	f = -1;
	scp = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!scp)
		return (NULL);
	while (s[++f])
		scp[f] = s[f];
	return (scp);
}
