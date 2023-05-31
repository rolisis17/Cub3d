
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:25:37 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/10 15:51:51 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	void	*nmembp;
	size_t	f;

	f = -1;
	nmembp = (void *) malloc(nmemb * size);
	if (!nmembp)
		return (NULL);
	while (++f < nmemb * size)
		((unsigned char *)nmembp)[f] = 0;
	return (nmembp);
}

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int f)
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
	free (s1);
	return (s3);
}

int	gnl_check(char *line)
{
	int	f;

	f = -1;
	if (!line)
		return (0);
	while (line[++f])
		if (line[f] == '\n')
			return (f + 1);
	return (0);
}
