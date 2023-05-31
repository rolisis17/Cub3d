/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:54:33 by dcella-d          #+#    #+#             */
/*   Updated: 2023/03/27 13:32:41 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa(unsigned int nbr, char *base)
{
	int	res;

	res = 0;
	if (nbr > 15)
		res += ft_puthexa(nbr / 16, base);
	res += ft_putchar(base[nbr % 16]);
	return (res);
}
