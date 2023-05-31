/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:12:46 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/11 15:07:58 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	f;
	size_t	u;

	f = ft_strlen(dst);
	u = 0;
	if ((size <= f) || (size == 0))
		return (ft_strlen(src) + size);
	while ((src[u]) && (u < size - f - 1))
	{
		dst[f + u] = src[u];
		u++;
	}
	dst[f + u] = '\0';
	return (f + ft_strlen(src));
}

/* int main()
{
	char	dest[15] = "";
	char	src[15] = "some";

	printf("%ld\n", ft_strlcat(dest, src, 2));
	printf("%s\n", dest);
	return (0);
} */