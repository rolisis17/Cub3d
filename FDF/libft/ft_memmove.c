/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:35:42 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/18 13:14:08 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	f;
	char	*d;
	char	*s;
	char	*res;

	s = (char *) src;
	d = (char *) dest;
	if (!src && !dest)
		return (NULL);
	res = ft_calloc(n, sizeof(char));
	if (!res)
		return (dest);
	f = -1;
	while (++f < n)
		res[f] = s[f];
	f = -1;
	while (++f < n)
		d[f] = res[f];
	free(res);
	return (dest);
}

/* int main()
{
	char src[] = "Fucksome";
	char *dest = src + 2;
	//char *res = memcpy(dest, src, 7);
	//printf("src : %s|\n", src);
	//printf("dest : %s|\n", dest);
	char *res2 = ft_memmove(dest, src, 7);
	//printf("The func cpy: %s\n", res); 
	printf("The func move: %s|\n", res2);
}
 */