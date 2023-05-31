/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:09:05 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/11 15:39:47 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	f;

	f = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (src[f] == '\0')
		dst[f] = '\0';
	while (src[f] && (f < size - 1))
	{
		dst[f] = src[f];
		f++;
	}
	dst[f] = '\0';
	return (ft_strlen(src));
}

/* int	main()
{
	char	src[15] = "Fuck";
	char	dst[15] = "some";

	printf("%ld|\n", ft_strlcpy(dst, src, 6));
	printf("%s|\n", dst);
} */