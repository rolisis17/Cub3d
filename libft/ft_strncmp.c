/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:02:57 by dcella-d          #+#    #+#             */
/*   Updated: 2023/04/10 21:30:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	f;

	f = 0;
	if (!s1 || !s2)
		return (0);
	while (f < n)
	{
		if (s1[f] != s2[f])
			return ((unsigned char)s1[f] - (unsigned char)s2[f]);
		f++;
	}
	return (0);
}
