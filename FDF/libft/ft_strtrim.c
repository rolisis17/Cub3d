/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:48:44 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/23 12:58:32 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	f;
	size_t	u;

	f = 0;
	u = -1;
	while (ft_strchr(set, s1[++u]) != NULL)
		;
	while (ft_strrchr(set, s1[ft_strlen(s1) - ++f]) != NULL)
		;
	s2 = ft_substr(s1, u, ft_strlen(s1) - u - f + 1);
	if (!s2)
		return (NULL);
	return (s2);
}

/* int	main()
{
	char *s1 = " \n   \n \n \t\t\n  Hello \t  Please\n Trim me !\n   \n";
 	char *s2 = "Hello \t  Please\n Trim me !";
 	char *ret = ft_strtrim(s1, " \n\t");
	size_t	f = checkstart(s1, ret);
	printf("%zu", f);
	printf("$%s$\n", ret);
} */