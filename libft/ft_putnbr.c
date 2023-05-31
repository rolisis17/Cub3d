/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:54:33 by dcella-d          #+#    #+#             */
/*   Updated: 2023/03/27 13:32:46 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr)
{
	long	nb;
	int		res;

	nb = nbr;
	res = 0;
	if (nb < 0)
	{
		nb *= -1;
		res += write(1, "-", 1);
	}
	if (nb > 9)
		res += ft_putnbr(nb / 10);
	res += ft_putchar(nb % 10 + 48);
	return (res);
}
