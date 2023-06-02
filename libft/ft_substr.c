/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:22:57 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/01 17:29:01 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (((len > (size_t)ft_strlen(s)) && (start > (size_t)ft_strlen(s))) \
	|| (start > (size_t)ft_strlen(s)))
		len = 0;
	if (len >= (size_t)ft_strlen(s) && ((size_t)ft_strlen(s) > start))
		len = (size_t)ft_strlen(s) - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	if (start < (size_t)ft_strlen(s))
		ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

/* int	main()
{
	char	*s = "tripouille";

	printf("%s", ft_substr(s, 100, 1));
} */