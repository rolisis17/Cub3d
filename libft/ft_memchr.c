/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:38:39 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/18 13:15:24 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			f;
	unsigned char	*s1;
	unsigned char	c1;

	f = -1;
	s1 = (unsigned char *) s;
	c1 = (unsigned char) c;
	while (++f < n)
		if (s1[f] == c1)
			break ;
	if (f == n)
		return (NULL);
	return ((void *)&s1[f]);
}

/* int main(void)
{
	char s[] = "tripou\0ille";
	printf("Yours: %d\n", ft_memchr(s, '\0') == s + 6);
	printf("The: %d\n", memchr(s, '\0') == s + 6);
	printf("Yours: %d\n", ft_memchr(s, 'l') == s + 7);
	printf("The: %d\n", ft_memchr(s, 'l') == s + 7);
	printf("Yours: %d\n", ft_memchr(s, 'z') == 0);
	printf("The: %d\n", ft_memchr(s, 'z') == 0);
	printf("Yours: %d\n", ft_memchr(s, 0) == s + memlen(s));
	printf("The: %d\n", ft_memchr(s, 0) == s + memlen(s));
	printf("Yours: %d\n", ft_memchr(s, 't' + 256) == s);
	printf("The: %d\n", ft_memchr(s, 't' + 256) == s);
	printf("%d", ft_memlen(s));
	return (0);
} */