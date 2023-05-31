/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:21:09 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/18 13:14:49 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	f;

	f = -1;
	if (!src && !dest)
		return (NULL);
	while (++f < n)
		((unsigned char *)dest)[f] = ((const char *)src)[f];
	return (dest);
}
