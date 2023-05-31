/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:54:33 by dcella-d          #+#    #+#             */
/*   Updated: 2023/03/27 13:32:33 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putaddress(unsigned long int nbr, char *base, int safe)
{
	int	res;

	res = 0;
	if (!nbr)
		return (write(1, "(nil)", 5));
	if (safe == 0)
		res += write(1, "0x", 2);
	if (nbr > 15)
		res += ft_putaddress(nbr / 16, base, 1);
	res += ft_putchar(base[nbr % 16]);
	return (res);
}
