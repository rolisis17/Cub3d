/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:18:56 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/11 19:52:15 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	f;
	size_t	u;

	f = 0;
	u = 0;
	if (!little[f])
		return ((char *)big);
	while (big[f] && (f < len))
	{
		while ((big[f + u] == little[u]) && (f + u < len))
		{
			if (little[u + 1] == '\0')
				return ((char *)big + f);
			u++;
		}
		u = 0;
		f++;
	}
	return (NULL);
}

/* int	main()
{
	const char	big[] = "lorem ipsum dolor sit amet";
	const char	little[] = "dolor";
	
	printf("%s", ft_strnstr(big, little, 15));
} */