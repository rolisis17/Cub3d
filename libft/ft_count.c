/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:44:01 by dcella-d          #+#    #+#             */
/*   Updated: 2023/03/27 13:12:06 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(const char *str, va_list args)
{
	int	f;
	int	count;

	f = -1;
	count = 0;
	while (str[++f])
	{
		if (str[f] == '%' && str[f])
			count += ft_flags(str[++f], args);
		else
			count += ft_putchar(str[f]);
	}
	return (count);
}
