/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:34:00 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/17 13:51:11 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	f;
	char	*s3;

	f = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = (char *)ft_calloc(f, sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, (char *)s2, f);
	return (s3);
}
