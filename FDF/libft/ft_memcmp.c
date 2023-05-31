/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:03:53 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/18 13:15:03 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			f;
	unsigned char	*s11;
	unsigned char	*s22;

	f = -1;
	s11 = (unsigned char *) s1;
	s22 = (unsigned char *) s2;
	while (++f < n)
		if (s11[f] != s22[f])
			return (s11[f] - s22[f]);
	return (0);
}
