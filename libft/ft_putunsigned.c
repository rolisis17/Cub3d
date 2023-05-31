/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:54:33 by dcella-d          #+#    #+#             */
/*   Updated: 2023/03/27 13:32:51 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned(unsigned int nbr)
{
	int				res;

	res = 0;
	if (nbr > 9)
		res += ft_putunsigned(nbr / 10);
	res += ft_putchar(nbr % 10 + 48);
	return (res);
}
