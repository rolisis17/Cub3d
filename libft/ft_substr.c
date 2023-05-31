/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:22:57 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/14 15:51:54 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (((len > ft_strlen(s)) && (start > ft_strlen(s))) \
	|| (start > ft_strlen(s)))
		len = 0;
	if (len >= ft_strlen(s) && (ft_strlen(s) > start))
		len = ft_strlen(s) - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	if (start < ft_strlen(s))
		ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

/* int	main()
{
	char	*s = "tripouille";

	printf("%s", ft_substr(s, 100, 1));
} */