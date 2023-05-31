/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:01:26 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/09 18:00:20 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	f;

	f = ft_strlen(s);
	while ((f >= 0) && (char)s[f] != (char)c)
		f--;
	if ((char)c != '\0' && f == -1)
		return (NULL);
	return ((char *)&s[f]);
}

/* #include <string.h>

int main(void)
{
	char s[] = "\xc4tripou\xc4ille";
	printf("Yours: %d\n", ft_strrchr(s, 't') == s + 6);
	printf("The: %d\n", strrchr(s, 't') == s + 6);
	printf("Yours: %d\n", ft_strrchr(s, 'l') == s + 7);
	printf("The: %d\n", ft_strrchr(s, 'l') == s + 7);
	printf("Yours: %d\n", ft_strrchr(s, 'z') == 0);
	printf("The: %d\n", ft_strrchr(s, 'z') == 0);
	printf("Yours: %d\n", ft_strrchr(s, 0) == s + strlen(s));
	printf("The: %d\n", ft_strrchr(s, 0) == s + strlen(s));
	printf("Yours: %d\n", ft_strrchr(s, 't' + 256) == s);
	printf("The: %d\n", ft_strrchr(s, 't' + 256) == s);
	printf("%ld", ft_strlen(s));
	return (0);
}
 */