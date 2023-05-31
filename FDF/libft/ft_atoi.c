/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:19:46 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/11 19:53:42 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	f;
	size_t	sign;
	size_t	res;

	f = 0;
	sign = 1;
	res = 0;
	while ((nptr[f] == 32) || ((nptr[f] >= 9) && (nptr[f] <= 13)))
		f++;
	if ((nptr[f] == '-') || (nptr[f] == '+'))
	{
		if (nptr[f] == '-')
			sign *= -1;
		f++;
	}
	while ((nptr[f] >= 48) && (nptr[f] <= 57))
	{
		res = res * 10 + (nptr[f] - 48);
		f++;
	}
	return (res * sign);
}

/* int	main()
{
	const char	*nptr = "   a -123123123adsasd213    ";

	printf("%d", ft_atoi(nptr));
} */