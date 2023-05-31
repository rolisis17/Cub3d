/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:34:00 by dcella-d          #+#    #+#             */
/*   Updated: 2023/04/10 20:56:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int f)
{
	int		u;
	int		c;
	char	*s3;

	u = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	if (f == -1)
		u -= ft_strlen_gnl(s1);
	s3 = (char *)ft_calloc_gnl(u + 1, sizeof(char));
	if (!s3)
		return (NULL);
	c = -1;
	if (s1 && f != -1)
		while (s1[++c] && (c < u))
			s3[c] = s1[c];
	else
		c = 0;
	u = -1;
	while (s2[++u])
		s3[c + u] = s2[u];
	if (f == -2)
		if (s1)
			free (s1);
	return (s3);
}
