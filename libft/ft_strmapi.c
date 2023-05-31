/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:51:07 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/16 15:13:06 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		u;
	char				*strf;

	u = -1;
	strf = ft_calloc (ft_strlen(s) + 1, sizeof(char));
	if (!strf || !s)
		return (NULL);
	while (s[++u])
		strf[u] = f(u, s[u]);
	return (strf);
}
