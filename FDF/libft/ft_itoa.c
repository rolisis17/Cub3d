/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:49:51 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/16 14:47:44 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_countnb(long n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		count++;
		n = (n / 10);
	}
	return (count);
}

static char	*ft_nbstr(char *res, long n, int count, int sig)
{
	int	f;

	f = count + sig;
	while (f-- > 0)
	{
		res[f] = (n % 10) + 48;
		n /= 10;
		if (sig == 1 && f == 0)
			res[f] = 45;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		sig;
	int		count;
	char	*res;
	long	n1;

	sig = 0;
	n1 = n;
	if (n1 < 0)
	{
		sig = 1;
		n1 *= -1;
	}
	count = ft_countnb(n1);
	res = ft_calloc(count + sig + 1, sizeof(char));
	if (!res)
		return (NULL);
	res = ft_nbstr(res, n1, count, sig);
	return (res);
}

/* int main()
{
	printf("%s", ft_itoa(-2147483648));
} */