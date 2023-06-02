/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:01:26 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/01 17:26:55 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	f;

	f = 0;
	while (s[f] && (char)s[f] != (char)c)
		f++;
	if ((char)c != '\0' && ft_strlen(s) == f)
		return (NULL);
	return ((char *)&s[f]);
}
/* #include <string.h>

int iTest = 1;
int main(void)
{
	char s[] = "tripou\0ille";
	printf("Yours: %d\n", ft_strchr(s, '\0') == s + 6);
	printf("The: %d\n", strchr(s, '\0') == s + 6);
	printf("Yours: %d\n", ft_strchr(s, 'l') == s + 7);
	printf("The: %d\n", ft_strchr(s, 'l') == s + 7);
	printf("Yours: %d\n", ft_strchr(s, 'z') == 0);
	printf("The: %d\n", ft_strchr(s, 'z') == 0);
	printf("Yours: %d\n", ft_strchr(s, 0) == s + strlen(s));
	printf("The: %d\n", ft_strchr(s, 0) == s + strlen(s));
	printf("Yours: %d\n", ft_strchr(s, 't' + 256) == s);
	printf("The: %d\n", ft_strchr(s, 't' + 256) == s);
	printf("%ld", ft_strlen(s));
	return (0);
}
 */