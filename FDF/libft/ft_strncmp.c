/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:02:57 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/11 16:36:29 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	f;

	f = 0;
	while ((f < n) && (s1[f] || s2[f]))
	{
		if (s1[f] != s2[f])
			return ((unsigned char)s1[f] - (unsigned char)s2[f]);
		f++;
	}
	return (0);
}
